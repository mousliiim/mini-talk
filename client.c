/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:13 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/08 00:27:41 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit;

/*
* Ce code en C représente un petit programme client qui envoie des messages à 
* un autre processus. La fonction "char_to_binary" convertit chaque caractère 
* du message en signal binaire et le "read_msg" fonctionne en boucle pour
* envoyer chaque caractère à l'autre processus. La fonction "main" vérifie que
* le nombre d'arguments est suffisant et convertit le premier argument 
* (l'ID du processus) en un entier. Enfin, si le nombre d'arguments est égal
* à 3 et que les conditions sont respecter, le programme lit le message et 
* l'envoie au processus. 
*/

/*
* La variable global g_bit sert à contrôler le processus de transmission
* de données entre le client et le server. Une fois qu'une donnée a été 
* transmise le server met le g_bit à 1 et le client peut alors envoyer le
* prochain octet.
*/

static void	char_to_binary(unsigned char c, int pid)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		g_bit = 0;
		if (kill(pid, 0) < 0)
		{
			ft_printf("\n%sError : This PID its not a SERVER !%s\n\n",
				RED, END);
			exit(1);
		}
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_bit != 1)
			usleep(10);
	}
}

static void	sigclient(int signum)
{
	if (signum == SIGUSR2)
		g_bit = 1;
	else if (signum == SIGUSR1)
	{
		ft_printf("\n%sServer receive correctly your message !%s\n\n", GREEN, END);
		exit(0);
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
		return (ft_printf("%s\n./client [Processus ID] [Your Message]%s\n\n",
				GREEN, END));
	signal(SIGUSR1, &sigclient);
	signal(SIGUSR2, &sigclient);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (ft_printf("\n%sYour PID cannot be negative !%s\n\n", RED, END));
	else if (!ft_isdigit(argv[1][0]))
		return (ft_printf("\n%sYour PID cannot be a char !%s\n\n", RED, END));
	else if (pid == 0)
		return (ft_printf("\n%sYour PID cannot be 0 !%s\n\n", RED, END));
	else if (pid > 4194304)
		return (ft_printf("\n%sThe PID limit value is 4194304%s\n\n", RED, END));
	else if (ft_strlen(argv[2]) == 0)
		return (ft_printf("\n%sMessage can't be empty !%s\n\n", RED, END));
	else if (argc == 3)
		read_msg(argv[2], pid);
	while (1)
		sleep(1);
}
