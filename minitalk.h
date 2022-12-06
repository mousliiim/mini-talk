/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:19:06 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/06 01:20:26 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include "libft/printf/ft_printf.h"
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define END "\033[0m"

void	ascii_start(int pid);

#endif