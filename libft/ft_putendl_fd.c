/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:42:29 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:26:34 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Ecrit la string du parametre (*s) sur le file descriptor donné
 * en deuxieme paramétre suivi d'un retour a la ligne.
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

/*
int	main(void)
{
	printf("\n******** FT_PUTENDL_FD ********\n'test':\n");
	ft_putendl_fd("test", 1);
}
*/
