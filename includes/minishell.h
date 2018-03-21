/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:13:55 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/21 18:01:13 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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
 ** SPLIT
 */
char		**ft_split(char *str);

/*
 ** STR
 */
int			ft_strcmp_ref(char *ref, char *str);
int			name_ok_env(char *str);

#endif
