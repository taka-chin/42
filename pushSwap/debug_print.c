#include "pushswap.h"

void debug_print_pivot(char *s,unsigned int num)
{
	ft_putstr_fd(s,1);
	//ft_putstr_fd("pivot is:",1);
	ft_putnbr_fd((int)num,1);
	ft_putchar_fd('\n',1);
}

void debug_print(char *s,int *num, size_t array_length)
{
	size_t i;

	i = 0;
	ft_putstr_fd(s,1);
	while(i <  array_length)
	{
		ft_putnbr_fd(num[i],1);
		if(i != array_length - 1)
			ft_putchar_fd(' ',1);
		i++;
	}
	ft_putchar_fd('\n',1);
}

void debug_print_list(char *s,t_list *list)
{
	t_list *p;
	p = list;
	ft_putstr_fd(s,1);
	while(p)
	{
		ft_putnbr_fd(p->data,1);
		ft_putchar_fd(' ',1);
		p = p->next;
	}
	ft_putchar_fd('\n',1);
}