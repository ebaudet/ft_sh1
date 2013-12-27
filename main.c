/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 22:40:26 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/27 22:40:26 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_cmd(t_data *data)
{
	char	**tab;

	get_next_line(0, &data->prompt);
	tab = ft_strsplit(data->prompt, ' ');
	data->name_cmd = tab[0];
	data->argv = tab;
	return (0);
}

char	*ft_get_user(char **tab)
{
	char	*tmp;

	tmp = tab[4] + 5;
	return (tmp);
}

int		main(int ac, char **av, char **env)
{
	t_data		data;
	char		*user;

	ac = 0;
	av = 0;
	data.env = env;
	data.prompt = ft_strnew(1);
	user = ft_get_user(data.env);
	ft_putstr("$> Welcome ");
	ft_putstr(user);
	ft_putchar('\n');
	while (ft_strcmp(data.prompt, "exit") != 0)
	{
		ft_putstr("$> ");
		ft_get_cmd(&data);
		ft_exec_cmd(&data);
		free(data.name_cmd);
	}
	return (0);
}
