/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/03 02:28:24 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_i = 0;

char	*ft_realloc(char *str)
{
	char	*new;
	int		i;

	i = -1;
	new = ft_calloc(sizeof(char), BUFFER_SIZE * 2);
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

void	create_char(char *str, int *i, char *bit, int *count)
{
	str[(*i)++] = *bit;
	*count += 1;
	*bit = 0;
}

void	display_str(char **str, int *i, int *count)
{
	write(1, *str, *i);
	*i = 0;
	*count = 0;
	free(*str);
	*str = NULL;
}

void	my_handler(int signum)
{
	static int	count;
	static int	shift = -1;
	static char	bit;
	static char	*str;

	if (!str)
		str = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!str)
		exit(1);
	if (shift < 0 && !bit)
		shift = 7;
	if (signum == SIGUSR2)
		bit = bit | (1 << shift);
	shift--;
	if (shift < 0 && bit)
		create_char(str, &g_i, &bit, &count);
	else if (shift < 0 && !bit)
		display_str(&str, &g_i, &count);
	if (count == BUFFER_SIZE)
		str = ft_realloc(str);
}

int	main(void)
{
	ascii_start(getpid());
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
		sleep(1);
}
