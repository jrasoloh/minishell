/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:09:35 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/21 17:42:07 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		main_part_one(char ***env, char **cmd)
{
	if (!ft_strcmp("setenv", cmd[0]))
	{
		if (get_env_size(cmd) == 3 && name_ok_env(cmd[1]) == 1)
			*env = set_env(env, cmd[1], cmd[2]);
		else
			error_setenv();
	}
	else if (!ft_strcmp("unsetenv", cmd[0]))
	{
		if (get_env_size(cmd) == 2)
			*env = unset_env(*env, cmd[1]);
		else
			error_unsetenv();
	}
	else if (!ft_strcmp("env", cmd[0]))
		print_env(*env);
}

int			main(int ac, char **av, char **env)
{
	char	*buf;
	char	**t_env;
	char	**cmd_line;

	buf = NULL;
	cmd_line = NULL;
	t_env = init_main_env(env, ac, av);
	while (1)
	{
		print_prompt(t_env);
		ft_exit(t_env, cmd_line, &buf);
		if (cmd_line != NULL)
			free_word_tab(cmd_line);
		cmd_line = ft_split(buf);
		if (!*cmd_line)
			continue ;
		if (!ft_strcmp("exit", cmd_line[0]))
		{
			free_word_tab(t_env);
			free_word_tab(cmd_line);
			break ;
		}
		main_part_one(&t_env, cmd_line);
	}
	return (0);
}
