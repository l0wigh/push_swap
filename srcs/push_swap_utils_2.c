/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:33:56 by thomathi          #+#    #+#             */
/*   Updated: 2022/07/08 12:36:41 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(int *liste, int taille)
{
	int	smallest;
	int	i;

	smallest = liste[0];
	i = 1;
	while (i < taille)
	{
		if (liste[i] < smallest)
			smallest = liste[i];
		i++;
	}
	return (smallest);
}

int	get_biggest(int *liste, int taille)
{
	int	biggest;
	int	i;

	biggest = liste[0];
	i = 1;
	while (i < taille)
	{
		if (liste[i] > biggest)
			biggest = liste[i];
		i++;
	}
	return (biggest);
}
