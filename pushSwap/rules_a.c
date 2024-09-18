/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:27:20 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:29:37 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list **a_head)
{
	t_list	*first;
	t_list	*new_first;
	t_list	*third;

	if (*a_head == NULL)
		return ;
	ft_putstr_fd("sa\n", 1);
	first = *a_head;
	new_first = first->next;
	third = new_first->next;
	first->next = third;
	first->prev = new_first;
	new_first->next = first;
	new_first->prev = NULL;
	if (third != NULL)
		third->prev = first;
	*a_head = new_first;
}

void	pa(t_list **a_head, t_list **b_head)
{
	t_list	*b_first;
	t_list	*b_new_first;
	t_list	*a_first;

	if (*b_head == NULL)
		return ;
	ft_putstr_fd("pa\n", 1);
	b_first = *b_head;
	b_new_first = b_first->next;
	b_first->next = NULL;
	if (b_new_first != NULL)
		b_new_first->prev = NULL;
	*b_head = b_new_first;
	if (*a_head == NULL)
	{
		*a_head = init_node(b_first->data);
	}
	else
	{
		a_first = *a_head;
		a_first->prev = b_first;
		b_first->next = a_first;
		b_first->prev = NULL;
	}
	*a_head = b_first;
}

void	ra(t_list **a_head)
{
	t_list	*a_first;
	t_list	*a_second;
	t_list	*a_last;

	if (*a_head == NULL)
		return ;
	ft_putstr_fd("ra\n", 1);
	a_first = *a_head;
	a_last = *a_head;
	a_second = a_first->next;
	if (a_second == NULL)
		return ;
	while (a_last != NULL)
	{
		if (a_last->next == NULL)
			break ;
		a_last = a_last->next;
	}
	a_first->prev = a_last;
	a_first->next = NULL;
	a_second->prev = NULL;
	a_last->next = a_first;
	*a_head = a_second;
}

void	rra(t_list **a_head)
{
	t_list	*a_last;
	t_list	*a_new_last;
	t_list	*a_new_fast;

	if (*a_head == NULL)
		return ;
	ft_putstr_fd("rra\n", 1);
	a_new_fast = *a_head;
	a_last = *a_head;
	while (a_last != NULL)
	{
		if (a_last->next == NULL)
			break ;
		a_last = a_last->next;
	}
	a_new_last = a_last->prev;
	if (a_new_last == NULL)
		return ;
	a_new_last->next = NULL;
	a_last->prev = NULL;
	a_last->next = a_new_fast;
	a_new_fast->prev = a_last;
	*a_head = a_last;
}
