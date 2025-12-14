/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabr <gabrgarc@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:34:32 by gabr              #+#    #+#             */
/*   Updated: 2025/12/14 20:19:42 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>   // open
# include <unistd.h>  // close read write access dup dup2 execve fork pipe unlink
# include <stdlib.h>  // malloc free exit
# include <stdio.h>   // perror
# include <string.h>  // strerror
# include <sys/wait.h>// wait waitpid
# include "ft_printf.h"
# include "libft.h"

typedef struct s_info
{
	char	**cmd1;
	char	*path_cmd1;
	char	**cmd2;
	char	*path_cmd2;
	char	**path;
	char	**envp;
	char	*file1;
	char	*file2;
	char	flags;
}	t_info;

enum e_files
{
	infile,
	outfile
};

enum e_relative
{
	relative = 0b1,
	relative2 = 0b10
};

t_info	get_info(char **argv, char **envp);

void	pipex(t_info *info);
void	input_validations(t_info *info);
void	clear_memory(t_info *info);

#endif
