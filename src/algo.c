/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:07:32 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/06 12:14:46 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_data *d)
{
	int		i;
	int		count;
	t_node	*temp;

	i = 0;
	if (!is_sorted(d))
	{
		while (i < d->a->size + d->b->size)
		{
			i++;
			temp = d->a->first;
			count = 0;
			while (temp->index != i)
			{
				count++;
				temp = temp->next;
			}
			rotate_until(d, 'a', count);
			push(d, 'b');
		}
		while (d->b->size > 0)
			push(d, 'a');
	}
}
