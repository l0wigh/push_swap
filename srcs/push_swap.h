/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:13:58 by thomathi          #+#    #+#             */
/*   Updated: 2022/07/08 12:49:56 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <unistd.h>

typedef struct s_stack
{
	int	taille;
	int	*elements;
	int	*tmp;
}	t_stack;

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
void	loic(t_stack *stacka, t_stack *stackb);
int		ps_issorted_int(int *stack, int taille);
int		ps_issorted(t_stack *stack);
int		*bubblesort(int *numbers, int arrsize);
int		get_biggest(int *liste, int taille);
int		get_smallest(int *liste, int taille);
int		push_to_b(t_stack *stacka, t_stack *stackb, int sorted, int x);
