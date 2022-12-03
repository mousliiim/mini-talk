/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:13 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/03 02:31:40 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(unsigned char c, int pid)
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

void	read_msg(char *msg, int pid)
{
	int	i;

	i = -1;
	while (msg[++i])
		char_to_binary(msg[i], pid);
	char_to_binary(0, pid);
}

void	sendsig(int sigusr)
{
	static int	sending;

	if (sigusr == SIGUSR1)
	{
		ft_printf("%s%d Signal envoyez ..%s\n", GREEN, ++sending, END);
		exit(EXIT_SUCCESS);
	}
	if (sigusr == SIGUSR2)
		++sending;
}

int	main(int argc, char **argv)
{
	__pid_t				pid;

	if (argc < 3)
		return (ft_printf("./client [Processus ID] [Your Message]\n"));
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (ft_printf("\n%sYour PID cannot be negative !%s\n\n", RED, END));
	if (argc == 3)
		read_msg(argv[2], pid);
}
