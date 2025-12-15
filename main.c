/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:39:54 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/14 21:10:57 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_file(char *argv);

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc != 5)
	{
		ft_printf("Error: Invalid number of arguments\n");
		return (1);
	}
	handle_file(argv[1]);
	info = get_info(argv, envp);
	input_validations(&info);
	pipex(&info);
	clear_memory(&info);
	return (0);
}

static void	handle_file(char *argv)
{
	if (access(argv, F_OK) != 0)
	{
		ft_printf("Error: File does not exist\n");
		exit(1);
	}
	if (access(argv, R_OK) != 0)
	{
		ft_printf("Error: Read permission denied in input file\n");
		exit(1);
	}
}
