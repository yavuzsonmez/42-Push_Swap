/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:45:56 by ysonmez           #+#    #+#             */
/*   Updated: 2021/06/23 10:28:33 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	size_t	sign;
	size_t	i;
	int		result;

	sign = 0;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign++;
		i++;
	}
	while (str[i] == 48)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + ((str[i] - 48) % 10);
		i++;
	}
	if (sign % 2 == 1)
		return (result * (-1));
	return (result);
}
