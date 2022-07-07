/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:42:46 by thomathi          #+#    #+#             */
/*   Updated: 2022/07/07 17:56:07 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	ps_issorted_tmp(t_stack *stack)
{
	int e;
	int smallest;

	e = 0;
	smallest = stack->tmp[0];
	while(++e < stack->taille)
	{
		if (smallest > stack->tmp[e])
			return 0;
		smallest = stack->tmp[e];
	}
	return 1;
}

int	ps_issorted_int(int *stack, int taille)
{
	int e;
	int smallest;

	e = 0;
	smallest = stack[0];
	while(++e < taille)
	{
		if (smallest > stack[e])
			return 0;
		smallest = stack[e];
	}
	return 1;
}

int	ps_issorted(t_stack *stack)
{
	int e;
	int smallest;

	e = 0;
	smallest = stack->elements[0];
	while(++e < stack->taille)
	{
		if (smallest > stack->elements[e])
			return 0;
		smallest = stack->elements[e];
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

int		find_pos_smallest(t_stack *stack)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = i;
	while (++i < stack->taille)
	{
		if (smallest > stack->elements[i])
			smallest = i;
	}
	return (smallest);
}

int		find_smallest(t_stack *stack)
{
	int	i;
	int	smallest;

	i = 0;
	while (++i < stack->taille)
	{
		if (smallest > stack->elements[i])
			smallest = stack->elements[i];
	}
	return (smallest);
}

void	ps_startsort(t_stack *stacka, t_stack *stackb)
{
	int	i;
	int	smallest;
	int pos;

	i = 0;
	smallest = find_smallest(stacka);
	pos = find_pos_smallest(stacka);
	while (smallest != stacka->elements[0])
		if ((stacka->taille - pos) > (stacka->taille / 2))
			reversea(stacka, 1);
		else
			rotatea(stacka, 1);
	pushb(stacka, stackb);
	if (stacka->taille == 0)
	{
		while (stackb->taille > 0)
			pusha(stacka, stackb);
		return ;
	}
	ps_startsort(stacka, stackb);
}

int	*bubblesort(int *numbers, int arrsize)
{
	int	i;
	int j;
	int temp;

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

int    ps_checkbigger(t_stack *stacka)
{
    int bigger;
    int pos_bigger;
    int i;

    pos_bigger = 0;
    i = 0;
    bigger = stacka->elements[i];
    while (i < stacka->taille)
    {
        if (bigger < stacka->elements[i])
        {
            bigger = stacka->elements[i];
            pos_bigger = i;
        }
        i++;
    }
    return pos_bigger;
}

int    ps_checksmaller(t_stack *stacka)
{
    int smaller;
    int pos_smaller;
    int i;

    pos_smaller = 0;
    i = 0;
    smaller = stacka->elements[i];
    while (i < stacka->taille)
    {
        if (smaller > stacka->elements[i])
        {
            smaller = stacka->elements[i];
            pos_smaller = i;
        }
        i++;
    }
    return pos_smaller;
}

int *get_smallestpos(t_stack *stack, int *numbers, int howmany)
{
	int *pos;
	int i;
	int current;
	
	i = 0;
	pos = numbers;
	while (i < howmany)
	{
		current = 0;
		while (numbers[i] != stack->elements[current])
			current++;
		pos[i] = current;
		i++;
	}
	return (pos);
}

int *get_smallestnumbers(t_stack *stack, int howmany)
{
	int *sorted;
	int *liste;
	int i;

	i = 0;
	sorted = stack->tmp;
	sorted = bubblesort(sorted, stack->taille);
	liste = sorted;
	while (i < howmany)
	{
		liste[i] = sorted[i];
		i++;
	}
	sorted = get_smallestpos(stack, liste, howmany);
	return (sorted);
}

void new_ps_customsort(t_stack *stacka, t_stack *stackb)
{
	int *liste;
	int i;
	int x;
	int j;

	i = 0;
	j = 0;
	liste = get_smallestnumbers(stacka, ((stacka->taille / 2) + 1));
	while (i < stacka->taille / 2)
	{
		ft_printf("%d\n", liste[i]);
		x = 0;
		while (x + j < liste[i])
		{
			rotatea(stacka, 1);
			x++;
			j++;
		}
		pushb(stacka, stackb);
		i++;
	}
	return ;
}

void old_ps_customsort(t_stack *stacka, t_stack *stackb)
{
    int i;
	int isreverse;
    int smaller;
    int bigger;

    i = 0;
	isreverse = 0;
    smaller = ps_checksmaller(stacka);
	if (smaller > stacka->taille / 2)
	{
		smaller = stacka->taille - smaller;
		isreverse = 1;
	}
    while (i++ < smaller)
	{
		if (!isreverse)
			rotatea(stacka, 1);
		else
			reversea(stacka, 1);
	}
	isreverse = 0;
    pushb(stacka, stackb);
	bigger = ps_checkbigger(stacka);
	i = 0;
	if (bigger > stacka->taille / 2)
	{
		bigger = stacka->taille - bigger;
		isreverse = 1;
	}
    while (i++ < bigger)
	{
		if (!isreverse)
			rotatea(stacka, 1);
		else
			reversea(stacka, 1);
	}
    pushb(stacka, stackb);
	rotateb(stackb, 1);
    if (stacka->taille == 0)
    {
		int j;

		j = 0;
		while(j < stackb->taille / 2)
		{
			reverseb(stackb, 1);
			j++;
		}
        while (stackb->taille != 0)
            pusha(stacka, stackb);
    }
    else
        old_ps_customsort(stacka, stackb);
}

int get_smallest(int *liste, int taille)
{
	int smallest;
	int i;

	smallest = liste[0];
	i = 1;
	while (i < taille)
	{
		if (liste[i] < smallest)
			smallest = liste[i];
		i++;
	}
	return smallest;
}

int get_biggest(int *liste, int taille)
{
	int biggest;
	int i;

	biggest = liste[0];
	i = 1;
	while (i < taille)
	{
		if (liste[i] > biggest)
			biggest = liste[i];
		i++;
	}
	return biggest;
}

void	first_part(t_stack *stacka, t_stack *stackb)
{
	while (stackb->taille > 0)
	{
		if (stackb->elements[0] == get_smallest(stackb->elements, stackb->taille))
		{
			pusha(stacka, stackb);
			rotatea(stacka, 1);
		}
		else if (stackb->elements[0] == get_biggest(stackb->elements, stackb->taille))
		{
			pusha(stacka, stackb);
		}
		else
			rotateb(stackb, 1);
	}
	return ;
}

void	last_part(t_stack *stacka, t_stack *stackb)
{
	while (stackb->taille > 0)
	{
		if (stackb->elements[0] == get_smallest(stackb->elements, stackb->taille))
		{
			pusha(stacka, stackb);
			rotatea(stacka, 1);
		}
		else if (stackb->elements[0] == get_biggest(stackb->elements, stackb->taille))
		{
			pusha(stacka, stackb);
		}
		else
			rotateb(stackb, 1);
	}
	return ;
}

int	push_to_b(t_stack *stacka, t_stack *stackb, int sorted, int x)
{
	int i;
	int taille;

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

void assembler(t_stack *stacka, int x)
{
	while (x > 0)
	{
		rotatea(stacka, 1);
		x--;
	}
}

void	last_push_to_b(t_stack *stacka, t_stack *stackb, int j)
{
	int x;

	x = 0;
	while (x < j)
	{
		pushb(stacka, stackb);
		x++;
	}
	return ;
}

void loic(t_stack *stacka, t_stack *stackb)
{
	int *sorted;
	int j;
	int i;
	int coef;

	sorted = bubblesort(stacka->tmp, stacka->taille);
	coef = 2;
	if (stacka->taille >= 100)
		coef += stacka->taille / 100 + 1;
	j = stacka->taille / coef;
	i = 0;
	while (coef-- > 1)
	{
		i = push_to_b(stacka, stackb, sorted[j * coef], i);

		// Trier la première partie
		first_part(stacka, stackb);
		// Assembler la première partie une fois triée
		if (coef > 1)
		{
			while (1)
			{
				if (stacka->elements[stacka->taille - 1] == sorted[stacka->taille - 1])
					break ;
				rotatea(stacka, 1);
			}
		}
	}
	while (1)
	{
		if (stacka->elements[stacka->taille - 1] == sorted[stacka->taille - 1])
			break ;
		reversea(stacka, 1);
	}
	/* while (1) */
	/* { */
	/* 	if (ps_issorted(stacka)) */
	/* 		break ; */
	/* 	reversea(stacka, 1); */
	/* 	pushb(stacka, stackb); */
	/* } */
	last_push_to_b(stacka, stackb, j);
	last_part(stacka, stackb);
	while (!ps_issorted(stacka))
		reversea(stacka, 1);
	return ;
}
