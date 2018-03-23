/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:13:55 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 10:45:20 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

/*
 ** DIR
 */
void		ch_dir_env(char ***env, char *new_pwd, char *oldpwd);
void		ch_dir(char ***env, char **cmd);

/*
 ** DIR_TOOLS
 */
void		ch_dir_part_two(char ***env, char **cmd);

/*
 ** DOTDOT
 */
char		*shorten_path(char *path);
/*
 ** ECHO
 */
char		**arrange_var(char *buf, char **env);
void		echo(char **cmd);

/*
 ** ENV
 */
char		**add_to_env(char **env, char *new_env);
char		*get_env(char **env, char *name);
char		**set_env(char ***env, char *name, char *value);
char		**switch_env_value(char ***env, char *name, char *new_env);
char		**unset_env(char **env, char *name);

/*
 ** ERROR
 */
void		error_cd(void);
void		error_chdir(char *str);
void		error_empty_env(void);
void		error_setenv(void);
void		error_unsetenv(void);

/*
 ** ENV_TOOLS
 */
void		free_word_tab(char **tab);
void		print_env(char **env);
int			get_env_size(char **env);
int			check_elt_in_env(char **env, char *elt);

/*
 ** EXE
 */
char		*get_exe_path(char *path, char **path_tab);
char		**get_path_tab(char **env, char *path);
void		run_execve(char **env, char **cmd);

/*
 ** INIT_ENV
 */
char		**add_shlvl(char **env);
char		**copy_env(char **env);
char		**init_main_env(char **env, int ac, char **av);
char		**init_new_env(void);

/*
 ** MAIN
 */

/*
 ** MAIN_TOOLS
 */
void		ft_exit(char **t_env, char **cmd_line, char **buf);
void		print_prompt(char **env);

/*
 ** PATH
 */
int			no_parent(char *path);
char		*get_parent(char *path);
char		*join_n_shorten(char *home, char *tail);

/*
 ** SPLIT
 */
char		**ft_split(char *str);

/*
 ** STR
 */
char		*add_slash(char *str);
int			ft_strcmp_ref(char *ref, char *str);
int			name_ok_env(char *str);
size_t		stop_char(char *str);
#endif
