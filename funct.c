/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 22:40:37 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/27 23:31:08 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_count_c(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

char	**ft_get_path(char **tab)
{
	char	**path;
	char	**tmp;
	int		i;
	int		j;

	tmp = ft_strsplit(tab[0] + 5, ':');
	i = ft_count_c(tab[0], ':') + 1;
	path = (char **)malloc(i * sizeof(*path));
	path[i] = 0;
	j = 0;
	while (j < i)
	{
		path[j] = ft_strjoin(tmp[j], "/");
		free(tmp[j]);
		j++;
	}
	free(tmp);
	return (path);
}

int		ft_exec(t_data *data)
{
	char	*tmp;
	char	**path;
	int		i;
	int		t;

	path = ft_get_path(data->env);
	i = 0;
	while (path[i] != 0)
	{
		tmp = ft_strjoin(path[i], data->name_cmd);
		t = access(tmp, X_OK);
		execve(tmp, data->argv, data->env);
		free(tmp);
		i++;
	}
	if (t == -1 && ft_strcmp(data->name_cmd, "exit") != 0)
		p_err("command not found: ", data->name_cmd, 0);
	return (0);
}

void	ft_exec_cmd_cd(t_data *data)
{
	char	*str;

	if (data->argv[1])
	{
		if ((chdir(data->argv[1])) == -1)
			p_err("cd: no such file or directory: ", data->argv[1], NO_ERR);
	}
	else
	{
		chdir(str = ft_strsplit(data->env[3], '=')[1]);
		free(str);
	}
}

int		ft_exec_cmd(t_data *data)
{
	int		ret;

	if (ft_strcmp(data->name_cmd, "cd") == 0)
		ft_exec_cmd_cd(data);
	else
		data->pid = fork();
	if (data->pid == -1)
	{
		ft_putstr("fork : problem.");
		ft_putchar('\n');
	}
	if (data->pid == 0 && (ft_strcmp(data->name_cmd, "cd") != 0))
	{
		ft_exec(data);
		exit(0);
	}
	if (data->pid > 0)
		wait(&ret);
	return (0);
}
