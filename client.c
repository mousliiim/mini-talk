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
#include "libft/printf/ft_printf.h"

void	ft_char(char c)
{
	write(1, &c, 1);
}

void	char_to_binary(unsigned char c)
{
	int	i;

	i = 7;
	while (i--)
	{
		if (c & (1 << i))
			ft_char('1');
		else
			ft_char('0');
	}
}

/*int	*read_msg(char *msg)
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
}*/

/*int	main(int argc, char const *argv[])
{
	__pid_t	pid;
	int		i;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc < 3)
		return (ft_printf("./client [PID] [Message]\n"));
	else
		kill(pid, SIGUSR2);
}*/

int	main(void)
{
	int	i;
	char	q;
	char *msg;

	msg = "mouslim";
	q = 'm';
	i = -1;
	while (msg[++i])
		char_to_binary(msg[i]);
}
