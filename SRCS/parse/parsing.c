/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:47:00 by psoares-          #+#    #+#             */
/*   Updated: 2023/02/13 14:58:52 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

long int	ft_atoi(char *str, int *erro)
{
	int			i;
	long int	res;
	long int	sinal;

	i = 0;
	res = 0;
	sinal = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sinal *= -1;
		str++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		res = (res * 10) + (str[i++] - '0');
	res *= sinal;
	if (str[i] != 0 || res > INT_MAX || res < INT_MIN || i == 0)
		*erro = 1;
	return (res);
}

int	checker_duplicate(t_list *list)
{
	t_list	*temp;
	t_list	*temp2;

	temp = list;
	while (temp)
	{
		temp2 = list;
		while (temp2)
		{
			if (temp != temp2 && temp->content == temp2->content)
				return (FALSE);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (TRUE);
}
