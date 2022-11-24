/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:17:23 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/12 19:29:08 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * La fonction split découpe une chaine de caractère (*s) suivant un délimiteur
 * donner en parametre (c), elle retourne un tableau de chaines de caractères
 * alloué dynamiquement et qui termine par un '\0'.
*/

static char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		word++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (word);
}

static int	count_len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	while (*s && *s == c)
		s++;
	return (i);
}

static char	**ft_free(char **str, int i)
{
	while (--i >= 0)
		free(str[i]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		word_len;
	int		word;

	word = count_word(s, c);
	strs = (char **)malloc(sizeof(char *) * (word + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < word && *s)
	{
		while (*s == c)
			s++;
		word_len = count_len_word(s, c);
		strs[i] = ft_strndup(s, word_len);
		if (!strs[i])
			return (ft_free(strs, i));
		s += word_len;
		i++;
	}
	strs[word] = 0;
	return (strs);
}

/*
int	main(void)
{
	char	**result;
	int		i;
	printf("\n************ FT_SPLIT ***********\n");
	printf("Separateur : '-' | Chaine : \"Salut----Les----Terriens----\" : \n");
	result = ft_split("Salut----Les----Terriens----", '-');
	i = -1;
	while (result[++i])
		printf("Index : %d => %s\n", i, result[i]);
	printf("\nSeparateur : '/' | Chaine : \"4242 1///42!!42 2//42 3\" : \n");
	result = ft_split("4242 1///42!!42 2//42 3", '/');
	i = -1;
	while (result[++i])
		printf("Index : %d => %s\n", i, result[i]);
	printf("*********************************\n\n");
}
*/
