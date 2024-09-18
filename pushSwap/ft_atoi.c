/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:26:42 by tyamauch          #+#    #+#             */
/*   Updated: 2023/05/07 15:33:09 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_put_error_atoi(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

static int	over_flow_check(int num, int check, const char *s)
{
	int	ov_div;
	int	ov_mod;

	ov_div = INT_MAX / 10;
	ov_mod = INT_MAX % 10;
	if (check == -1)
		ov_mod += 1;
	if (num > ov_div)
		return (1);
	else if (num == ov_div && ov_mod < (*s - '0'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	check;
	int	num;

	if (*str == '\0')
		ft_put_error_atoi();
	num = 0;
	check = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			check = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (over_flow_check(num, check, str) && check == 1)
			ft_put_error_atoi();
		if (over_flow_check(num, check, str) && check == -1)
			ft_put_error_atoi();
		num = num * 10 + (*str - '0');
		str++;
	}
	num *= check;
	return (num);
}
