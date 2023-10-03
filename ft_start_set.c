/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:32:19 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/04 12:17:33 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_first_push(t_data *d, t_start *s, int n)
{
	int	i;

	i = 0;
	while (i <= s->cmin)
	{
		if (d->c[i++] == n)
			return (1);
	}
	i = s->cmax;
	while (i < d->n)
	{
		if (d->c[i++] == n)
			return (1);
	}
	return (0);
}

void	ft_set_range(t_data *d, t_start *s)
{
	s->cmin = 0;
	s->cmax = d->n -1;
	if (s->maxa > s->mina && (s->mina > s->maxb || s->maxa < s->minb \
	|| s->maxa < s->maxb))
	{
		while (d->c[s->cmin] != d->a[s->maxa] && d->c[s->cmin] != d->a[s->maxb])
			s->cmin++;
	}
	if (s->maxb > s->minb && (s->minb > s->maxa || s->maxb < s->mina))
	{
		while (d->c[s->cmax] != d->a[s->minb])
			s->cmax--;
	}
}

void	ft_mm_a(t_data *d, t_start *s)
{
	int	i;
	int	j;

	i = 0;
	s->maxa = 0;
	while (d->a[i] != d->c[0])
		i++;
	s->mina = i++;
	j = 1;
	while (i < d->na -1 && j < d->n -1)
	{
		while (d->a[i] != d->c[j] && i < d->na -1 && j < d->n -1)
			i++;
		if (d->a[i] == d->c[j])
		{
			s->maxa = i++;
			j++;
		}
	}
	if (s->maxa < s->mina)
		s->maxa = s->mina;
}

void	ft_mm_b(t_data *d, t_start *s)
{
	int	i;
	int	j;

	i = d->na - 1;
	while (d->a[i] != d->c[d->n -1])
		i--;
	s->maxb = i--;
	j = d->n - 2;
	s->minb = d->n - 1;
	while (i >= 0 && j >= 0)
	{
		while (i >= 0 && j >= 0 && d->a[i] != d->c[j])
			i--;
		if (i >= 0 && j >= 0 && d->a[i] == d->c[j])
		{
			s->minb = i--;
			j--;
		}
	}
	if (s->maxb < s->minb)
		s->minb = s->maxb;
}

void	ft_start(t_data *d, t_start *s)
{
	int		i;
	int		n;

	ft_mm_a(d, s);
	ft_mm_b(d, s);
	ft_set_range(d, s);
	i = 0;
	n = (d->a[d->na -1]);
	while (d->a[0] != n)
	{
		if (ft_first_push(d, s, d->a[0]))
		{
			ft_ra(d);
			i++;
		}
		else
		{
			ft_pb(d);
			i++;
		}
	}
	if (!ft_first_push(d, s, d->a[0]))
		ft_pb(d);
	free(s);
}
