/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:25:40 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/09 17:42:57 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			*ft_store(char *str, int n)
{
	static char	*tab[100] = {0};
	static int	i = -1;

	if (str && n == 1)
		tab[++i] = str;
	if (n == -1)
		while (i > -1)
		{
			free(tab[i]);
			i--;
		}
	return (str);
}

int				ft_stop_char(char *str)
{
	int			i;

	i = 1;
	while (str[i++])
		if (ft_char_ok_env(str[i]) == 0)
			return (i);
	return (i);
}

void			ft_interpret(char ***cmd, char **env)
{
	int			i;
	int			stop;
	char		*new;
	char		*tail;

	new = NULL;
	tail = NULL;
	if (*cmd == NULL || **cmd == NULL || ft_get_env_size(*cmd) < 2)
		return ;
	i = 0;
	stop = 0;
	while ((*cmd)[i] != NULL)
	{
		if (ft_strlen((*cmd)[i]) > 1 && (*cmd)[i][0] == '$') 
		{
			if ((stop = ft_stop_char((*cmd)[i])) == ft_strlen((*cmd)[i]))
			{
				new = ft_strsub((*cmd)[i], 1, ft_strlen((*cmd)[i]) - 1);
				(*cmd)[i] = ft_store((*cmd)[i], 1);
				(*cmd)[i] = ft_get_env(env, new);
			}
			else
			{
				new = ft_strsub((*cmd)[i], 1, stop - 1);
				ft_putchar((*cmd)[i][stop]);
				ft_putendl(" STOPPEUR");
				tail = ft_strsub((*cmd)[i], stop, ft_strlen((*cmd)[i]) - 1);
				ft_putendl(tail);
				(*cmd)[i] = ft_store((*cmd)[i], 1);
				(*cmd)[i] = ft_strjoin(ft_get_env(env, new), tail);
				free(tail);
			}
			free(new);
		}
		i++;
	}
	ft_store(NULL, -1);
}

void			ft_add_shlvl(char ***env)
{
	char		*res;
	char		*value;
	
	res = (char *)malloc(sizeof(char) * (2));
	res[1] = '\0';
	value = NULL;
	if ((value = ft_get_env(*env, "SHLVL")) != NULL)
	{	
		res[0] = value[0] + 1;
		*env = ft_setenv(*env, "SHLVL", res);
	}
	else
		*env = ft_setenv(*env, "SHLVL", "2");
	free(value);
	free(res);
	ft_store(NULL, -1);
}

void			ft_prompt(char **env)
{
	if (env != NULL && *env != NULL && ft_get_env(env, "PWD") != NULL)
	{
		ft_putstr(getcwd(NULL, 0));
	//	printf("\033[31;42m%s> \n\033[0;0m", ft_get_env(env, "PWD"));
		ft_putstr("> ");
	}
	else
		ft_putstr("$> ");
}

void			ft_print_word_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

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
	return(t_env);
}

int			main(int ac, char **av, char **env)
{
	char	*buf;
	char	**t_env;
	int		i;
	char	**cmd_line;

	buf = NULL;
	if (env == NULL || *env == NULL)
		t_env = ft_init_env();
	else
	{
		t_env = ft_copy_env(env);
		ft_add_shlvl(&t_env);
	}
	while (1)
	{
		ft_prompt(t_env);
		if (get_next_line(0, &buf) == 0)
		{
			ft_free_word_tab(t_env);
			if (*cmd_line != NULL)
				ft_free_word_tab(cmd_line);
			exit(0);
		}
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
