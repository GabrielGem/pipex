/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:06:19 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/15 17:14:41 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	validate_input_file(char *file);
static void	validate_output_file(char *file);

void	check_arguments_and_files(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Error: Invalid number of arguments\n");
		exit(1);
	}
	validate_input_file(argv[1]);
	validate_output_file(argv[4]);
}

static void	validate_input_file(char *file)
{
	if (access(file, F_OK) != 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(file, 2);
		perror(":\b");
		exit(1);
	}
	if (access(file, R_OK) != 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(file, 2);
		perror(":\b");
		exit(1);
	}
}

static void	validate_output_file(char *file)
{
	if (access(file, F_OK) == 0)
	{
		if (access(file, W_OK) != 0)
		{
			ft_putstr_fd("pipex: ", 2);
			ft_putstr_fd(file, 2);
			perror(":\b");
			exit(1);
		}
	}
}
