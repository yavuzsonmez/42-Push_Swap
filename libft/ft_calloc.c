/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:13:53 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/13 14:59:38 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	arr = malloc(size * nmemb);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, size * nmemb);
	return (arr);
}
