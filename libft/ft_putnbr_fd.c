/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:05:04 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/25 22:33:45 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n %= 10;
		c = n + '0';
		ft_putchar_fd(c, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

/* int main(void) */
/* { */
/* printf("%s",ft_putnbr_fd(-2147483648,1)); */
/* ft_putnbr_fd(-2147483648,1); */
/* ft_putnbr_fd(-2147483648,1); */
/* ft_putnbr_fd(-2147483647,1); */
/* } */
