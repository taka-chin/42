/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:11:45 by tyamauch          #+#    #+#             */
/*   Updated: 2022/10/14 22:17:17 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//        printf("%d\n", isalnum('a'));
//        printf("%d\n", isalnum('A'));
//        printf("%d\n", isalnum('1'));
//
//        printf("%d\n", ft_isalnum('a'));
//        printf("%d\n", ft_isalnum('A'));
//        printf("%d\n", ft_isalnum('1'));
//}
