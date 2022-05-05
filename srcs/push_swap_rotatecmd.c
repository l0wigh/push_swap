/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotatecmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:22:06 by thomathi          #+#    #+#             */
/*   Updated: 2022/04/29 23:22:06 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotatea(t_stack *stacka, int show)
{
	int		i;
	int		tmp;
	int		taille;

	taille = stacka->taille;
	i = 0;
	tmp = stacka->elements[0];
	while (i < taille - 1)
	{
		stacka->elements[i] = stacka->elements[i + 1];
		i++;
	}
	stacka->elements[taille - 1] = tmp;
	if (show)
		ft_printf("ra\n");
	return ;
}

void	rotateb(t_stack *stackb, int show)
{
	int		i;
	int		tmp;
	int		taille;

	taille = stackb->taille;
	i = 0;
	tmp = stackb->elements[0];
	while (i < taille - 1)
	{
		stackb->elements[i] = stackb->elements[i + 1];
		i++;
	}
	stackb->elements[taille - 1] = tmp;
	if (show)
		ft_printf("rb\n");
	return ;
}

void	rotates(t_stack *stacka, t_stack *stackb)
{
	rotatea(stacka, 0);
	rotateb(stackb, 0);
	ft_printf("rr\n");
	return ;
}
