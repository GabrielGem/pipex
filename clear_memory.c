/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:44:37 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/15 10:44:08 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_memory(t_info *info)
{
	int	i;

	i = 0;
	while (info->path[i])
		free(info->path[i++]);
	free(info->path);
	i = 0;
	while (info->cmd1[i])
		free(info->cmd1[i++]);
	free(info->cmd1);
	if (info->flags & relative)
		free(info->path_cmd1);
	i = 0;
	while (info->cmd2[i])
		free(info->cmd2[i++]);
	free(info->cmd2);
	if (info->flags & relative2)
		free(info->path_cmd2);
}
