/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:53:42 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/12 19:17:04 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ajoute l’élément ’new’ à la fin de la liste.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

/*
static void	display_lst(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		++i;
		printf("Contenu du noeud [%d] : %s\n", i, (char *)temp->content);
		temp = temp->next;
	}
}

int	main(void)
{
	t_list	*noeud1;
	t_list	*noeud2;
	t_list	*noeud3;
	t_list	*noeud4;

	noeud1 = ft_lstnew("First");
	noeud2 = ft_lstnew("Second");
	noeud3 = ft_lstnew("Third");
	noeud4 = ft_lstnew("Last");
	ft_lstadd_back(&noeud1, noeud2);
	ft_lstadd_back(&noeud1, noeud3);
	ft_lstadd_back(&noeud1, noeud4);
	printf("\n****** FT_LSTADD_BACK ******\n");
	display_lst(noeud1);
	printf("Nombre d'element de la liste : \" %d \"\n\n", ft_lstsize(noeud1));
}
*/