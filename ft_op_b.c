/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:23:11 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/08/30 13:54:34 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_data *d)
{
	int	i;
	int	t;

	if (d->na < 2)
		return ;
	t = d->a[0];
	i = 0;
	while (i < d->na - 1)
	{
		d->a[i] = d->a[i + 1];
		i++;
	}
	d->a[d->na - 1] = t;
	if (!d->dup)
		write(1, "ra\n", 3);
}

void	ft_rb(t_data *d)
{
	int	i;
	int	t;

	if (d->nb < 2)
		return ;
	t = d->b[0];
	i = 0;
	while (i < d->nb - 1)
	{
		d->b[i] = d->b[i + 1];
		i++;
	}
	d->b[d->nb - 1] = t;
	if (!d->dup)
		write(1, "rb\n", 3);
}

void	ft_rra(t_data *d)
{
	int	i;
	int	t;

	if (d->na < 2)
		return ;
	t = d->a[d->na - 1];
	i = d->na - 1;
	while (i > 0)
	{
		d->a[i] = d->a[i - 1];
		i--;
	}
	d->a[0] = t;
	if (!d->dup)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_data *d)
{
	int	i;
	int	t;

	if (d->nb < 2)
		return ;
	t = d->b[d->nb - 1];
	i = d->nb - 1;
	while (i > 0)
	{
		d->b[i] = d->b[i - 1];
		i--;
	}
	d->b[0] = t;
	if (!d->dup)
		write(1, "rrb\n", 4);
}

void	ft_dup_mov(t_data *d, int i)
{
	d->dup = 1;
	if (i == 1)
	{
		ft_sa(d);
		ft_sb(d);
		write(1, "ss\n", 3);
	}
	if (i == 2)
	{
		ft_ra(d);
		ft_rb(d);
		write(1, "rr\n", 3);
	}
	if (i == 3)
	{
		ft_rra(d);
		ft_rrb(d);
		write(1, "rrr\n", 4);
	}
	d->dup = 0;
}
