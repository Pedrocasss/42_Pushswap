/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmallest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:29:14 by psoares-          #+#    #+#             */
/*   Updated: 2023/02/08 20:12:18 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

void	sort3(t_list **stack_A)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_A)->content;
	b = (*stack_A)->next->content;
	c = (*stack_A)->next->next->content;
	if (a < b && b > c && a < c)
	{
		ft_revrotate(stack_A);
		ft_swap((*stack_A), 1);
	}
	else if (a > b && b < c && a < c)
		ft_swap((*stack_A), 1);
	else if (a < b && b > c && a > c)
		ft_revrotate(stack_A);
	else if (a > b && b > c && a > c)
	{
		ft_rotate(stack_A);
		ft_swap((*stack_A), 1);
	}
	else if (a > b && a > c && b < c)
		ft_rotate(stack_A);
}
