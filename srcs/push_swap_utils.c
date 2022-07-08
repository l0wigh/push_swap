/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:30:20 by thomathi          #+#    #+#             */
/*   Updated: 2022/07/08 12:36:46 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_issorted_int(int *stack, int taille)
{
	int	e;
	int	smallest;

	e = 0;
	smallest = stack[0];
	while (++e < taille)
	{
		if (smallest > stack[e])
			return (0);
		smallest = stack[e];
	}
	return (1);
}

int	ps_issorted(t_stack *stack)
{
	int	e;
	int	smallest;

	e = 0;
	smallest = stack->elements[0];
	while (++e < stack->taille)
	{
		if (smallest > stack->elements[e])
			return (0);
		smallest = stack->elements[e];
	}
	return (1);
}

int	*bubblesort(int *numbers, int arrsize)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < arrsize - 1)
	{
		while (j < arrsize - i - 1)
		{
			if (numbers[j] > numbers[j + 1])
			{
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	if (!ps_issorted_int(numbers, arrsize))
		bubblesort(numbers, arrsize);
	return (numbers);
}

int	push_to_b(t_stack *stacka, t_stack *stackb, int sorted, int x)
{
	int	i;
	int	taille;

	i = 0;
	taille = stacka->taille;
	taille -= x;
	while (i < taille)
	{
		if (stacka->elements[0] >= sorted)
		{
			x++;
			pushb(stacka, stackb);
		}
		else
			rotatea(stacka, 1);
		i++;
	}
	return (x);
}

void	assembler(t_stack *stacka, int x)
{
	while (x > 0)
	{
		rotatea(stacka, 1);
		x--;
	}
}
