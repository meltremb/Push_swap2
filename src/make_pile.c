/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:19:22 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/03 14:18:42 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_piles(t_data *d)
{
	d->a = ft_calloc(1, sizeof(t_pile));
	d->b = ft_calloc(1, sizeof(t_pile));
}

int	is_indexed(t_pile *any)
{
	t_node	*temp;

	temp = any->first;
	while (temp)
	{
		if (temp->index == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	indexer(t_pile *any)
{
	t_node	*temp;
	t_node	*smolguy;
	int		index;

	smolguy = any->first;
	while (smolguy)
	{
		temp = any->first;
		index = 1;
		while (temp)
		{
			if (smolguy->content > temp->content)
				index++;
			temp = temp->next;
		}
		smolguy->index = index;
		smolguy = smolguy->next;
	}
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
		}
		ft_free_array((void ***) &args);
	}
	indexer(any);
}
