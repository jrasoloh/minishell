/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:35:56 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 21:34:25 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		put_home_path(char *home, char *path)
{
	if ((ft_strlen(home) == ft_strlen(path)) && !(ft_strcmp(home, path)))
		ft_putchar('~');
	else if ((ft_strlen(path) > ft_strlen(home))
			&& ft_strcmp_ref(home, path) == 0)
	{
		ft_putchar('~');
		ft_putstr(&path[ft_strlen(home)]);
	}
	else
		ft_putstr(path);
}

void			print_prompt(char **env)
{
	char		*pwd;
	char		*home;

	pwd = NULL;
	home = NULL;
	if (env != NULL && *env != NULL)
	{
		pwd = getcwd(NULL, 0);
		if (((home = get_env(env, "HOME")) != NULL)
				&& ft_strcmp_ref(home, pwd) == 0)
			put_home_path(home, pwd);
		else
			ft_putstr(pwd);
		ft_putstr(" > ");
		free(pwd);
	}
	else
		ft_putstr("$> ");
}

void			ft_exit(char **t_env, char **cmd_line, char **buf)
{
	if (get_next_line(0, buf) == 0)
	{
		if (buf)
			free_word_tab(buf);
		free_word_tab(t_env);
		if (cmd_line != NULL && *cmd_line != NULL)
			free_word_tab(cmd_line);
		else if (cmd_line != NULL)
			free(cmd_line);
		exit(0);
	}
}

void			free_all(char *buf, char **env, char **cmd)
{
	if (buf)
		free(buf);
	free_word_tab(env);
	free_word_tab(cmd);
}
