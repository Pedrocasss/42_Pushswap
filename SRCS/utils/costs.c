/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:20:38 by psoares-          #+#    #+#             */
/*   Updated: 2023/02/13 15:08:43 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

t_list	*nearest(t_list *stack, t_list *elem)
{
	t_list			*nearest;
	long long		comparamemo;
	long long		diference;

	if (!stack || !elem)
		return (NULL);
	if (elem->content > find_max_elem(stack)->content)
		return (find_min_elem(stack));
	if (elem->content < find_min_elem(stack)->content)
		return (find_min_elem(stack));
	nearest = stack;
	comparamemo = LLONG_MAX;
	while (stack)
	{
		diference = stack->content - elem->content;
		if (comparamemo > diference && diference > 0)
		{
			comparamemo = diference;
			nearest = stack;
		}
		stack = stack->next;
	}
	return (nearest);
}

/*t_list	*nearest(t_list *stack, t_list *elem)
{
	t_list	*nearest;
	int		diff_curr;
	int		diff_smallest;

	if (!elem || !stack)
		return (NULL);
	if (elem->content < find_min_elem(stack)->content)
		return (find_min_elem(stack));
	if (elem->content > find_max_elem(stack)->content)
		return (find_min_elem(stack));
	nearest = stack;
	diff_smallest = INT_MAX;
	while (stack)
	{
		diff_curr = stack->content - elem->content;
		if (diff_curr < diff_smallest && elem->content < stack->content)
		{
			diff_smallest = diff_curr;
			nearest = stack;
		}
		stack = stack->next;
	}
	return (nearest);
}*/

int	toprcost(t_list *stack, t_list *elem)
{
	return (ft_lstsize(stack) - ft_lstsize(elem));
}

int	toprrcost(t_list *stack, t_list *elem)
{
	(void)stack;
	return (ft_lstsize(elem));
}

int	elem_cost(t_list **a, t_list **b, t_list *elem)
{
	int		a_cost;
	int		b_cost;
	t_list	*vizinho;

	vizinho = nearest(*a, elem);
	if (toprrcost(*b, elem) < toprcost(*b, elem))
		b_cost = toprrcost(*b, elem);
	else
		b_cost = toprcost(*b, elem);
	if (b_cost > toprrcost(*a, vizinho)
		|| b_cost > toprcost(*a, vizinho))
		return (b_cost);
	if (toprrcost(*a, vizinho) < toprcost(*a, vizinho))
		a_cost = toprrcost(*a, vizinho);
	else
		a_cost = toprcost(*a, vizinho);
	return (b_cost + a_cost);
}

t_list	*get_best_elem(t_list **a, t_list **b)
{
	t_list	*tempb;
	t_list	*res;
	int		cost_final;
	int		cost;

	tempb = *b;
	cost_final = INT_MAX;
	while (tempb)
	{
		cost = elem_cost(a, b, tempb);
		if (cost < cost_final)
		{
			cost_final = cost;
			res = tempb;
		}
		tempb = tempb->next;
	}
	return (res);
}
