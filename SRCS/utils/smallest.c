/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:58:07 by psoares-          #+#    #+#             */
/*   Updated: 2023/02/13 17:04:26 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

t_list	*find_min_elem(t_list *stack_a)
{
	t_list	*stack_min;

	stack_min = stack_a;
	while (stack_a != NULL)
	{
		if (stack_min->content > stack_a->content)
			stack_min = stack_a;
		stack_a = stack_a->next;
	}
	return (stack_min);
}
