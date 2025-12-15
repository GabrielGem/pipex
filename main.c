/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:39:54 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/15 12:18:07 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	error_handle(argc, argv);
	info = get_info(argv, envp);
	input_validations(&info);
	pipex(&info);
	clear_memory(&info);
	return (0);
}
