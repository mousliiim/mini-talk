/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:57:15 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:27:04 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>
//#include <stdio.h>

/*
 * La fonction concatène les chaîne *dst et *src, et place le résultat dans la 
 * chaîne *dst. Contrairement à la fonction strcat la longueur totale de la 
 * chaîne sera comprise entre la longueur initiale de *dst et size. Le '\0' de
 * fin de chaîne est compatibilisé.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (dst[i] && i < size)
	{
		i++;
	}
	j = 0;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*
int	main(void)
{
	// Compiler avec Flag -lbsd
	printf("\n****** TEST FT_STRLCAT ******\n");
	char dst[30] = "";
    char src[] = "123";
	char dst2[30] = "";
	char src2[] = "123";
    size_t result = ft_strlcat(dst, src, sizeof(dst));
	printf("Src array before : \"%s\" | Dst array before : \"%s\"\n", src2, dst2);
    printf("After ft_strlcat : %s | Function Return : %zu\n", dst, result);
	printf("Print dst array after ft_strlcat : %s\n\n", dst);
	printf("****** TEST STRLCAT ******\n");
	printf("Src2 array before : \"%s\" | Dst2 array before : \"%s\"\n", src2, dst2);
	size_t result2 = strlcat(dst2, src2, sizeof(dst2));
	printf("After strlcat : %s | Function Return : %zu\n", dst2, result2);
	printf("Print dst2 array after strlcat : %s\n\n", dst2);
}*/
