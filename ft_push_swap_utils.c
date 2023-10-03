/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:14:40 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/08/30 15:43:48 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mov_u(t_data *d)
{
	if (d->ndar - d->movn < d->ndarr)
	{
		while (d->movn > 0 && d->ndar > 0 && d->b[0] != d->ntmov)
		{
			ft_dup_mov(d, 2);
			d->movn--;
			d->ndar--;
		}
	}
	while (d->movn > 0 && d->b[0] != d->ntmov)
	{
		ft_rb(d);
		d->movn--;
	}
}

void	ft_mov_d(t_data *d)
{
	if (d->ndarr - d->movn < d->ndar)
	{
		while (d->movn > 0 && d->ndarr > 0 && d->b[0] != d->ntmov)
		{
			d->movn--;
			d->ndarr--;
			ft_dup_mov(d, 3);
		}
	}
	while (d->movn > 0 && d->b[0] != d->ntmov)
	{
		d->movn--;
		ft_rrb(d);
	}
}

void	ft_mov(t_data *d)
{
	if (d->movd == 'u')
		ft_mov_u(d);
	if (d->movd == 'd')
		ft_mov_d(d);
	ft_a_fin_need(d);
	ft_pa(d);
	ft_check_mov(d);
	ft_a_need(d);
}

int	ft_pos(t_data *d)
{
	int	i;
	int	n;
	int	pos;

	i = 1;
	n = d->a[0];
	pos = 0;
	while (i < d->na)
	{
		if (d->a[i] < n)
		{
			pos = i;
			n = d->a[i];
		}
		i++;
	}
	if (pos <= d->na / 2)
		return (1);
	return (0);
}

void	ft_c(t_data *d)
{
	int	i;
	int	j;
	int	t;

	d->c = (int *) malloc (sizeof(int) * d->na);
	if (!d->c)
		write(1, "Error\n", 6);
	i = -1;
	while (++i < d->na)
		d->c[i] = d->a[i];
	i = -1;
	while (++i < d->na - 1)
	{
		j = i + 1;
		while (j < d->na)
		{
			if (d->c[i] > d->c[j])
			{
				t = d->c[i];
				d->c[i] = d->c[j];
				d->c[j] = t;
			}
			j++;
		}
	}
}
