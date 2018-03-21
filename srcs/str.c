/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:26:27 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/21 16:35:18 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_strcmp_ref(char *ref, char *str)
{
	int			i;
	char		*tmp;

	i = 0;
	if (ref && str && (ft_strlen(str) >= ft_strlen(ref)))
	{
		tmp = ft_strsub(str, 0, ft_strlen(ref));
		i = ft_strcmp(tmp, ref);
		free(tmp);
	}
	return (i);
}

static int			ft_char_ok_env(char c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	if (c == 45 || c == 95)
		return (1);
	return (0);
}

int				name_ok_env(char *name)
{
	int			i;

	i = 0;
	while (name[i])
	{
		if (ft_char_ok_env(name[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
