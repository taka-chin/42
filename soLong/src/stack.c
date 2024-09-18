/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:37:36 by tyamauch          #+#    #+#             */
/*   Updated: 2023/08/01 21:35:05 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->point = NULL;
}

void free_stack(t_stack *stack)
{
	while(stack->size != 0 )
	{
		free(stack->point);
		stack->size -=1;
	}
}

void	push_stack(t_stack *stack, int i, int j)
{
	t_point	*tmp;

	tmp = (t_point *)malloc(sizeof(t_point) * 1);
	printf("leak is ?:%p\n",tmp);
	if (tmp == NULL)
		exit(1);
	tmp->x = i;
	tmp->y = j;
	tmp->prev = stack->point;
	stack->point = tmp;
	stack->size += 1;
}

t_point	*pop_stack(t_stack *stack)
{
	t_point	*point;

	point = stack->point;
	stack->point = point->prev;
	stack->size -= 1;
	return (point);
}
