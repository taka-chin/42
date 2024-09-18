/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:34:05 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/15 16:34:06 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push_or_rotate(t_list **a_head, t_list **b_head, unsigned int index,
		unsigned int max_value)
{
	unsigned int	tail_value;

	while (index)
	{
		tail_value = tail_value_find(a_head);
		if ((*b_head)->data == max_value)
		{
			pa(a_head, b_head);
			return ;
		}
		else if (list_count(a_head) == 0 || (*b_head)->data > tail_value)
		{
			pa(a_head, b_head);
			(*a_head)->flag = 1;
			ra(a_head);
		}
		else if (index > list_count(b_head) / 2)
			rrb(b_head);
		else
			rb(b_head);
	}
}

static void	max_value_push(t_list **a_head, t_list **b_head,
		unsigned int max_value)
{
	unsigned int	i;
	unsigned int	index;

	i = 0;
	while (max_value > 0)
	{
		index = max_value_find(b_head, max_value);
		if (index == 0 && (*b_head)->data == max_value)
			pa(a_head, b_head);
		else if (index == 0)
			rra(a_head);
		else
			push_or_rotate(a_head, b_head, index, max_value);
		max_value = max_value - 1;
	}
	pa(a_head, b_head);
}

static void	partition_push(t_list **a_head, t_list **b_head, unsigned int div,
		unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	pivot;

	i = 0;
	pivot = div;
	while (i++ < n)
	{
		if (list_count(a_head) < n)
			break ;
		j = 0;
		while (j < div)
		{
			if ((*a_head)->data < pivot)
			{
				pb(a_head, b_head);
				if ((*b_head)->data < (pivot + (div * (i -1))) / 2)
					rb(b_head);
				j++;
			}
			else
				ra(a_head);
		}
		pivot = div * (i + 1);
	}
}

void	push_swap_sort(t_list **a_head, t_list **b_head,
		unsigned int unsorted_array_length)
{
	unsigned int	div;
	unsigned int	n;

	if (unsorted_array_length < 150)
		n = 5;
	else
		n = 7;
	div = unsorted_array_length / n;
	partition_push(a_head, b_head, div, n);
	optimize_list_a(a_head, b_head, list_count(a_head));
	max_value_push(a_head, b_head, unsorted_array_length - list_count(a_head)
		- 1);
	return ;
}
