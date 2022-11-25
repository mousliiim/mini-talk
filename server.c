/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/25 19:08:57 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/printf/ft_printf.h"

void	sighandler(int signalreceive)
{
	if (signalreceive == SIGUSR1)
		ft_printf("Signal SIGUSR1\n");
	else if (signalreceive == SIGUSR2)
		ft_printf("Signal SIGUSR2\n");
	else
		ft_printf("Error\n");
}

int	main(void)
{
	ft_printf("Hello %s\n", getlogin());
	ft_printf("You'r Server Processus ID IS : %d\n", getpid());
	if (signal(SIGUSR1, sighandler) == SIG_ERR)
	{
		ft_printf("Error !\n");
		exit(1);
	}
	if (signal(SIGUSR2, sighandler) == SIG_ERR)
	{
		ft_printf("Error !\n");
		exit(1);
	}
	while (1)
	{
		sleep(1);
	}
}