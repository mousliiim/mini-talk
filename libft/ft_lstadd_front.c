/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:02:50 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/12 19:03:55 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ajoute l’élément ’new’ au début de la liste.
lst: L’adresse du pointeur vers le premier élément
de la liste.
new: L’adresse du pointeur vers l’élément à
rajouter à la liste.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	*malist;

	malist = ft_lstnew("First");
	printf("Premier Element de la Liste : %s\n", (char *)malist->content);
	t_lstadd_front(&malist, ft_lstnew("Second"));
	printf("Premier Element de la liste actuel : %s\n", (char *)malist->content);
}
*/