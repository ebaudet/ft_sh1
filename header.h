/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 22:40:32 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/27 22:40:32 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <sys/types.h>
# include <errno.h>
# include <stdlib.h>
# include <assert.h>
# include <sys/wait.h>
# include "libft/includes/libft.h"

typedef struct		s_data
{
	char			**argv;
	char			**env;
	char			*name_cmd;
	pid_t			pid;
	char			*prompt;
}					t_data;

int		ft_exec_cmd(t_data *data);
int		ft_get_cmd(t_data *data);
int		ft_exec(t_data *data);
char	**ft_get_path(char **tab);
int		ft_count_c(char *str, char c);
char	*ft_get_user(char **tab);

#endif
