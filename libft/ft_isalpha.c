/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:22:47 by tyamauch          #+#    #+#             */
/*   Updated: 2022/10/16 01:25:53 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
//#include <stdio.h>
//#include <ctype.h>
//
//int ft_isalpha(int c);
//
//int main()
//{
//        printf("%d\n", isalpha('a'));
//        printf("%d\n", isalpha('A'));
//        printf("%d\n", isalpha('1'));
//
//        printf("%d\n", ft_isalpha('a'));
//        printf("%d\n", ft_isalpha('A'));
//        printf("%d\n", ft_isalpha('1'));
//}
