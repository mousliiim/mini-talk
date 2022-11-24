/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:36:05 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 01:00:33 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * La fonction strrchr recherche la dernière occurrence du caractère passé en
 * second paramètre dans la chaîne de caractère spécifiée via le premier
 * parametre.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		else
			i--;
	}
	return (0);
}

/*
int	main(int argc, char **argv)
{
	(void) argc;
	printf("Ft_strrchr : %s\n", ft_strrchr(argv[1], atoi(argv[2])));
	printf("strrchr : %s\n", strrchr(argv[1], atoi(argv[2])));
	return (0);
}
*/
