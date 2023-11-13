/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:10:40 by psoares-          #+#    #+#             */
/*   Updated: 2023/02/13 17:03:50 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# define TRUE 1
# define FALSE 0

typedef struct s_list
{
	long long				content;
	struct s_list			*next;
	char					self;
}				t_list;

//void		print_stack(t_list **stack);
t_list		*find_min_elem(t_list *stack_a);
t_list		*find_max_elem(t_list *stack_a);
void		printstacks_all(t_list **stack_A, t_list **stack_B);
long long	media(t_list *stack);
long long	soma(t_list *lst);
//cost
int			elem_cost(t_list **a, t_list **b, t_list *elem);
int			toprrcost(t_list *stack, t_list *elem);
int			toprcost(t_list *stack, t_list *elem);
t_list		*get_best_elem(t_list **a, t_list **b);
t_list		*nearest(t_list *stack, t_list *elem);
//sort small
void		sort3(t_list **stack_A);
//sorting big
void		sort_big(t_list **a, t_list **b);
void		send_to_b(t_list **a, t_list **b);
void		place_to_top(t_list **a, t_list **b, t_list *elem);
void		select_sort(t_list **a, t_list **b);
// lists
t_list		*ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int content);
int			is_sorted(t_list *stack);
void		destroy_list(t_list **lst);
//moves
void		ft_push(t_list **stack_src, t_list **stack_dest, int option);
void		ft_revrotate(t_list **stack);
void		ft_rotate(t_list **stack);
void		ft_swap(t_list *stack, int option);
void		ft_revrotates(t_list **stack_A, t_list **stack_B);
void		ft_rotates(t_list **stack_A, t_list **stack_B);
//parsing
int			checker_duplicate(t_list *list);
long int	ft_atoi(char *str, int *erro);
int			ft_strlen(char *str);
int			ft_isdigit(int c);

#endif