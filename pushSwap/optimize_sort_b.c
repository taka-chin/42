/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:25:13 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:25:15 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	two_element_sort_b(t_list **head)
{
	unsigned int	num1;
	unsigned int	num2;
	t_list			*node;

	node = *head;
	num1 = node->data;
	num2 = node->next->data;
	if (num1 < num2)
		sb(head);
}
