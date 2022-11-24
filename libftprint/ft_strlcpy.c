/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:35:17 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:27:07 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * La fonction strlcpy permet de copier une chaîne de caractères
 * dans une autre chaîne en limitant le nombre de caractères copiés
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
int	main(int argc, char **argv)
{
	printf("Ft_Strlcpy : %ld\n", ft_strlcpy(argv[1], argv[2], atoi(argv[3])));
	printf("Strlcpy : %ld\n", strlcpy(argv[1], argv[2], atoi(argv[3])));
	return (0);
}
*/
