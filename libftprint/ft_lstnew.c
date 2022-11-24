/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:04:36 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/12 19:06:06 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Alloue (avec malloc(3)) et renvoie un nouvel
élément. La variable membre ’content’ est
initialisée à l’aide de la valeur du paramètre ’content’. 
La variable ’next’ est initialisée à NULL.
Return : Le nouvel element avec le content donner en parametre.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

/*
int	main(void)
{
	t_list	*noeux1;
	t_list	*noeux2;

	noeux1 = ft_lstnew("First Content");
	noeux2 = ft_lstnew("Second Content");
	noeux1->next = noeux2;
	printf("Noeud 1 : \"%s\"\n", (char *)(noeux1->content));
	printf("Noeud 1 --> Noeud 2 : \"%s\"\n", (char *)noeux1->next->content);
}
*/