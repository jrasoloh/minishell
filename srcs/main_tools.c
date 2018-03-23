/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:35:56 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/22 14:14:25 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			print_prompt(char **env)
{
	char		*tmp;
	char		*home;

	tmp = NULL;
	home = NULL;
	if (env != NULL && *env != NULL)
	{
		tmp = getcwd(NULL, 0);
		if (((home = get_env(env, "HOME")) != NULL)
				&& !(ft_strcmp(tmp, home)))
			ft_putchar('~');
		else
			ft_putstr(tmp);
		ft_putstr(" > ");
		free(tmp);
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
