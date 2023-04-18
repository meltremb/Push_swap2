/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:08:08 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/18 12:52:17 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_until(t_data *d, char type, int count)
{
	if (count > 0)
	{
		while (count-- > 0)
			rotate(d, type);
	}
	else if (count < 0)
	{
		while (count++ < 0)
			reverse_rotate(d, type);
	}
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

int	is_in_order(t_data *d, char type)
{
	t_node	*temp;
	int		nb_moves;

	nb_moves = 0;
	if (type == 'a')
	{
		temp = d->a->first;
		while (temp)
		{
			nb_moves++;
			if (temp->index > temp->next->index)
				return (nb_moves);
			temp = temp->next;
		}
	}
	else if (type == 'b')
	{
		temp = d->b->last;
		while (temp->prev)
		{
			nb_moves++;
			if (temp->index > temp->prev->index)
				return (nb_moves);
			temp = temp->prev;
		}
	}
	return (0);
}

int	root(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

int	smallest_range(int prev, int new)
{
	int	temp_prev;
	int	temp;

	temp = new;
	temp_prev = prev;
	if (prev < 0)
		temp_prev = prev * -1;
	if (new < 0)
		temp = new * -1;
	if (temp < temp_prev)
		return (new);
	else
		return	(prev);
}
