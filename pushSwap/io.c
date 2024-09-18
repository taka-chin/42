/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:12:20 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:12:22 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	optimize_list_a(t_list **a_head, t_list **b_head,
		unsigned int array_length)
{
	if (array_length == 2)
		two_element_sort_a(a_head);
	else if (array_length == 3)
		three_element_sort_a(a_head);
	else if (array_length == 4)
		four_element_sort_a(a_head, b_head, array_length);
	else if (array_length == 5)
		five_element_sort_a(a_head, b_head, array_length);
	else if (array_length == 6)
		six_element_sort_a(a_head, b_head, array_length);
}

void	sort_list(unsigned int *num_compress, unsigned int array_length)
{
	t_list	*a_head;
	t_list	*b_head;

	a_head = NULL;
	b_head = NULL;
	make_list(num_compress, &a_head, array_length);
	if (array_length < 7)
		optimize_list_a(&a_head, &b_head, array_length);
	else
		push_swap_sort(&a_head, &b_head, array_length);
}

int	main(int argc, char *argv[])
{
	size_t			array_length;
	char			**input;
	int				*num;
	int				*sorted_num;
	unsigned int	*num_compress;

	array_length = 0;
	input = make_input(argc, argv, &array_length);
	num = make_nums(input, array_length);
	sorted_num = (int *)malloc(sizeof(int) * array_length);
	if (sorted_num == NULL)
		ft_put_error();
	ft_memcpy(sorted_num, num, sizeof(int) * array_length);
	if (bubble_sort(sorted_num, array_length) == 0)
		exit(1);
	num_compress = make_compress(num, sorted_num, array_length);
	duplicated_check(num_compress, array_length);
	sort_list(num_compress, array_length);
	free(num);
	free(sorted_num);
	free(num_compress);
}
