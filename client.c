/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:13 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/25 19:55:44 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>


void	ft_char(char c)
{
	write(1, &c, 1);
}

void	char_to_binary(unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		usleep(100);
	}
}

void	read_msg(char *msg)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(msg);
	while (i < len)
	{
		char_to_binary(msg[i]);
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
	{
		signal(SIGUSR1, sendsig);
		signal(SIGUSR2, sendsig);
	}
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
