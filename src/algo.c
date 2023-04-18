/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:07:32 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/18 16:17:12 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quick_sort(t_data *d)
{
	if (d->b->size > 3)
	{
		if (d->b->first->index != d->a->first->index)
		{
			
		}
	}

}

void	push_back(t_data *d)
{
	int	i;

	i = d->b->size + 1;
	while (--i > 0)
	{
		if (d->b->first->index == i)
			push(d, 'a');
		else
		{
			rotate_until(d, 'b', counter(d->b, i));
			push(d, 'a');
		}
	}
}

void	push_swap(t_data *d)
{
	int	min;
	int	max;
	int	range;
	int	i;

	range = root(d->a->size);
	min = 1;
	max = range;
	i = 0;
	if (!is_sorted(d))
	{
		while (i < (d->a->size + d->b->size))
		{
			while (i++ < max)
			{
				rotate_until(d, 'a', look_for_range(d, min, max, i));
				quick_sort(d);
				push(d, 'b');
			}
			min = i;
			i--;
			max = (min + range) - 1;
			if (max > d->a->size + d->b->size)
				max = d->a->size + d->b->size;
		}
		push_back(d);
	}
}
