/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:44:16 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/14 11:50:47 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(int file, t_info *info, int *fd);
static int	open_file(const char *filename, int flags, mode_t mode);
static void	setup_child_io(int input_fd, int output_fd);

void	pipex(t_info *info)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		child_process(infile, info, fd);
	pid2 = fork();
	if (pid2 == -1)
		exit(1);
	if (pid2 == 0)
		child_process(outfile, info, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}

static void	child_process(int file, t_info *info, int *fd)
{
	int	file_fd;

	if (file == infile)
	{
		close(fd[0]);
		file_fd = open_file(info->file1, O_RDONLY, 0);
		setup_child_io(file_fd, fd[1]);
		close(file_fd);
		close(fd[1]);
		execve(info->path_cmd1, info->cmd1, info->envp);
	}
	if (file == outfile)
	{
		close(fd[1]);
		file_fd = open_file(info->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		setup_child_io(fd[0], file_fd);
		close(file_fd);
		close(fd[0]);
		execve(info->path_cmd2, info->cmd2, info->envp);
	}
}

static int	open_file(const char *filename, int flags, mode_t mode)
{
	int	file_fd;

	file_fd = open(filename, flags, mode);
	if (file_fd == -1)
		exit (1);
	return (file_fd);
}

static void	setup_child_io(int input_fd, int output_fd)
{
	if (dup2(input_fd, STDIN_FILENO) == -1
		|| dup2(output_fd, STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("Error: Failed to redirect I/O\n", 2);
		exit(127);
	}
}
