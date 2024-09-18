/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:17:43 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:17:45 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	input_check(char **input)
{
	const char	*str;

	while (*input)
	{
		str = *input;
		if (str[0] == '+' || str[0] == '-')
			str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
				ft_put_error();
			str++;
		}
		input++;
	}
}

char	**make_input(int argc, char *argv[], size_t *array_length)
{
	char	**input;
	size_t	i;

	i = 0;
	if (argc == 1)
		exit(1);
	else if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (input == NULL)
			ft_put_error();
		while (input[i])
			i++;
	}
	else
	{
		argv++;
		input = argv;
		i = argc - 1;
	}
	*array_length = i;
	input_check(input);
	return (input);
}
