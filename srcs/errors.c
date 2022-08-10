/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:31:44 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/03 14:59:08 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errors_free(t_stack *stacka, t_stack *stackb)
{
	freeing(stacka, stackb);
	errors();
}

void	errors(void)
{
	ft_printf("Error\n");
	exit(1);
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
}
