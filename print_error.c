/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 15:03:14 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/30 15:03:14 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	p_err(char *s1, char *s2, int error)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr("\n");
	if (error != NO_ERR)
		exit(error);
}
