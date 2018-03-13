/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:33:27 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/13 11:54:02 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_error_setenv(void)
{
	ft_putendl("setenv: Incorrect arguments");
	ft_putendl("Usage: setenv [NAME=aA-_9] [VALUE]");
}

void			ft_error_unsetenv(void)
{
	ft_putendl("unsetenv: Incorrect arguments");
	ft_putendl("Usage: unsetenv [NAME]");
}

void			ft_error_cd(void)
{
	ft_putendl("cd: too many arguments");
	ft_putendl("Usage: cd [PATH]");
}

void			ft_error_chdir(char *str)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putendl(str);
}

void			ft_error_empty_env(void)
{
	ft_putendl("Unable to process action. Env file is not defined.");
	return ;
}
