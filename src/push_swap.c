/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:29:20 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/07 12:42:06 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc < 3)
		return (0);
	d = ft_calloc(1, sizeof(t_data));
	init_piles(d);
	make_pile(d->a, argc, argv);
	dbl_lst_print(d->a, d->b);
	push_swap(d);
	dbl_lst_print(d->a, d->b);
	return (0);
}
