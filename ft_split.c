/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:54:07 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/19 11:11:31 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wrds(char const *s, char c)
{
	int	wrds;
	int	wrd_fnd;

	wrds = 0;
	wrd_fnd = 0;
	while (*s != '\0')
	{
		if (*s != c && wrd_fnd == 0)
		{
			wrds++;
			wrd_fnd = 1;
		}
		else if (*s == c)
			wrd_fnd = 0;
		s++;
	}
	return (wrds);
}

int	ft_chars(char const *s, char c)
{
	int	cs;

	cs = 0;
	while (*s != c && *s != '\0')
	{
		cs++;
		s++;
	}
	return (cs);
}

void	ft_del_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	*matrix = NULL;
}

void	ft_fillstr(int j, char **wrds, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		wrds[j][i++] = *s;
		s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**wrds;
	int		wrd_l;
	int		j;

	if (!s)
		return (NULL);
	wrds = ft_calloc(ft_wrds(s, c) + 1, sizeof(char *));
	j = 0;
	while (*s && wrds)
	{
		while (*s == c)
			s++;
		wrd_l = ft_chars(s, c);
		if (wrd_l)
		{
			wrds[j] = ft_calloc((wrd_l + 1), sizeof(char));
			if (!wrds[j])
				ft_del_matrix(wrds);
			ft_fillstr(j, wrds, s, c);
			s += wrd_l;
		}
		j++;
	}
	return (wrds);
}
