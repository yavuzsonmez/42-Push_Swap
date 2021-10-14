/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:03:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/06/22 14:04:26 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;
	char			c;

	c = 0;
	if (n < 0)
	{
		number = n * (-1);
		write(fd, "-", 1);
	}
	else
		number = n;
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	c = (number % 10) + 48;
	write(fd, &c, 1);
}
