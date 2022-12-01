/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:13 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/01 21:28:21 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	ft_char(char c)
{
	write(1, &c, 1);
}

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
		usleep(400);
	}
}

void	read_msg(char *msg, int pid)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(msg);
	while (i < len)
	{
		char_to_binary(msg[i], pid);
		i++;
	}
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

int	main(int argc, char *argv[])
{
	__pid_t				pid;

	pid = ft_atoi(argv[1]);
	if (argc < 3)
		return (ft_printf("./client [PID] [Message]\n"));
	else if (pid < 0)
		return (ft_printf("PID NEGATIF"));
	else
		read_msg(argv[2], pid);
}

// int	main(void)
// {
// 	int	i;
// 	char	q;
// 	char *msg;

// 	msg = "mouslim";
// 	q = 'm';
// 	i = -1;
// 	while (msg[++i])
// 		char_to_binary(msg[i]);
// }
