/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:46 by psoares-          #+#    #+#             */
/*   Updated: 2023/02/13 17:04:16 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <unistd.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	select_sort(t_list **a, t_list **b)
{
	if (!is_sorted(*a))
	{
		if (ft_lstsize(*a) == 2)
			ft_swap(*a, 1);
		if (ft_lstsize(*a) == 3)
			sort3(a);
		if (ft_lstsize(*a) > 3)
			sort_big(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		erro;

	a = NULL;
	b = NULL;
	i = 0;
	erro = 0;
	if (argc < 2)
		return (FALSE);
	if (ft_strlen(argv[1]) == 0)
		return (0);
	while (argv[++i] && !erro)
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i], &erro)))->self = 'a';
	if (erro || !checker_duplicate(a))
		write(2, "Error\n", 6);
	else
		select_sort(&a, &b);
	destroy_list(&a);
	destroy_list(&b);
}
	//sort_big(&a, &b);
	//sort_big(&a, &b);
	//ft_push(&a, &b, 1);
	//print_stack(&a);
	//printstacks_all(&a, &b);
	//write(1, "\nteste\n", 7);
	//printf("%d\n", nearest(a, b)->content);
	//printf("\n%d", find_nearest(a, b)->content);
	//print_stack(&b);
	//sort_big(&a, &b);
