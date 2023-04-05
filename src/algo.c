/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:07:32 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/05 15:58:06 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_until(t_data *d, char type, int count)
{
	if (count > 0)
		while (count-- > 0)
			rotate(d, type);
	else if (count < 0)
		while (count++ < 0)
			reverse_rotate(d, type);
}

int	is_sorted(t_data *d)
{
	t_node	*temp;
	int		i;

	temp = d->a->first;
	i = 1;
	while (temp)
	{
		if (temp->index != i)
			return (0);
		i++;
		temp = temp->next;
	}
	return (1);
}

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
