/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:52:40 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/14 21:09:27 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(char **envp);

t_info	get_info(char **argv, char **envp)
{
	t_info	info;

	info = (t_info){0};
	info.path = get_path(envp);
	info.cmd1 = ft_split(argv[2], ' ');
	info.path_cmd1 = NULL;
	info.cmd2 = ft_split(argv[3], ' ');
	info.path_cmd2 = NULL;
	info.envp = envp;
	info.file1 = argv[1];
	info.file2 = argv[4];
	return (info);
}

static char	**get_path(char **envp)
{
	char	*env;
	char	*temp;
	char	**paths;
	int		i;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	paths = ft_split((*envp + 5), ':');
	i = 0;
	while (paths[i])
	{
		env = ft_strjoin(paths[i], "/");
		temp = paths[i];
		paths[i] = env;
		free(temp);
		i++;
	}
	return (paths);
}
