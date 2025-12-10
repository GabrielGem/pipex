/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabr <gabrgarc@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:34:32 by gabr              #+#    #+#             */
/*   Updated: 2025/12/08 12:20:49 by gabr             ###   ########.fr       */
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

#endif
