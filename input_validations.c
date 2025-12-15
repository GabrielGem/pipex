/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:49:36 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/14 21:09:29 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_relative_path(t_info *info, char **path_cmd, char *cmd);

void	input_validations(t_info *info)
{
	if (ft_strchr(info->cmd1[0], '/'))
		info->path_cmd1 = info->cmd1[0];
	if (ft_strchr(info->cmd2[0], '/'))
		info->path_cmd2 = info->cmd2[0];
	if (info->path_cmd1 == NULL)
	{
		info->flags |= relative;
		check_relative_path(info, &info->path_cmd1, info->cmd1[0]);
		if (info->path_cmd1 == NULL)
		{
			info->flags &= ~relative;
			clear_memory(info);
			exit (1);
		}
	}
	if (info->path_cmd2 == NULL)
	{
		info->flags |= relative2;
		check_relative_path(info, &info->path_cmd2, info->cmd2[0]);
		if (info->path_cmd2 == NULL)
		{
			info->flags &= ~relative2;
			clear_memory(info);
			exit (1);
		}
	}
}

static void	check_relative_path(t_info *info, char **path_cmd, char *cmd)
{
	int		i;
	char	*absolute;

	i = 0;
	while (info->path[i])
	{
		absolute = ft_strjoin(info->path[i], cmd);
		if (!access(absolute, F_OK) && !access(absolute, X_OK))
		{
			*path_cmd = absolute;
			return ;
		}
		free(absolute);
		i++;
	}
	ft_putstr_fd("Error: Command does not exist or not without permission.\n", 2);
}
