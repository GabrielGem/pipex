/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:39:54 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/09 18:03:57 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	input_validations(argv);
}

void	input_validations(argv);
{
	char	**paths;

	paths = get_env();
	handle_command(argv[2], paths);
	handle_command(argv[3], paths);
	//handle_file(char *file); TODO
}

char	**get_env(void)
{
	int		fd;
	char	*path;
	char	*env;
	char	*paths;
	int		i;
	
	fd = open("/etc/environment", O_RDONLY);
	path = get_next_line(fd);
	env = ft_strtrim(path, "PATH=\"\n");
	free(path);
	paths = ft_split(env, ':');
	free(env);
	i = 0;
	while (paths[i])
	{
		env = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = env;
		free(env);
		i++;
	}
	return (paths);
}

void	handle_command(char *cmd, char **paths)
{
	char	*absolute;

	while (*paths)
	{
		absolute = ft_strjoin(paths, cmd);
		if (access(absolute, F_OK) == 0)
			//''
		if (access(absolute, X_OK) == 0)
			//passed to a struct?
		paths++;
	}
	close(fd);
	return (NULL);
}
