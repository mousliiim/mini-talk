/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/28 19:38:23 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ascii_start(int pid)
{
	(void)pid;
	ft_printf("\n\n");
	ft_printf("%s\t███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░██╗\n",
		RED);
	ft_printf("\t████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	ft_printf("\t██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n");
	ft_printf("\t██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	ft_printf("\t██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
	ft_printf("\t╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝%s",
		END);
	ft_printf("\n\n\n");
	ft_printf("\t\t   ●▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬๑۩۩๑▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬●\n");
	ft_printf("\t\t       PID : %s%d%s\tBy MMOURDAL\n", GREEN, pid, END);
	ft_printf("\t\t   ●▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬๑۩۩๑▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬●\n\n\n");
}

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
	ascii_start(getpid());
	if (signal(SIGUSR1, sighandler) == SIG_ERR)
	{
		ft_printf("Error ! USR2\n");
		exit(1);
	}
	if (signal(SIGUSR2, sighandler) == SIG_ERR)
	{
		ft_printf("Error ! USR2\n");
		exit(1);
	}
	while (1)
		sleep(1);
}
