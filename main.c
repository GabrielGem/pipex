/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:39:54 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/14 14:08:21 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc < 5 || argc > 5)
	{
		ft_printf("Error: Invalid number of arguments\n");
		return (1);
	}
	info = get_info(argv, envp);
	input_validations(&info);
	pipex(&info);
	clear_memory(&info);
	return (0);
}
