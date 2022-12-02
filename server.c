/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/02 18:23:53 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_i = 0;

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

char	*ft_realloc(char *str)
{
	char	*new;
	size_t	i;

	i = -1;
	new = ft_calloc(sizeof(char), BUFFER_SIZE * 2 + g_i);
	if (!new)
	{
		free(str);
		exit(1);
	}
	while (str[++i])
		new[i] = str[i];
	free(str);
	return (new);
}

void my_handler(int signum)
{
	static int	count;
	static int	shift = -1;
	static char	bit;
	static char	*str;

	if (!str)
		str = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (shift < 0 && !bit)
		shift = 7;
	if (signum == SIGUSR2)
		bit = bit | (1 << shift);
	shift--;
	if (count == BUFFER_SIZE)
	{
		str = ft_realloc(str);
		count = 0;
	}
	if (shift < 0 && bit)
	{
		str[g_i] = bit;
		bit = 0;
		g_i++;
		count++;
	}
	else if (shift < 0 && !bit)
	{
		write(1, str, g_i);
		g_i = 0;
		count = 0;
		free(str);
		str = NULL;
	}
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
