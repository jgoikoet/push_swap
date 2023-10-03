/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:41:20 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/04 12:15:42 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* #include <stdio.h> */

/* void	ft_print(t_data *d)
{
	int	i;

	i = 0;
	printf("\n");
	printf("A        B\n");
	while (i < d->na || i < d->nb)
	{
		if (i < d->na)
			printf("%i", d->a[i]);
		if (d->a[i] < 10)
			printf("       ");
		if (d->a[i] >= 10 && d->a[i] < 100)
			printf("      ");
		if (d->a[i] >= 100 && d->a[i] < 1000)
			printf("     ");
		if (d->a[i] >= 1000 && d->a[i] < 10000)
			printf("    ");
		if (i >= d->na)
			printf("  ");
		if (i < d->nb)
			printf("%i", d->b[i]);
		printf("\n");
		i++;
	}
} */

long int	ft_atoi(char *s)
{
	int			i;
	long int	n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	if (s[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	else if (s[0] == '+')
		i = 1;
	while (s[i])
	{
		n = n * 10;
		n = n + s[i++] - '0';
	}
	n = n * sign;
	return (n);
}

void	ft_ord_5(t_data *d)
{
	int	i;

	i = ft_pos(d);
	while (i && !ft_check_min(d))
		ft_ra(d);
	while (!i && !ft_check_min(d))
		ft_rra(d);
	while (!ft_check_sub(d) && ft_check_min(d))
		ft_pb(d);
	if (d->na == 3)
		ft_ord_3(d);
	while (!ft_check(d) && ft_check_sub(d))
		ft_pa(d);
}

void	ft_ord_3(t_data *d)
{
	if (d->n == 2)
		ft_sa(d);
	else
	{
		if (d->a[0] < d->a[1] && d->a[1] > d->a[2] && ft_check_min(d))
		{
			ft_rra(d);
			ft_sa(d);
		}
		if (d->a[0] < d->a[1] && d->a[1] > d->a[2])
			ft_rra(d);
		if (d->a[0] > d->a[1] && d->a[1] < d->a[2] && d->a[0] < d->a[2])
			ft_sa(d);
		if (d->a[0] > d->a[1] && d->a[1] < d->a[2])
			ft_ra(d);
		if (d->a[0] > d->a[1] && d->a[1] > d->a[2])
		{
			ft_sa(d);
			ft_rra(d);
		}
	}
}

void	ft_ord(t_data *d)
{
	t_start	*s;

	s = (t_start *) malloc (sizeof(t_start));
	if (!s)
		return ;
	d->ppos = 0;
	ft_start(d, s);
	ft_check_mov(d);
	ft_a_need(d);
	while (d->nb)
		ft_mov(d);
	ft_final_swap(d);
}

int	ft_swap(t_data *d)
{
	d->b = (int *) malloc (sizeof(int) * d->na);
	if (!d->b)
		return (write(1, "Error\n", 6), -1);
	ft_c(d);
	d->nb = 0;
	d->dup = 0;
	d->n = d->na;
	while (!ft_check(d) && d->n < 6)
	{
		if (d->n < 4)
			ft_ord_3(d);
		ft_ord_5(d);
	}
	if (d->n > 5 && !ft_check(d))
		ft_ord(d);
	return (0);
}
