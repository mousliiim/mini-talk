/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:28:02 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:26:29 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

/*
 * Ecrit le caractère du premier parametre 'c' sur le file descriptor donné
 * en deuxieme paramétre.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main(void)
{
	int	fd;

	printf("\n******** FT_PUTCHAR_FD ********\n'test':\n");
	ft_putchar_fd('t', 1);
	ft_putchar_fd('e', 1);
	ft_putchar_fd('s', 1);
	ft_putchar_fd('t', 1);
	printf("\n******** Test ecriture dans un fichier 'testfile' ********");
	printf("\nEcriture du caractère : b\n");
	fd = open("testfile", O_WRONLY | O_CREAT, 0777);
	ft_putchar_fd('b', fd);
	close(fd);
	printf("\nCaractère ecrit dans le fichier 'testfile' : ");
	system("sed -i '1s/^/echo /' testfile");
	printf("\n");
	system("./testfile");
}
*/
