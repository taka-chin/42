/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:20:07 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:20:08 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

unsigned int	list_count(t_list **list)
{
	unsigned int	list_count;
	t_list			*node;

	list_count = 0;
	node = *list;
	while (node)
	{
		list_count++;
		node = node->next;
	}
	return (list_count);
}

t_list	*init_node(unsigned int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list) * 1);
	if (node == NULL)
		ft_put_error();
	node->next = NULL;
	node->prev = NULL;
	node->data = value;
	node->flag = 0;
	return (node);
}

static void	add_back(t_list **head, t_list *new_node)
{
	t_list	*node;

	node = *head;
	while (node != NULL)
	{
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	if (node != NULL)
	{
		node->next = new_node;
		new_node->next = NULL;
		new_node->prev = node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
	}
}

t_list	*make_list(unsigned int *num_compress, t_list **head,
		size_t array_length)
{
	t_list	*new_node;
	size_t	i;

	i = 0;
	while (i < array_length)
	{
		new_node = init_node(num_compress[i]);
		add_back(head, new_node);
		i++;
	}
	return (new_node);
}
