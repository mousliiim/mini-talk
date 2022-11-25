/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/25 02:06:44 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/printf/ft_printf.h"

static void	sigHandler_sigusr1(int sig)
{
	(void)sig;
    ft_printf("Caught SIGUSR1, %d\n", getpid());
}

int	main(void)
{
	ft_printf("Hello %s\n", getlogin());
	ft_printf("You'r Server Processus ID IS : %d\n", getpid());
	signal(SIGUSR1, sigHandler_sigusr1);
	
	while (1)
	{
		sleep(1);
	}
	signal(SIGUSR1, sigHandler_sigusr1);
}