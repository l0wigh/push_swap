/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:59:49 by thomathi          #+#    #+#             */
/*   Updated: 2022/05/11 17:31:47 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Make the radix sort and find a way to translate
//		 the sort to the push_swap commands

/**
Deux stacks : A et B
A : Nombres aléatoires (positifs ou négatifs) non dupliqués
B : Vide
Tri en ordre croissant

Commandes :
sa (swap a) 					-> échange les deux premiers éléments de la stack A (ne fait rien si seulement 1 élément ou vide)
sb (swap b) 					-> échange les deux premiers éléments de la stack B (ne fait rien si seulement 1 élément ou vide)
ss (swap stacks) 				-> éffectue sa et sb en même temps
pa (push a) 					-> prends le premier élément de B et le met sur A (ne fait rien si B est vide)
pb (push b) 					-> prends le premier élément de A et le met sur B (ne fait rien si B est vide)
ra (rotate a) 					-> monte vers le haut tout les éléments de la pile A. Le premier élément devient le dernier
rb (rotate b) 					-> monte vers le haut tout les éléments de la pile B. Le premier élément devient le dernier
rr (rotate stacks) 				-> fait ra et rb en même temps
rra (reverse rotate a) 			-> fait l'inverse de ra
rrb (reverse rotate b) 			-> fait l'inverse de rb
rrr (reverse rotate stacks) 	-> fait rra et rrb en même temps
**/

#include "push_swap.h"

int	ps_verifyargs(char arguments[])
{
	int test;
	int i;

	i = 0;
	while (arguments[i] != '\0')
	{
		test = ft_isdigit(arguments[i]);
		if (test == 0)
		{
			return (test);
		}
		i++;
	}
	test = 1;
	return (test);
}

t_stack 	*ps_createstack(char *elements[], int taille)
{
	t_stack *stack;
	int i;
	int verify;
	int current;

	i = 1;
	taille--;
	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->taille = taille;
	stack->elements = (int*)malloc(sizeof(int) * taille);
	while (i <= taille)
	{
		verify = ps_verifyargs(elements[i]);
		if (verify == 1)
		{
			current = ft_atoi(elements[i]);
			stack->elements[i - 1] = current;
		}
		else
			return (NULL);
		i++;
	}
	return (stack);
}

void	showstacks(t_stack *stacka, t_stack *stackb)
{
	int		i;
	i = 0;
	ft_printf("Stack A : ");
	while (i < stacka->taille)
	{
		ft_printf("| %d ", stacka->elements[i]);
		i++;
	}
	ft_printf("|");
	i = 0;
	ft_printf("\nStack B : ");
	while (i < stackb->taille)
	{
		ft_printf("| %d ", stackb->elements[i]);
		i++;
	}
	ft_printf("|\n\n");
}

int	main(int argc, char *argv[])
{
	int		sorted;
	t_stack *stacka;
	t_stack *stackb;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	stacka = ps_createstack(argv, argc);
	stackb = ps_createstack(NULL, 1);
	if (stacka == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	sorted = ps_issorted(stacka);
	if (sorted)
		return (0);
	// useless lines here
	reversea(stacka, 1);
	showstacks(stacka, stackb);
	/**
	pusha(stacka, stackb);
	pusha(stacka, stackb);
	pusha(stacka, stackb);
	showstacks(stacka, stackb);
	pushb(stacka, stackb);
	showstacks(stacka, stackb);
	swapa(stacka, 1);
	showstacks(stacka, stackb);
	swapb(stackb, 1);
	showstacks(stacka, stackb);
	rotatea(stacka, 1);
	showstacks(stacka, stackb);
	reverseb(stackb, 1);
	showstacks(stacka, stackb);
	pusha(stacka, stackb);
	showstacks(stacka, stackb);
	reversea(stacka, 1);
	showstacks(stacka, stackb);
	pusha(stacka, stackb);
	pusha(stacka, stackb);
	showstacks(stacka, stackb);
	**/
	return (0);
}
