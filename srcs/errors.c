/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:31:44 by thomathi          #+#    #+#             */
/*   Updated: 2022/07/28 12:45:30 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	errors(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	freeing(t_stack *stacka, t_stack *stackb)
{
	free(stacka->elements);
	free(stacka);
	free(stackb->elements);
	free(stackb);
}
