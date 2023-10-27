/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:49:56 by ribana-b          #+#    #+#             */
/*   Updated: 2023/10/26 00:06:01 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (argc != 5)
		return (1);
	if (pipe(fd) < 0)
		ft_error_message("Pipe");
	pid = fork();
	if (pid < 0)
		ft_error_message("fork");
	else if (pid == 0)
		ft_first_child_process(argv, envp, fd);
	else
	{
		waitpid(pid, &status, WNOHANG);
		ft_parent_process(argv, envp, fd, argc);
	}
	return (0);
}
