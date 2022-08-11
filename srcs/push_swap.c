/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:59:49 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/11 13:34:43 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project bien claqué, on va pas se mentir. Vive Pipex !!

#include "push_swap.h"
#include <stdlib.h>

int	isduplicate(int *elements, int taille)
{
	int	i;
	int	x;
	int	current;

	i = 0;
	while (i < taille)
	{
		x = i + 1;
		current = elements[i];
		while (x < taille)
		{
			if (current == elements[x])
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}

int	ps_verifyargs(char arguments[])
{
	int	test;
	int	i;

	i = 0;
	if (arguments[0] == '-')
		i++;
	while (arguments[i] != '\0')
	{
		test = ft_isdigit(arguments[i]);
		if (test == 0)
			return (test);
		i++;
	}
	test = 1;
	return (test);
}

t_stack	*ps_createstack(char *elements[], int taille, int mode)
{
	t_stack	*stack;
	int		i;

	i = 0;
	if (mode == 1)
		taille--;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->taille = taille;
	stack->elements = (int *)malloc(sizeof(int) * taille);
	stack->tmp = (int *)malloc(sizeof(int) * taille);
	while (i + mode <= taille)
	{
		if (ps_verifyargs(elements[i + mode]))
		{
			stack->elements[i] = ft_atoi(elements[i + mode]);
			stack->tmp[i] = ft_atoi(elements[i + mode]);
		}
		else
			errors_free(stack, NULL);
		i++;
		if (!elements[i + mode])
			break;
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	int		sorted;
	t_stack	*stacka;
	t_stack	*stackb;
	int		mode;

	mode = 1;
	if (argc <= 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ps_argc(argv);
		mode = 0;
	}
	stacka = ps_createstack(argv, argc, mode);
	stackb = ps_createstack(NULL, 1, 1);
	if (isduplicate(stacka->elements, stacka->taille))
		errors_free(stacka, stackb);
	sorted = ps_issorted(stacka);
	if (argc - mode == 3)
		thomas(stacka);
	else if (argc - mode == 5)
		hugo(stacka, stackb);
	else
		pre_loic(stacka, stackb);
	freeing(stacka, stackb);
	return (0);
}
