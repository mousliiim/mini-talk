/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:05:14 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/12 19:03:12 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compte le nombre d’éléments de la liste.
Return : Taille de la liste donner en parametre.
*/

int	ft_lstsize(t_list *lst)
{
	int	result;

	result = 0;
	while (lst != NULL)
	{
			result++;
			lst = lst->next;
	}
	return (result);
}

/*
int	main(void)
{
	t_list	*noeud1;
	t_list	*noeud2;
	t_list	*noeud3;

	noeud1 = ft_lstnew("1");
	noeud2 = ft_lstnew("2");
	noeud3 = ft_lstnew("3");
	noeud1->next = noeud2;
	noeud2->next = noeud3;
	printf("\n[1er noeud] Contenue de la Liste : \"%s\"\n",
		(char *)noeud1->content);
	printf("[2eme noeud] Contenue de la Liste : \"%s\"\n",
		(char *)noeud1->next->content);
	printf("[3eme noeud] Contenue de la Liste : \"%s\"\n",
		(char *)noeud2->next->content);
	printf("\nNombre d'element de la liste : \"%d\"\n\n", ft_lstsize(noeud1));
}
*/
