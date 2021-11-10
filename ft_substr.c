/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:02:08 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/09 21:17:56 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*buff;
	unsigned int	index;

	buff = (void *)0;
	if (s == NULL)
		return (NULL);
	index = ft_strlen(s);
	if (index == 0 || start >= index)
	{
		buff = (char *)ft_calloc(1, sizeof(char));
		*buff = '\0';
		return (buff);
	}
	index = 0;
	buff = (char *)ft_calloc(len + 1, sizeof(char));
	if (!buff)
		return (buff);
	while (s[index] && index < len)
	{
		buff[index] = s[start];
		start++;
		index++;
	}
	buff[index] = '\0';
	return (buff);
}
