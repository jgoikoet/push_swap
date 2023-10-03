/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:53:57 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/01 11:20:45 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_swap(t_data *d)
{
	int	pos;
	int	i;
	int	n;

	pos = 0;
	i = 0;
	n = d->a[0];
	while (++i < d->na)
	{
		if (d->a[i] < n)
		{
			pos = i;
			n = d->a[i];
		}
	}
	if (pos <= d->na / 2)
	{
		while (d->a[0] != n)
			ft_ra(d);
	}
	else
	{
		while (d->a[0] != n)
			ft_rra(d);
	}
}

void	ft_a_fin_need(t_data *d)
{
	ft_a_need(d);
	if (d->ndar <= d->ndarr)
	{
		while (d->ndar-- > 0)
			ft_ra(d);
	}
	else
	{
		while (d->ndarr-- > 0)
			ft_rra(d);
	}
}

int	ft_search_a(t_data *d, int n)
{
	int	i;

	i = 0;
	while (i < d->na)
	{
		if (d->a[i++] == n)
			return (1);
	}
	return (0);
}

void	ft_a_need(t_data *d)
{
	int	i;

	i = 1;
	if (d->a[0] > d->ntmov && d->a[d->na - 1] < d->ntmov)
		d->ppos = 0;
	else
	{
		while (i < d->na)
		{
			if (d->a[i] > d->ntmov && d->a[i - 1] < d->ntmov)
				d->ppos = i;
			i++;
		}
	}
	d->ndar = d->ppos;
	if (d->ppos == 0)
		d->ndarr = 0;
	else
		d->ndarr = d->na - d->ppos;
}

void	*ft_del_ar(char **ar)
{
	int	i;

	i = 0;
	while (ar[i] != NULL)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
	return (NULL);
}
