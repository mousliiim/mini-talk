/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:13 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/25 01:45:45 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/printf/ft_printf.h"

int	main(int argc, char const *argv[])
{
	__pid_t	pid;
	int		i;

	i = 0;
	pid = ft_atoi(argv[1]);

	if (argc < 3)
		return (ft_printf("./client [PID] [Message]\n"));
	else
		kill(pid, SIGUSR1);
}