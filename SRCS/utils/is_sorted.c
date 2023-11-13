/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:55:49 by psoares-          #+#    #+#             */
/*   Updated: 2023/02/07 22:36:36 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

int	is_sorted(t_list *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			if (stack->next->content < stack->content)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
	return (0);
}
