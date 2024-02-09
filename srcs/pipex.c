/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:51:37 by ycostode          #+#    #+#             */
/*   Updated: 2024/02/07 17:50:11 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	exec(t_pipex *pipex, char *cmd, int current, int max)
{
	pid_t	pid;

	if (pipe(pipex->pipe) == -1)
		return (print_error("pipe", false));
	pid = fork();
	if (pid == -1)
		return (print_error("fork", false));
	if (pid == 0)
		return (treat_child(pipex, cmd, current, max));
	if (pipex->pipe_saved != -1)
		close(pipex->pipe_saved);
	pipex->pipe_saved = pipex->pipe[PIPE_READ];
	close(pipex->pipe[PIPE_WRITE]);
	return (true);
}

static void	execute(char *infile, char *outfile, t_cmd cmd, char **envp)
{
	t_pipex	pipex;

	pipex = init_struct(cmd, envp);
	pipex.infile = open(infile, O_RDONLY);
	pipex.outfile = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (pipex.infile == -1 || pipex.outfile == -1)
	{
		perror("file");
		close_file(pipex.infile, pipex.outfile);
		ft_freesplit(pipex.env);
		return ;
	}
	while (pipex.cmd.current < pipex.cmd.len)
	{
		if (!exec(&pipex, pipex.cmd.list[pipex.cmd.current], pipex.cmd.current,
				pipex.cmd.len - 1))
			break ;
		pipex.cmd.current++;
	}
	close_fd(pipex);
	ft_freesplit(pipex.env);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	cmd;

	if (argc != 5)
		return (print_error("args", EXIT_FAILURE));
	if (!envp || !envp[0])
		return (print_error("envp", EXIT_FAILURE));
	cmd.current = 0;
	cmd.list = &argv[2];
	cmd.len = argc - 3;
	execute(argv[1], argv[argc - 1], cmd, envp);
	waitpid(-1, NULL, 0);
	return (EXIT_SUCCESS);
}
