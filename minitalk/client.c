/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:21:59 by tyamauch          #+#    #+#             */
/*   Updated: 2023/04/16 17:28:15 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char(pid_t pid,char c)
{
	int bit;
	int i;
	unsigned char uc;

	uc = (unsigned char)c;
	i = 0;
	while(i < 8)
	{
		usleep(100);
		bit = (uc >> i) & 0x01;
		if(bit)
		{
			kill(pid,SIGUSR1);
		}
		else
		{
			kill(pid,SIGUSR2);
		}
		i++;
	}
}

int main(int argc,char *argv[])
{
	pid_t pid;
	char *message;
	/* The server PID */

	if(argc != 3)
		exit(1);
	pid = atoi(argv[1]);
	/* The string to send */
	message = argv[2];
	while(*message)
	{
		/* usleep(1000); */
		send_char(pid,*message);
		message++;
		/* usleep(1000); */
	}
}
