/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:07:32 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/07 13:26:23 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_back(t_data *d)
{
	while (d->b->size > 0)
		push(d, 'a');
}

int	counter(t_pile *any, int value)
{
	int		countdown;
	int		countup;
	t_node	*tempfirst;
	t_node	*templast;

	countdown = 0;
	countup = -1;
	tempfirst = any->first;
	templast = any->last;
	while (tempfirst->index != value && templast->index != value)
	{
		countdown++;
		countup--;
		tempfirst = tempfirst->next;
		templast = templast->prev;
	}
	if (tempfirst->index == value)
		return (countdown);
	return (countup);
}

void	push_swap(t_data *d)
{
	int	i;
	int	count;

	if (!is_sorted(d))
	{
		i = 0;
		while (i++ < d->a->size + d->b->size)
		{
			count = counter(d->a, i);
			if (count == 1)
				swap(d, 'a');
			count = counter(d->a, i);
			rotate_until(d, 'a', count);
			push(d, 'b');
		}
		push_back(d);
	}
}
