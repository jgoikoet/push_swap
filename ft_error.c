/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:33:52 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/01 13:11:57 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_comma_aux(char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == ',')
			n++;
		if (n > 1)
			return (0);
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-')
			n = 0;
		i++;
	}
	return (1);
}

int	ft_comma_error(char *s)
{
	int	i;

	i = 0;
	while (s[i] < '0' || s[i] > '9')
	{
		if (s[i++] == ',')
			return (write(1, "Error\n", 6), 0);
	}
	i = ft_strlen(s) - 1;
	while (s[i] < '0' || s[i] > '9')
	{
		if (s[i--] == ',')
			return (write(1, "Error\n", 6), 0);
	}
	if (!ft_comma_aux(s))
		return (write(1, "Error\n", 6), 0);
	return (1);
}

int	ft_rep_check(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->na)
	{
		j = i + 1;
		while (j < d->na)
		{
			if (d->a[i] == d->a [j++])
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_int_error(char *s)
{
	long int	n;

	n = ft_atoi(s);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int	ft_char_error(char *s)
{
	int	i;

	if ((s[0] < '0' || s[0] > '9') && s[0] != '-' && s[0] != '+')
		return (0);
	if ((s[0] == '-' || s[0] == '+') && s[1] == '\0')
		return (0);
	i = 1;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
