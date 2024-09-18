/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:21:54 by tyamauch          #+#    #+#             */
/*   Updated: 2023/04/17 06:54:38 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* global param */
static unsigned char c ;
static int i;

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	cn;

	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n %= 10;
		cn = n + '0';
		ft_putchar_fd(cn, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void signal_handler(int siguma, siginfo_t *info, void *ctx)
{
	(void)info;
	(void)ctx;
	int bit;

	bit = 0x01;

	if(siguma == SIGUSR1)
	{
		c = c | (bit << i);
	}
	i++;
	if(i == 8)
	{
		/* ft_putchar_fd(c,1); */
		write(1,&c,1);
		i = 0;
		c = 0;
	}
}

int main()
{
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1,&sa,NULL);
	sigaction(SIGUSR2,&sa,NULL);

	pid_t pid;
	/* pidを表示する */
	pid = getpid();
	ft_putnbr_fd(pid,1);
	write(1,"\n",1);
	while(1)
	{
		pause();
	}
	return (0);
}

