/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sort_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:23:15 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:23:17 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	two_element_sort_a(t_list **head)
{
	unsigned int	num1;
	unsigned int	num2;
	t_list			*node;

	node = *head;
	num1 = node->data;
	num2 = node->next->data;
	if (num1 > num2)
		sa(head);
}

void	three_element_sort_a(t_list **head)
{
	unsigned int	num1;
	unsigned int	num2;
	unsigned int	num3;
	t_list			*node;

	node = *head;
	num1 = node->data;
	num2 = node->next->data;
	num3 = node->next->next->data;
	if (num1 > num2 && num2 < num3 && num1 < num3)
		sa(head);
	else if (num1 > num2 && num2 > num3 && num1 > num3)
	{
		sa(head);
		rra(head);
	}
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		ra(head);
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa(head);
		ra(head);
	}
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		rra(head);
}

void	four_element_sort_a(t_list **a_head, t_list **b_head,
		unsigned int array_length)
{
	unsigned int	i;
	unsigned int	min;

	i = 0;
	if (list_count(b_head))
		array_length = list_count(a_head) + list_count(b_head);
	min = array_length - list_count(a_head);
	while (i < list_count(a_head))
	{
		if ((*a_head)->data == min)
		{
			pb(a_head, b_head);
			break ;
		}
		else
			ra(a_head);
		i++;
	}
	three_element_sort_a(a_head);
	pa(a_head, b_head);
}

void	five_element_sort_a(t_list **a_head, t_list **b_head,
		unsigned int array_length)
{
	unsigned int	i;
	unsigned int	min;
	unsigned int	max;
	unsigned int	len;

	i = 0;
	len = list_count(a_head);
	if (list_count(b_head))
		array_length = list_count(a_head) + list_count(b_head);
	min = array_length - list_count(a_head);
	max = array_length - 1;
	while (i < len)
	{
		if ((*a_head)->data == min)
			pb(a_head, b_head);
		else if ((*a_head)->data == min + 1)
			pb(a_head, b_head);
		else
			ra(a_head);
		i++;
	}
	three_element_sort_a(a_head);
	two_element_sort_b(b_head);
	pa(a_head, b_head);
	pa(a_head, b_head);
}

void	six_element_sort_a(t_list **a_head, t_list **b_head,
		unsigned int array_length)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	min;

	i = 0;
	len = list_count(a_head);
	if (list_count(b_head))
		array_length = list_count(a_head) + list_count(b_head);
	min = array_length - list_count(a_head);
	while (i < len)
	{
		if ((*a_head)->data == min)
			pb(a_head, b_head);
		else if ((*a_head)->data == min + 1)
			pb(a_head, b_head);
		else
			ra(a_head);
		i++;
	}
	four_element_sort_a(a_head, b_head, list_count(a_head));
	two_element_sort_b(b_head);
	pa(a_head, b_head);
	pa(a_head, b_head);
}
