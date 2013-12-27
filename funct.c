/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 22:40:37 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/27 22:40:37 by ebaudet          ###   ########.fr       */
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
		{
			ft_putstr("[NOT_FOUND] : cherche pas la petite bete.");
			ft_putchar('\n');
			exit(0);
		}
	return (0);
}

int		ft_exec_cmd(t_data *data)
{
	int		ret;

	if (ft_strcmp(data->name_cmd, "cd") == 0)
	{
		if (data->argv[1])
		{
			ft_putstr(data->argv[1]);
			/*chdir(argv[1]);*/
		}
		ft_putstr("pas d'arguments\n");		
	}
	data->pid = fork();
	if (data->pid == -1)
	{
		ft_putstr("fork : problem.");
		ft_putchar('\n');
	}
	if (data->pid == 0)
	{
		ft_exec(data);
		exit(0);
	}
	if (data->pid > 0)
		wait(&ret);
	return (0);
}
