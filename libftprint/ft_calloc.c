/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:34:56 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:25:43 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SIZE_MAX	(18446744073709551615UL)

/*
 * La fonction calloc() a le même rôle que malloc().
 * Elle permet d'allouer de la mémoire.
 * La différence entre les fonctions calloc() et malloc(), 
 * c'est que calloc() initialise à 0 tous les éléments de la zone mémoire.
 * Le premier argument est le nombre d'éléments
 * qu'on souhaite pouvoir stocker en mémoire
 * et le deuxième est la taille de ces éléments.
 * Nous aurions pu aussi utiliser notre fonction coder précedemment ft_memset.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	i;

	if (nmemb && size == SIZE_MAX)
		return (NULL);
	i = 0;
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (0);
	while (i < nmemb * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

/*
int	main(int argc, char **argv)
{
	(void) argc;
	printf("%p", ft_calloc(atoi(argv[1]), atoi(argv[2])));
	// Retour de valgrind ./a.out 2 25 = 50 bytes in 1 blocks
	return (0);
}
*/
