/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:13 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/04 00:40:47 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
* Ce code en C représente un petit programme client qui envoie des messages à 
* un autre processus. La fonction "char_to_binary" convertit chaque caractère 
* du message en signal binaire et le "read_msg" fonctionne en boucle pour
* envoyer chaque caractère à l'autre processus. La fonction "main" vérifie que
* le nombre d'arguments est suffisant et convertit le premier argument 
* (l'ID du processus) en un entier. Enfin, si le nombre d'arguments est égal
* à 3, le programme lit le message et l'envoie au processus.
*/

// Nous considerons un bit actif '1' pour SIGUSR2 | Bit passif '0' pour SIGUSR1
static void	char_to_binary(unsigned char c, int pid)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(600);
	}
}

static void	read_msg(char *msg, int pid)
{
	int	i;

	i = -1;
	while (msg[++i])
		char_to_binary(msg[i], pid);
	char_to_binary(0, pid);
}

int	main(int argc, char **argv)
{
	__pid_t				pid;

	if (argc < 3)
		return (ft_printf("./client [Processus ID] [Your Message]\n"));
	pid = ft_atoi(argv[1]);
	if (pid < 0 || argv[1][0] < 0)
		return (ft_printf("\n%sYour PID cannot be negative !%s\n\n", RED, END));
	if (argc == 3)
		read_msg(argv[2], pid);
}