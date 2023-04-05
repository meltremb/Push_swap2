/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:14:32 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/05 10:42:57 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../reworked-libft/libft.h"
# include "../dbl_push_swap/include/dbl_extension_libft.h"

typedef struct s_data
{
	t_pile	*a;
	t_pile	*b;
	char	type;
}			t_data;

void	init_piles(t_data *d);
void	make_pile(t_pile *any, int argc, char **argv);
void	swap(t_data *d, char type);
void	push(t_data *d, char type);
void	rotate(t_data *d, char type);
void	reverse_rotate(t_data *d, char type);
void	push_swap(t_data *d);

#endif