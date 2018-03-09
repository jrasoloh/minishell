/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:47:22 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/07 16:52:48 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int			ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (0);
	return (1);
}

static int			ft_countwords(char *str)
{
	int				i;
	int				words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			i++;
		else
		{
			words++;
			while (ft_isspace(str[i]) == 1)
				i++;
		}
	}
	return (words);
}

static int			ft_strlen_spec(char *str)
{
	int				i;

	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	return (i);
}

static char			*ft_makeword(char *str, int *j)
{
	int				i;
	char			*res;
	
	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen_spec(&str[*j]) + 1));
	while (ft_isspace(str[*j]) == 1)
	{
		res[i] = str[*j];
		i++;
		*j = *j + 1;
	}
	res[i] = '\0';
	return (res);
}

char				**ft_split(char *str)
{
	char			**res;
	int				i;
	int				j;

	res = (char **)malloc(sizeof(char *) * (ft_countwords(str) + 1));
	j = 0;
	i = 0;
	while (i < ft_countwords(str))
	{
		if (ft_isspace(str[j]) == 1)
		{	res[i] = ft_makeword(str, &j);
			i++;
		}
		else
			j++;
	}
	res[i] = NULL;
	return (res);
}
