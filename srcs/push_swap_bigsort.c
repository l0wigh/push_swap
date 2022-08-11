/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bigsort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:42:46 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/11 13:07:04 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortb(t_stack *stacka, t_stack *stackb)
{
	int	taille;
	int	elem;

	while (stackb->taille > 0)
	{
		taille = stackb->taille;
		elem = stackb->elements[0];
		if (elem == get_smallest(stackb->elements, taille))
		{
			pusha(stacka, stackb);
			rotatea(stacka, 1);
		}
		else if (elem == get_biggest(stackb->elements, taille))
		{
			pusha(stacka, stackb);
		}
		else
			rotateb(stackb, 1);
	}
	return ;
}

void	last_push_to_b(t_stack *stacka, t_stack *stackb, int j)
{
	int	x;

	x = 0;
	while (x < j)
	{
		pushb(stacka, stackb);
		x++;
	}
	return ;
}

void	infinity(t_stack *stacka, int *sorted, int mode)
{
	int	t;

	t = stacka->taille - 1;
	while (1)
	{
		if (stacka->elements[t] == sorted[t])
			break ;
		if (mode == 0)
			rotatea(stacka, 1);
		else
			reversea(stacka, 1);
	}
	return ;
}

void	loic(t_stack *stacka, t_stack *stackb)
{
	int	i;
	int	coef;
	int	*sorted;
	int	j;

	i = 0;
	coef = 2;
	sorted = bubblesort(stacka->tmp, stacka->taille);
	if (stacka->taille >= 100)
		coef += stacka->taille / 100 + 1;
	j = stacka->taille / coef;
	while (coef-- > 1)
	{
		i = push_to_b(stacka, stackb, sorted[j * coef], i);
		sortb(stacka, stackb);
		if (coef > 1)
			infinity(stacka, sorted, 0);
	}
	infinity(stacka, sorted, 1);
	last_push_to_b(stacka, stackb, j);
	sortb(stacka, stackb);
	while (!ps_issorted(stacka))
		reversea(stacka, 1);
	return ;
}
