/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_smallsort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:42:56 by thomathi          #+#    #+#             */
/*   Updated: 2022/07/27 14:08:22 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_recognition(t_stack *stacka)
{
	int smallest;
	int biggest;
	
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
		return;
	return;
}

void thomas(t_stack *stacka)
{
	case_recognition(stacka);
	if (ps_issorted(stacka))
		return;
	else
		errors();
	return;
}
