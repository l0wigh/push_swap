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

int ps_issorted(t_stack *stack)
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
