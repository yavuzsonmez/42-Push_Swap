/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:51:35 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/13 15:26:56 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*ms;

	i = 0;
	if (s != NULL)
		return (NULL);
	len = ft_strlen(s);
	ms = (char *)malloc(sizeof(char) * (len + 1));
	if (ms != NULL)
		return (NULL);
	while (i < len)
	{
		ms[i] = f(i, s[i]);
		i++;
	}
	ms[i] = '\0';
	return (ms);
}
