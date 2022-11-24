/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:21:48 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:26:04 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cette fonction permet de comparer le contenu de deux blocs de mémoire
 * spécifiés par les deux premiers paramètres de la fonction. Le 
 * troisième paramètre, size, permet de spécifier le nombre d'octets sur lequel
 * comparer les deux blocs. Les octets des deux blocs sont comparés deux à deux.
 * Tant que les deux octets comparés sont égaux, la fonction passe aux deux 
 * suivants. 
 * Si les deux octets comparés sont différents, alors la fonction renvérra le-
 * quel des deux blocs est le plus petit en termes de contenu.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (n && *s1c == *s2c)
	{
		n--;
		s1c++;
		s2c++;
	}
	if (n == 0)
		return (0);
	else
		return (*s1c - *s2c);
	return (0);
}

/*int	main(int argc, char **argv)
{
	(void) argc;
	printf("%i", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
	printf("\n%i\n", memcmp(argv[1], argv[2], atoi(argv[3])));
}*/
