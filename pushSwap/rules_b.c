/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:27:26 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:30:05 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sb(t_list **b_head)
{
	t_list	*first;
	t_list	*new_first;
	t_list	*third;

	if (*b_head == NULL)
		return ;
	ft_putstr_fd("sb\n", 1);
	first = *b_head;
	new_first = first->next;
	third = new_first->next;
	first->next = third;
	first->prev = new_first;
	new_first->next = first;
	new_first->prev = NULL;
	if (third != NULL)
		third->prev = first;
	*b_head = new_first;
}

void	pb(t_list **a_head, t_list **b_head)
{
	t_list	*a_first;
	t_list	*a_new_first;
	t_list	*b_first;

	if (*a_head == NULL)
		return ;
	ft_putstr_fd("pb\n", 1);
	a_first = *a_head;
	a_new_first = a_first->next;
	a_first->next = NULL;
	if (a_new_first != NULL)
		a_new_first->prev = NULL;
	*a_head = a_new_first;
	if (*b_head == NULL)
	{
		*b_head = init_node(a_first->data);
	}
	else
	{
		b_first = *b_head;
		b_first->prev = a_first;
		a_first->next = b_first;
		a_first->prev = NULL;
	}
	*b_head = a_first;
}

void	rb(t_list **b_head)
{
	t_list	*b_first;
	t_list	*b_second;
	t_list	*b_last;

	if (*b_head == NULL)
		return ;
	ft_putstr_fd("rb\n", 1);
	b_first = *b_head;
	b_last = *b_head;
	b_second = b_first->next;
	if (b_second == NULL)
		return ;
	while (b_last != NULL)
	{
		if (b_last->next == NULL)
			break ;
		b_last = b_last->next;
	}
	b_first->prev = b_last;
	b_first->next = NULL;
	b_second->prev = NULL;
	b_last->next = b_first;
	*b_head = b_second;
}

void	rrb(t_list **b_head)
{
	t_list	*b_last;
	t_list	*b_new_last;
	t_list	*b_new_fast;

	if (*b_head == NULL)
		return ;
	ft_putstr_fd("rrb\n", 1);
	b_new_fast = *b_head;
	b_last = *b_head;
	while (b_last != NULL)
	{
		if (b_last->next == NULL)
			break ;
		b_last = b_last->next;
	}
	b_new_last = b_last->prev;
	if (b_new_last == NULL)
		return ;
	b_new_last->next = NULL;
	b_last->prev = NULL;
	b_last->next = b_new_fast;
	b_new_fast->prev = b_last;
	*b_head = b_last;
}
