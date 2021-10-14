/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:40:11 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/13 15:29:37 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	count;
	char	*ss;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		count = 0;
	else if (ft_strlen(s + start) >= len)
		count = len;
	else
		count = ft_strlen(s + start);
	ss = (char *)malloc(sizeof(char) * (count + 1));
	if (ss == NULL)
		return (NULL);
	while (i < count)
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
