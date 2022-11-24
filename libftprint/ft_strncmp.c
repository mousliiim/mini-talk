/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:35:48 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:27:33 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

/*
 * Cette fonction permet de comparer deux chaînes de caractères
 * et de savoir si la première (*s1) est
 * inférieure, égale ou supérieure à la seconde (*s2). 
 * Cette comparaison sera faite dans l'ordre ASCII
 * Néanmoins la comparaison se fera au maximum sur 
 * les n premiers caractères.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while ((s1[i] && s2[i]) && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	main(int argc, char **argv)
{
	(void) argc;
	printf("Ft_strncmp : %i\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	printf("Strncmp : %i\n", strncmp(argv[1], argv[2], atoi(argv[3])));
	return (0);
}*/
