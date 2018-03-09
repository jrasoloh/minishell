/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:01:47 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/09 17:58:32 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define OK 1
# define NO 0

int				ft_char_ok_env(char c);
int				ft_check_elt_in_env(char **env, char *elt);
void			ft_chdir(char ***env, char **cmd);
char			**ft_copy_env(char **env);
void			ft_echo(char **cmd);
void			ft_env(char **env);
void			ft_error_setenv(void);
void			ft_error_unsetenv(void);
void			ft_error_cd(void);
void			ft_error_chdir(char *str);
char			*ft_exe_path(char *path, char **path_tab);
void			ft_execve(char **env, char **cmd);
void			ft_free_word_tab(char **tab);
char			*ft_get_env(char **env, char *elt);
int				ft_get_env_size(char **env);
int				ft_name_ok_env(char *name);
char			**ft_path_tab(char **env, char *path);
void			ft_print_word_tab(char **tab);
char			**ft_split(char *str);
char			*ft_store(char *str, int n);
char			**ft_unsetenv(char **env, char *name);
char			**ft_setenv(char **env, char *name, char *value);

#endif
