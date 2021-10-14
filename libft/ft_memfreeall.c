/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfreeall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:56:02 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/13 19:43:06 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memfreeall(void **ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return ;
	while (ptr[i] != NULL)
	{
		ft_memfree(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}
