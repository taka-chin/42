/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:31:16 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/15 16:31:18 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

unsigned int	max_value_find(t_list **list, unsigned int max_value)
{
	int				index;
	unsigned int	flag;
	t_list			*node;

	index = 1;
	flag = 0;
	node = *list;
	while (node)
	{
		if (node->data == max_value)
		{
			flag = 1;
			break ;
		}
		node = node->next;
		index++;
	}
	if (flag)
		return (index);
	else
		return (0);
}

unsigned int	tail_value_find(t_list **list)
{
	int		tail_value;
	t_list	*node;
	t_list	*tail;

	if (list_count(list) == 0)
	{
		return (0);
	}
	node = *list;
	while (node)
	{
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	tail = node;
	if (tail->flag)
		tail_value = tail->data;
	else
		tail_value = 0;
	return (tail_value);
}
