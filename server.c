/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/01 21:31:14 by mmourdal         ###   ########.fr       */
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

void my_handler(int signum)
{
    if (signum == SIGUSR1)
        ft_printf("0");
	else if(signum == SIGUSR2)
		ft_printf("1");
}

// void	binary_to_char(unsigned char c, int pid)
// {
// 	int	bit;

// 	bit = 8;
// 	while (bit--)
// 	{
// 		if (c & (1 << bit))
// 			kill(pid, SIGUSR2);
// 		else
// 			kill(pid, SIGUSR1);
// 	}
// }

int	main(void)
{
	ascii_start(getpid());
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
		sleep(1);
}
