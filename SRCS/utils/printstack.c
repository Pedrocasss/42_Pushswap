/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:55:31 by psoares-          #+#    #+#             */
/*   Updated: 2023/02/10 20:06:31 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

void	print_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		printf("%lld\n", tmp->content);
		tmp = tmp->next;
	}
}

void	printstacks_all(t_list **stack_A, t_list **stack_B)
{
	write(1, "\t\t---STACK A---\t\t\n", 18);
	print_stack(stack_A);
	write(1, "\t\t---STACK B---\t\t\n", 18);
	print_stack(stack_B);
}
