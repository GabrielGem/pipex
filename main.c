/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:39:54 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/15 17:26:03 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	check_arguments_and_files(argc, argv);
	info = get_info(argv, envp);
	check_commands(&info);
	pipex(&info);
	clear_memory(&info);
	return (0);
}
