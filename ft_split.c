/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:40:31 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/10 10:39:32 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_count_number_of_word(char *str, int *h, char c)
{
	int		size;
	int		i;
	char	**table;

	size = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	*h = size;
	table = (char **)malloc(sizeof(char *) * (size + 1));
	if (!table)
		return (NULL);
	return (table);
}

char	**ft_count_char_of_word(char *str, char c, int *f, char **table)
{
	int		n;
	int		i;
	int		h;

	h = 0;
	i = 0;
	while (*str && h < *f)
	{
		n = 0;
		while (*str && *str == c)
			str++;
		while (*str && *str != c)
		{
			str++;
			n++;
		}
		table[h] = (char *)malloc(sizeof(char) * (n + 1));
		if (!table)
			return (NULL);
		h++;
	}
	return (table);
}

void	ft_stock_tab(char **table, int size_of_table, char *str, char c)
{
	int	i;
	int	j;
	int	m;

	m = 0;
	i = 0;
	while (i < size_of_table)
	{
		while (str[m] && str[m] == c)
			m++;
		j = 0;
		while (str[m] && str[m] != c)
		{
			table[i][j] = str[m];
			j++;
			m++;
		}
		table[i][j] = '\0';
		i++;
	}
	table[i] = 0;
}

char	**ft_split(char *str, char c)
{
	char	**table;
	int		l;

	if (str == NULL)
		return (NULL);
	l = 0;
	table = ft_count_number_of_word(str, &l, c);
	if (!table)
		return (NULL);
	table = ft_count_char_of_word(str, c, &l, table);
	if (!table)
		return (NULL);
	ft_stock_tab(table, l, str, c);
	return (table);
}
