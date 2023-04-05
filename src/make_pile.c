/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:19:22 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/05 16:00:45 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_piles(t_data *d)
{
	d->a = ft_calloc(1, sizeof(t_pile));
	d->b = ft_calloc(1, sizeof(t_pile));
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

void	arg_check(char *args)
{
	int		i;

	i = 0;
	while (args[i++])
	{
		if (ft_str_isdigit(args) == 0 || (ft_atoi(args) > INT_MAX
				&& ft_atoi(args) < INT_MIN))
			ft_exit("Error");
	}
}

void	check_doubles(t_pile *a)
{
	t_node	*temp;
	t_node	*smol;
	int		doubles;

	smol = a->first;
	while (smol)
	{
		temp = a->first;
		doubles = 0;
		while (temp)
		{
			if (smol->index == temp->index)
				doubles++;
			if (doubles >= 2)
				ft_exit("Error");
			temp = temp->next;
		}
		smol = smol->next;
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
			arg_check(args[k]);
			dbl_lst_add_back(any, ft_atoi(args[k]));
		}
		ft_free_array((void ***) &args);
	}
	indexer(any);
	check_doubles(any);
}
