/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:41:45 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/09 23:39:44 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * La fonction substr renvoie une sous-chaîne indiqué d'une chaîne de caractères.
 * Premier Parametre : Chaine à partir de laquelle extraire la sous-chaîne.
 * Deuxieme Parametre : Position de départ des caractères de la sous-chaîne.
 * Troisieme Parametre : Nombre de caractères dans la sous-chaîne.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			s_size;
	char			*str;

	if (!s || start >= ft_strlen((char *)s))
		return (str = ft_calloc(1, 1));
	s_size = ft_strlen((char *)s);
	if (start + len > s_size)
		len = s_size - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int	main(void)
{
	char	*ft;

	printf("\n************** FT_SUBSTR *************\n");
	ft = ft_substr("tripouille", 1, 1);
	printf("Test de la fonction :\n");
	printf("ft_substr(\"Mouslim de 42\", 11, 10) : %s\n", ft);
	printf("**************************************\n\n");
}
*/