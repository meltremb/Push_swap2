/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:19:56 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/18 16:10:11 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	while ((tempfirst && tempfirst->index != value) && (templast && templast->index != value) && (countdown < any->size))
	{
		countdown++;
		countup--;
		tempfirst = tempfirst->next;
		templast = templast->prev;
		//printf("down %d up %d\n", countdown, countup);
	}
	//printf("down %d up %d\n", countdown, countup);
	if (tempfirst && tempfirst->index == value)
		return (countdown);
	else if (templast && templast->index == value)
		return (countup);
	else if (countdown == (countup * -1))
		return (countdown);
	else
		return (INT_MAX);
}

int	look_for_range(t_data *d, int min, int max, int i)
{
	int	nb_moves;
	int	prev_nb_moves;
	int	j;

	prev_nb_moves = counter(d->a, i);
	j = min - 1;
	while (j++ < max)
	{
	//	printf("uwu\n");
		nb_moves = counter(d->a, j);
	//	printf("prev %d now %d j %d\n", prev_nb_moves, nb_moves, j);
		prev_nb_moves = smallest_range(prev_nb_moves, nb_moves);
		//printf("%d %d %d %d\n", min, max, i, j);
	}
	return (prev_nb_moves);
}
