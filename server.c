/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/04 01:41:56 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_i = 0;

// La fonction ft_realloc() est utilisée pour augmenter la taille de la chaîne
// de caractères lorsqu'elle est pleine, elle seras appeller a chaque fois que
// la variable count qui sert a compter le nombre de char creer seras egale a
// notre BUFFER_SIZE qui est de 10. 
static char	*ft_realloc(char *str)
{
	char	*new;
	int		i;

	i = -1;
	new = ft_calloc(sizeof(char), BUFFER_SIZE * 2);
	if (!new)
	{
		free(str);
		exit(1);
	}
	while (str[++i])
		new[i] = str[i];
	free(str);
	return (new);
}

// La fonction create_char() est utilisée pour créer un caractère à partir des 
// bits reçus dans le signal et l'ajouter à la chaîne str.
static void	create_char(char *str, int *i, char *bit, int *count)
{
	str[(*i)++] = *bit;
	*count += 1;
	*bit = 0;
}

// La fonction display_str() sert a afficher la chaîne et la réinitialiser.
// Des que la chaine est afficher nous pouvons free la chaine et remettre a 0
// Notre compteur pour le tampon BUFFER_SIZE et notre variable global g_i.
static void	display_str(char **str, int *i, int *count)
{
	write(1, *str, *i);
	*i = 0;
	*count = 0;
	*str = NULL;
	free(*str);
}

// La fonction my_handler est appelée chaque fois que le programme reçoit un
// signal SIGUSR1 | SIGUSR2.Elle stocke les signaux dans la chaîne de caractères
// en faisant correspondre les bits reçus aux caractères ASCII correspondants.
// Ont vas utiliser la meme logique de bits que sur notre client pour recreer
// notre octet dans notre Char Bit.
static void	my_handler(int signum)
{
	static int	count;
	static int	shift = -1;
	static char	bit;
	static char	*str;

	if (!str)
		str = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!str)
		exit(1);
	if (shift < 0 && !bit)
		shift = 7;
	if (signum == SIGUSR2)
	{
		bit = bit | (1 << shift);
		ft_printf("%c", bit);
	}
	shift--;
	if (shift < 0 && bit)
		create_char(str, &g_i, &bit, &count);
	else if (shift < 0 && !bit)
		display_str(&str, &g_i, &count);
	if (count == BUFFER_SIZE)
		str = ft_realloc(str);
}

int	main(void)
{
	ascii_start(getpid());
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
		sleep(1);
}