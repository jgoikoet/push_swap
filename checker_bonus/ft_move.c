/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:32:19 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/02 20:53:12 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_inst_error(t_data *d)
{
	write(1, "Error\n", 6);
	d->error = 1;
	ft_free(d);
	free(d);
	exit(-1);
}

void	ft_move(t_data *d, char *str)
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n' && str[3] == '\0')
		ft_sa(d);
	else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n' && str[3] == '\0')
		ft_sb(d);
	else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n' && str[3] == '\0')
		ft_pa(d);
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n' && str[3] == '\0')
		ft_pb(d);
	else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n' && str[3] == '\0')
		ft_ra(d);
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n' && str[3] == '\0')
		ft_rb(d);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		ft_rra(d);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		ft_rrb(d);
	else if (str[0] == 's' && str[1] == 's' && str[2] == '\n' && str[3] == '\0')
		ft_dup_mov(d, 1);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n' && str[3] == '\0')
		ft_dup_mov(d, 2);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		ft_dup_mov(d, 3);
	else
		ft_inst_error(d);
}
