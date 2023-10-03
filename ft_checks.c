/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:40:40 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/08/30 15:55:17 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_mov(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	d->movn = 5000;
	while (i < d->nb)
	{
		if (ft_check_dis(d, i) < d->movn)
		{
			d->movn = ft_check_dis(d, i);
			d->ntmov = d->b[i];
			j = i;
		}
		i++;
	}
	if (d->nb)
		ft_check_dis(d, j);
}

int	ft_check_dis(t_data *d, int i)
{
	int	j;
	int	n[4];

	d->ntmov = d->b[i];
	ft_a_need(d);
	j = d->nb - i;
	if (d->ndar > i)
		n[0] = d->ndar;
	else
		n[0] = i;
	if (d->ndarr > j)
		n[1] = d->ndarr;
	else
		n[1] = j;
	n[2] = i + d->ndarr;
	n[3] = j + d->ndar;
	if (n[0] <= n[1] && n[0] <= n[2] && n[0] <= n[3])
		return (d->movd = 'u', n[0]);
	else if (n[1] <= n[0] && n[1] <= n[2] && n[1] <= n[3])
		return (d->movd = 'd', n[1]);
	else if (n[2] <= n[0] && n[2] <= n[1] && n[2] <= n[3])
		return (d->movd = 'u', n[2]);
	else
		return (d->movd = 'd', n[3]);
}

int	ft_check_min(t_data *d)
{
	int	i;

	if (d->na == 1)
		return (1);
	if (!d->na)
		return (0);
	i = 1;
	while (i < d->na)
	{
		if (d->a[0] > d->a[i++])
			return (0);
	}
	return (1);
}

int	ft_check_sub(t_data *d)
{
	int	i;

	if (d->na == 1)
		return (1);
	i = 0;
	while (i < d->na - 1)
	{
		if (d->a[i] > d->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check(t_data *d)
{
	int	i;

	if (d->na < d->n)
		return (0);
	if (d->n == 1)
		return (1);
	i = 0;
	while (i < d->n - 1)
	{
		if (d->a[i] > d->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
