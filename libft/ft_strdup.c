/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:51:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/13 18:58:49 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ss;
	int		len;

	i = 0;
	len = ft_strlen(s) + 1;
	ss = (char *)malloc(sizeof(char) * len);
	if (ss == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
