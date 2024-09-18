/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:20:58 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:21:00 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*make_nums(char *input[], size_t array_length)
{
	int		*num;
	size_t	i;

	i = 0;
	num = malloc(sizeof(int) * array_length);
	if (num == NULL)
		ft_put_error();
	i = 0;
	while (input[i] != NULL)
	{
		num[i] = ft_atoi(input[i]);
		i++;
	}
	return (num);
}
