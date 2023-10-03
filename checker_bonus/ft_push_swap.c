/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:41:20 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/02 20:24:41 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
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
void	ft_free(t_data *d)
{
	free(d->a);
	free(d->b);
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

int	ft_swap(t_data *d)
{
	char	*str;

	d->b = (int *) malloc (sizeof(int) * d->na);
	if (!d->b)
		return (write(1, "Error\n", 6), -1);
	d->nb = 0;
	d->n = d->na;
	d->error = 0;
	str = get_next_line(0);
	while (str)
	{
		ft_move(d, str);
		free (str);
		str = get_next_line(0);
	}	
	if (ft_check(d))
		write (1, "OK\n", 3);
	else if (!d->error)
		write (1, "KO\n", 3);
	return (0);
}
