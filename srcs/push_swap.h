/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:13:58 by thomathi          #+#    #+#             */
/*   Updated: 2022/05/11 16:13:58 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../ft_printf/ft_printf.h"

typedef struct
{
	int taille;
	int *elements;
} t_stack;

void	pusha(t_stack *stacka, t_stack *stackb);
void	pushb(t_stack *stacka, t_stack *stackb);
void	swapa(t_stack *stacka, int show);
void	swapb(t_stack *stackb, int show);
void	swaps(t_stack *stacka, t_stack *stackb);
void	rotatea(t_stack *stacka, int show);
void	rotateb(t_stack *stackb, int show);
void	rotates(t_stack *stacka, t_stack *stackb);
void	reversea(t_stack *stacka, int show);
void	reverseb(t_stack *stackb, int show);
void	reverses(t_stack *stacka, t_stack *stackb);
int		ps_issorted(t_stack *stack);
