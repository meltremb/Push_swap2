/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:08:08 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/07 13:03:42 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_until(t_data *d, char type, int count)
{
	if (count > 0)
	{
		while (count-- > 0)
		{
			rotate(d, type);
			//dbl_lst_print(d->a, d->b);
		}
	}
	else if (count < 0)
	{
		while (count++ < 0)
		{
			reverse_rotate(d, type);
			//dbl_lst_print(d->a, d->b);
		}
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