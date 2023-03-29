/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:19:22 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/29 14:28:00 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_piles(t_data *d)
{
	d->a = ft_calloc(1, sizeof(t_pile));
	d->b = ft_calloc(1, sizeof(t_pile));
}

void	make_pile(t_pile *any, int argc, char **argv)
{
	int		i;
	int		k;
	char	**args;

	i = 0;
	while (argv[++i] && i < argc)
	{
		k = -1;
		args = ft_split(argv[i], ' ');
		while (args[++k])
		{
			if (ft_str_isdigit(args[k]) == 0)
				ft_exit("Non-digit argument detected");
			dbl_lst_add_back(any, ft_atoi(args[k]));
			any->size++;
		}
		ft_free_array((void ***) &args);
	}
}
