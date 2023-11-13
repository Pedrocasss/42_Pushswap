/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:51:21 by psoares-          #+#    #+#             */
/*   Updated: 2023/02/13 13:34:06 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

void	min_to_top(t_list **a)
{
	t_list	*min;

	min = find_min_elem(*a);
	while (*a != min)
	{
		if (ft_lstsize(min) <= ft_lstsize(*a) / 2)
			ft_revrotate(a);
		else
			ft_rotate(a);
	}
}

void	sort_big(t_list **a, t_list **b)
{
	if (!is_sorted(*a))
	{
		send_to_b(a, b);
		sort3(a);
		while (ft_lstsize(*b))
		{
			place_to_top(a, b, get_best_elem(a, b));
			ft_push(b, a, 1);
		}
		min_to_top(a);
	}
}
