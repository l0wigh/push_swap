/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_smallsort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:42:56 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/23 15:12:14 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_recognition(t_stack *stacka)
{
	int	smallest;
	int	biggest;

	smallest = get_pos(stacka->elements, stacka->taille, 1);
	biggest = get_pos(stacka->elements, stacka->taille, 2);
	if (smallest == 2 && biggest == 3)
		swapa(stacka, 1);
	else if (smallest == 3 && biggest == 1)
	{
		swapa(stacka, 1);
		reversea(stacka, 1);
	}
	else if (smallest == 2 && biggest == 1)
		rotatea(stacka, 1);
	else if (smallest == 1 && biggest == 2)
	{
		swapa(stacka, 1);
		rotatea(stacka, 1);
	}
	else if (smallest == 3 && biggest == 2)
		reversea(stacka, 1);
	return ;
}

void	thomas(t_stack *stacka)
{
	if (ps_issorted(stacka))
		return ;
	case_recognition(stacka);
	if (ps_issorted(stacka))
		return ;
	else
		errors();
	return ;
}

void	finish_hugo(t_stack *stacka, t_stack *stackb, int smallest)
{
	pusha(stacka, stackb);
	if (smallest != stacka->elements[0])
	{
		rotatea(stacka, 1);
		pusha(stacka, stackb);
	}
	else
	{
		pusha(stacka, stackb);
		rotatea(stacka, 1);
	}
}

void	hugo(t_stack *stacka, t_stack *stackb)
{
	int	smallest;
	int	biggest;
	int	i;

	if (ps_issorted(stacka))
		return ;
	smallest = get_smallest(stacka->elements, stacka->taille);
	biggest = get_biggest(stacka->elements, stacka->taille);
	i = 0;
	while (i != 2)
	{
		if (smallest == stacka->elements[0] || biggest == stacka->elements[0])
		{
			pushb(stacka, stackb);
			i++;
		}
		else
			rotatea(stacka, 1);
	}
	thomas(stacka);
	finish_hugo(stacka, stackb, smallest);
	return ;
}
