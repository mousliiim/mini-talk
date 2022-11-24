/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:33:32 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:26:01 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * La fonction memchr() examine les n premiers octets de la zone mémoire pointée
 * par s à la recherche du caractère c. Le premier octet correspondant à c 
 * (interprété comme un unsigned char) arrête l'opération.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		tofind;
	size_t				i;

	i = 0;
	tofind = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == tofind)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	if(argc == 2)
	{
	void	*found;
	char	*string;

	string = "azerty";
	printf("**** Test avec ft_memchr : ****\n");
	printf("Chaine de Charactere de Test : %s\n", string);

	found = ft_memchr(string, *((int *)argv[1]), 6);
	printf("Charactere '%s' (Ascii : %i) : %s\n", argv[1],
		*((char *)argv[1]), (found != NULL ? "Bien présent" : "Non présent"));
	found = ft_memchr(string, 109, 6);
	printf("Charactere 'm' (Ascii : 109) : %s\n",
		(found != NULL ? "Bien présent" : "Non présent"));
	}
	else
		printf("Oops le test ne peu pas fonctionner sans les arguments..\n");
	return (0);
}*/
