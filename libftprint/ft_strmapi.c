/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 05:07:48 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:27:16 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * La fonction strmapi applique la fonction en paramétre de celle ci (*f) 
 * à chaque caractère de *s pour crée une nouvelle chaîne (avec malloc) 
 * résultant de l'applications successives de f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	min_to_maj(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int	main(int argc, char **argv)
{
	char	src[20];
	char	*dst;

	(void)argc;
	strcpy(src, argv[1]);
	dst = ft_strmapi(src, min_to_maj);
	printf("\n********************* FT_STRMAPI ***********************\n");
	printf("Test de la fonction avec une autre fonction min_to_maj : \n");
	printf("ft_strmapi(\"%s\", min_to_maj) : %s\n", argv[1], dst);
	printf("********************************************************\n\n");
	free(dst);
}*/
