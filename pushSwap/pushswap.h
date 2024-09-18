/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:43:21 by tyamauch          #+#    #+#             */
/*   Updated: 2023/04/30 13:14:55 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	unsigned int	data;
	struct s_list	*prev;
	struct s_list	*next;
	int				flag;
}					t_list;

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_isdigit(int c);
int					push_swap(int list);
int					ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_put_error(void);
//debug用関数
void				debug_print(char *s, int *num, size_t array_length);
void				debug_print_list(char *s, t_list *list);
void				debug_print_pivot(char *s, unsigned int num);

size_t				bubble_sort(int *num, size_t size);
int					*make_nums(char *input[], size_t array_length);
char				**make_input(int argc, char *argv[], size_t *array_length);
int					*make_nums(char *input[], size_t array_length);
void				duplicated_check(unsigned int *num_compress,
						size_t array_length);
unsigned int		*make_compress(int *num, int *sorted_num,
						size_t array_length);
t_list				*make_list(unsigned int *num_compress, t_list **head,
						size_t array_length);
t_list				*init_node(unsigned int value);
unsigned int		list_count(t_list **list);
void				sa(t_list **a_head);
void				sb(t_list **b_head);
void				pa(t_list **a_head, t_list **b_head);
void				pb(t_list **a_head, t_list **b_head);
void				ra(t_list **a_head);
void				rb(t_list **b_head);
void				rra(t_list **a_head);
void				rrb(t_list **b_head);
void				two_element_sort_a(t_list **a_head);
void				three_element_sort_a(t_list **a_head);
void				four_element_sort_a(t_list **a_head, t_list **b_head,
						unsigned int array_length);
void				five_element_sort_a(t_list **a_head, t_list **b_head,
						unsigned int array_length);
void				six_element_sort_a(t_list **a_head, t_list **b_head,
						unsigned int array_length);
void				two_element_sort_b(t_list **b_head);
void				push_swap_sort(t_list **a_head, t_list **b_head,
						unsigned int array_length);
void				optimize_list_a(t_list **a_head, t_list **b_head,
						unsigned int array_length);
unsigned int		list_count(t_list **list);
unsigned int		max_value_find(t_list **list, unsigned int max_value);
unsigned int		tail_value_find(t_list **list);
#endif
