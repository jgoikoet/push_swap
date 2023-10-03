/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:02:59 by manue             #+#    #+#             */
/*   Updated: 2023/09/02 18:18:55 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_del(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(array[i++]);
	free(array);
	return (NULL);
}

char	*ft_subsplit(char const *s, int i)
{
	int		len;
	char	*str;
	int		start;

	start = i;
	len = 1;
	while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\f' \
	&& s[i] != '\r' && s[i] != '\v' && s[i] != ',' && s[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	str = (char *) malloc (sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while (s[start] != ' ' && s[start] != '\t' && s[start] != '\n' \
	&& s[start] != '\f' && s[start] != '\r' && s[start] != '\v' \
	&& s[start] != ',' && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_strcount(const char *s)
{
	int	i;
	int	snbr;
	int	ok;

	i = 0;
	snbr = 0;
	ok = 1;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && ok == 1 \
		&& s[i] != '\f' && s[i] != '\r' && s[i] != '\v' && s[i] != ',')
		{
			snbr++;
			ok = 0;
		}
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\f' \
		|| s[i] == '\r' || s[i] == '\v' || s[i] == ',')
			ok = 1;
		i++;
	}
	return (snbr);
}

char	**ft_split(char const *s)
{
	char	**array;
	char	*str;
	int		i;
	int		j;

	array = (char **) malloc (sizeof(char *) * ((ft_strcount(s)) + 1));
	if (array == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\f' \
		&& s[i] != '\r' && s[i] != '\v' && s[i] != ',')
		{
			str = ft_subsplit(s, i);
			if (!str)
				return (ft_del(array, j));
			array[j++] = str;
			i = i + ft_strlen(str) - 1;
		}
	}
	array[j] = 0;
	return (array);
}
