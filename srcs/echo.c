/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:19:09 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/07 16:26:28 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_echo(char **cmd)
{
	int			i;

	if (ft_get_env_size(cmd) < 2)
		ft_putchar('\n');
	else
	{
		i = 1;
		while (i < ft_get_env_size(cmd) - 1)
		{
			ft_putstr(cmd[i]);
			ft_putchar(' ');
			i++;
		}
		if (cmd[i])
			ft_putstr(cmd[i]);
		ft_putchar('\n');
	}
}
