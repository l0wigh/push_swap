/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:42:46 by thomathi          #+#    #+#             */
/*   Updated: 2022/05/10 12:05:06 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_simplifynumber(t_stack *stack)
{
	int i;
	int x;
	int pos;
	int biggest;
	int prevbiggest;

	x = 0;
	while (x++ < stack->taille)
	{
		i = 0;
		if (pos == i)
			biggest = stack->elements[i++];
		else
			biggest = stack->elements[i];
		while (++i < stack->taille)
		{
			if (biggest < stack->elements[i] && stack->elements[i] != prevbiggest)
			{
				biggest = stack->elements[i];
				pos = i;
			}
		}
		prevbiggest = biggest;
		stack->tmp[pos] = x;
	}
	stack->elements = stack->tmp;
}

int	ps_issorted(t_stack *stack)
{
	int i;
	int smallest;

	i = 1;
	smallest = stack->elements[0];
	while(i < stack->taille)
	{
		if (smallest > stack->elements[i])
			return 0;
		smallest = stack->elements[i];
		i++;
	}
	return 1;
}

void	ps_check_bigger(t_stack *stack)
{
	int i;
	int biggest;

	biggest = stack->elements[0];
	i = 1;
	while (i < 2)
	{
		if (biggest > stack->elements[i])
			swapa(stack, 1);
		i++;
	}
	return ;
}

void	ps_startsort(t_stack *stacka)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (i < stacka->taille)
	{
		ps_check_bigger(stacka);
		check = ps_issorted(stacka);
		if (check == 1)
			break;
		rotatea(stacka, 1);
		check = ps_issorted(stacka);
		if (check == 1)
			break;
		rotatea(stacka, 1);
		check = ps_issorted(stacka);
		i++;
	}
	if (check == 1)
		return ;
	i = 0;
	while (i < stacka->taille)
	{
		reversea(stacka, 1);
		check = ps_issorted(stacka);
		if (check == 1)
			break ;
		i++;
	}
	if (check == 1)
		return ;
	ps_startsort(stacka);
}
