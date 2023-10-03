/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:27:26 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/01 14:09:03 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_more_arg(char **ar)
{
	int	i;

	i = 0;
	while (ar[++i])
	{
		if (!ft_char_error(ar[i]) || ft_strlen(ar[i]) > 11)
			return (write(1, "Error\n", 6), 0);
	}
	i = 1;
	while (ar[i])
	{
		if (!ft_int_error(ar[i++]))
			return (write(1, "Error\n", 6), 0);
	}
	return (1);
}

int	ft_two_arg(char	**ar)
{
	int	i;

	i = 0;
	while (ar[i])
		i++;
	if (i < 1)
		return (write(1, "Error\n", 6), 0);
	i = -1;
	while (ar[++i])
	{
		if (!ft_char_error(ar[i]) || ft_strlen(ar[i]) > 11)
			return (write(1, "Error\n", 6), 0);
	}
	i = 0;
	while (ar[i])
	{
		if (!ft_int_error(ar[i++]))
			return (write(1, "Error\n", 6), 0);
	}
	return (1);
}

int	ft_set_more(t_data *d, char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		i++;
	d->na = i - 1;
	d->a = (int *) malloc (sizeof(int) * d->na);
	if (!d->a)
		return (write(1, "Error\n", 6), 0);
	i = 1;
	while (ar[i])
	{
		d->a[i - 1] = (int)ft_atoi(ar[i]);
		i++;
	}
	if (!ft_rep_check(d))
		return (free (d->a), write(1, "Error\n", 6), 0);
	return (1);
}

int	ft_set_two(t_data *d, char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		i++;
	d->na = i;
	d->a = (int *) malloc (sizeof(int) * d->na);
	if (!d->a)
		return (write(1, "Error\n", 6), 0);
	i = 0;
	while (ar[i])
	{
		d->a[i] = (int)ft_atoi(ar[i]);
		i++;
	}
	if (!ft_rep_check(d))
		return (free (d->a), write(1, "Error\n", 6), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*d;
	char	**split;

	if (argc < 2)
		return (0);
	d = (t_data *) malloc (sizeof(t_data));
	if (!d)
		return (write(1, "Error\n", 6), 0);
	split = ft_split(argv[1]);
	if (argc == 2 && ft_two_arg(split))
	{
		if (!ft_set_two(d, split) || !ft_comma_error(argv[1]))
			return (ft_del_ar(split), free(d), 0);
		ft_swap(d);
		ft_free(d);
	}
	else if (argc > 2 && ft_more_arg(argv))
	{
		if (!ft_set_more(d, argv))
			return (ft_del_ar(split), free(d), 0);
		ft_swap(d);
		ft_free(d);
	}
	ft_del_ar(split);
	return (free(d), 0);
}
