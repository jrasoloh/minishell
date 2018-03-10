/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:25:40 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/10 21:05:02 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_main(char ***env, char **cmd)
{
	if (!ft_strcmp("cd", cmd[0]))
		ft_chdir(env, cmd);
	else if (!ft_strcmp("echo", cmd[0]))
		ft_echo(cmd);
	else if (!ft_strcmp("env", cmd[0]))
		ft_print_word_tab(*env);
	else if (!ft_strcmp("setenv", cmd[0]))
	{
		if (ft_get_env_size(cmd) == 3 && ft_name_ok_env(cmd[1]) == 1)
			*env = ft_setenv(*env, cmd[1], cmd[2]);
		else
			ft_error_setenv();
	}
	else if (!ft_strcmp("unsetenv", cmd[0]))
	{
		if (ft_get_env_size(cmd) == 2)
			*env = ft_unsetenv(*env, cmd[1]);
		else
			ft_error_unsetenv();
	}
	else
		ft_execve(*env, cmd);
}

char		**ft_init_env(void)
{
	char	**t_env;

	t_env = (char **)malloc(sizeof(char *) * (2));
	t_env[0] = ft_strdup("SHVL=2");
	t_env[1] = NULL;
	return (t_env);
}

char		**ft_main_env(char **env, int ac, char **av)
{
	char	**t_env;

	(void)ac;
	(void)av;
	t_env = NULL;
	if (env == NULL || *env == NULL)
		t_env = ft_init_env();
	else
	{
		t_env = ft_copy_env(env);
		ft_add_shlvl(&t_env);
	}
	return (t_env);
}

void		ft_exit(char **t_env, char **cmd_line, char **buf)
{
	if (get_next_line(0, buf) == 0)
	{
		ft_free_word_tab(t_env);
		if (cmd_line != NULL && *cmd_line != NULL)
			ft_free_word_tab(cmd_line);
		else if (cmd_line != NULL)
			free(cmd_line);
		exit(0);
	}
}

int			main(int ac, char **av, char **env)
{
	char	*buf;
	char	**t_env;
	char	**cmd_line;

	buf = NULL;
	cmd_line = NULL;
	t_env = ft_main_env(env, ac, av);
	while (1)
	{
		ft_prompt(t_env);
		ft_exit(t_env, cmd_line, &buf);
		cmd_line = ft_split(buf);
		if (ft_get_env_size(cmd_line) > 1)
			ft_interpret(&cmd_line, t_env);
		if (!*cmd_line)
			continue ;
		if (!ft_strcmp("exit", cmd_line[0]))
		{
			ft_free_word_tab(t_env);
			ft_free_word_tab(cmd_line);
			break ;
		}
		ft_main(&t_env, cmd_line);
	}
	return (0);
}
