/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:57:04 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/01 11:27:42 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_data *d)
{
	free(d->a);
	free(d->b);
	free(d->c);
}

void	ft_sa(t_data *d)
{
	int	t;

	if (d->na < 2)
		return ;
	t = d->a[0];
	d->a[0] = d->a[1];
	d->a[1] = t;
	if (!d->dup)
		write(1, "sa\n", 3);
}

void	ft_sb(t_data *d)
{
	int	t;

	if (d->nb < 2)
		return ;
	t = d->b[0];
	d->b[0] = d->b[1];
	d->b[1] = t;
	if (!d->dup)
		write(1, "sb\n", 3);
}

void	ft_pa(t_data *d)
{
	int	i;

	if (d->nb == 0)
		return ;
	i = d->na - 1;
	while (i >= 0)
	{
		d->a[i + 1] = d->a[i];
		i--;
	}
	d->a[0] = d->b[0];
	d->na = d->na + 1;
	i = 0;
	while (i < d->nb - 1)
	{
		d->b[i] = d->b[i + 1];
		i++;
	}
	d->nb = d->nb - 1;
	write(1, "pa\n", 3);
}

void	ft_pb(t_data *d)
{
	int	i;

	if (d->na == 0)
		return ;
	i = d->nb - 1;
	while (i >= 0)
	{
		d->b[i + 1] = d->b[i];
		i--;
	}
	d->b[0] = d->a[0];
	d->nb = d->nb + 1;
	i = 0;
	while (i < d->na - 1)
	{
		d->a[i] = d->a[i + 1];
		i++;
	}
	d->na = d->na - 1;
	write(1, "pb\n", 3);
}
