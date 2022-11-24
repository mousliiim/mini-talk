/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:14:11 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/12 19:04:39 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Renvoie le dernier élément de la liste.
lst: Le début de la liste.
Return : Dernier élément de la liste
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
int	main(void)
{
	t_list	*noeud1;
	t_list	*noeud2;
	t_list	*noeud3;
	t_list *last;

	noeud1 = ft_lstnew("1");
	noeud2 = ft_lstnew("2");
	noeud3 = ft_lstnew("3");
	noeud1->next = noeud2;
	noeud2->next = noeud3;
	noeud3->next = ft_lstnew("Je suis le dernier");
	last = ft_lstlast(noeud1);
	printf("\n***** DISPLAY CONTENT LINKED LIST & SIZE OF LINKED LIST *****\n");
	printf("\n[1er noeud] Contenue de la Liste : \"%s\"\n",
		(char *)noeud1->content);
	printf("[2eme noeud] Contenue de la Liste : \"%s\"\n",
		(char *)noeud1->next->content);
	printf("[3eme noeud] Contenue de la Liste : \"%s\"\n",
		(char *)noeud2->next->content);
	printf("[Dernier noeud] Contenue de la Liste : \"%s\"\n",
		(char *)noeud3->next->content);
	printf("\nNombre d'element de la liste : \"%d\"\n\n", ft_lstsize(noeud1));
	printf("***** FT_LSTLAST *****\n");
	printf("\nDernier element de la liste : \"%s\"\n\n", (char *)last->content);
}
*/