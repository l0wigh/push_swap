/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:31:44 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/11 13:10:40 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	errors_free(t_stack *stacka, t_stack *stackb)
{
	errors();
	freeing(stacka, stackb);
}

void	errors(void)
{
	write(2, "Error\n", 6);
}

void	freeing(t_stack *stacka, t_stack *stackb)
{
	if (stacka != NULL)
	{
		free(stacka->elements);
		free(stacka->tmp);
		free(stacka);
	}
	if (stackb != NULL)
	{
		free(stackb->elements);
		free(stackb->tmp);
		free(stackb);
	}
	exit(1);
}

int	ps_argc(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return i;
}

void	pre_loic(t_stack *stacka, t_stack *stackb)
{
	if (ps_issorted(stacka))
		return ;
	loic(stacka, stackb);
	return ;
}
