/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:05:47 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/07 13:03:52 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_data *d, char type)
{
	int		value;

	if ((type == 'a' || type == 's') && d->a->size > 1)
	{
		value = d->a->first->index;
		d->a->first->index = d->a->first->next->index;
		d->a->first->next->index = value;
		if (type == 'a')
			write (1, "sa\n", 3);
	}
	if ((type == 'b' || type == 's') && d->b->size > 1)
	{
		value = d->b->first->index;
		d->b->first->index = d->b->first->next->index;
		d->b->first->next->index = value;
		if (type == 'b')
			write (1, "sb\n", 3);
	}
	if (type == 's')
		write (1, "ss\n", 3);
}

void	p(t_pile *a, t_pile *b)
{
	t_node	*temp;

	a->size++;
	b->size--;
	temp = b->first;
	b->first = b->first->next;
	if (a->first)
	{
		temp->next = a->first;
		a->first->prev = temp;
	}
	else
		a->last = temp;
	a->first = temp;
}

void	push(t_data *d, char type)
{
	if (type == 'a' && d->b->size > 0)
	{
		p(d->a, d->b);
		write (1, "pa\n", 3);
	}
	if (type == 'b' && d->a->size > 0)
	{
		p(d->b, d->a);
		write (1, "pb\n", 3);
	}
}

void	rotate(t_data *d, char type)
{
	t_node	*temp;

	if ((type == 'a' || type == 's') && d->a->size > 1)
	{
		temp = d->a->first;
		temp->prev = d->a->last;
		d->a->first = temp->next;
		d->a->last->next = temp;
		d->a->last = temp;
		if (type == 'a')
			write (1, "ra\n", 3);
	}
	if ((type == 'b' || type == 's') && d->b->size > 1)
	{
		temp = d->b->first;
		temp->prev = d->b->last;
		d->b->first = temp->next;
		d->b->last->next = temp;
		d->b->last = temp;
		if (type == 'b')
			write (1, "rb\n", 3);
	}
	if (type == 'r' && d->a->size > 2 && d->b->size > 1)
		write (1, "rb\n", 3);
}

void	reverse_rotate(t_data *d, char type)
{
	t_node	*temp;

	if ((type == 'a' || type == 's') && d->a->size > 1)
	{
		temp = d->a->last;
		temp->next = d->a->first;
		d->a->last = temp->prev;
		d->a->first->prev = temp;
		d->a->first = temp;
		if (type == 'a')
			write (1, "rra\n", 4);
	}
	if ((type == 'b' || type == 's') && d->b->size > 1)
	{
		temp = d->b->last;
		temp->next = d->b->first;
		d->b->last = temp->prev;
		d->b->first->prev = temp;
		d->b->first = temp;
		if (type == 'b')
			write (1, "rrb\n", 4);
	}
	if (type == 'r' && d->a->size > 2 && d->b->size > 1)
		write (1, "rrr\n", 4);
}
