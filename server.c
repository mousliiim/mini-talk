/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/08 00:27:09 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
* My_handler est une fonction qui est appelée par la fonction main lorsqu'un
* signal SIGUSR1 ou SIGUSR2 est reçu. La fonction fait une conversion bit à bit
* vers un caractère ASCII et l'affiche lorsque tous les bits ont été traités.
*/

void	my_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int	shift = -1;
	static char	bit;

	(void)context;
	if (shift < 0)
		shift = 7;
	if (signum == SIGUSR2)
		bit |= 1 << shift;
	else if (signum == SIGUSR1)
		bit &= ~(1 << shift);
	if (!shift && bit)
		ft_putchar_fd(bit, 1);
	else if (!shift && !bit)
		kill(siginfo->si_pid, SIGUSR1);
	shift--;
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = my_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	ascii_start(getpid());
	while (1)
		sleep(1);
}
