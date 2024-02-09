/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:51:37 by ycostode          #+#    #+#             */
/*   Updated: 2024/02/07 17:50:11 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	read_stdin(t_pipex pipex, char *limiter)
{
	int		bytes;
	char	buffer[BUFFER_SIZE + 1];

	bytes = 1;
	while (bytes != 0)
	{
		write(1, "pipe heredoc> ", 14);
		bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (ft_strlen(buffer) - 1 == ft_strlen(limiter) && ft_strncmp(buffer,
				limiter, ft_strlen(limiter)) == 0)
			break ;
		if (write(pipex.infile, buffer, bytes) != bytes)
		{
			perror("write");
			return ;
		}
	}
}

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
	if (!pipex.env)
		return (perror("PATH"));
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

static void	here_doc(char *limiter, char *outfile, t_cmd cmd, char **envp)
{
	t_pipex	pipex;

	pipex = init_struct(cmd, envp);
	pipex.infile = open("here_doc.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	pipex.outfile = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (pipex.infile == -1 || pipex.outfile == -1)
	{
		perror("file");
		close_file(pipex.infile, pipex.outfile);
		ft_freesplit(pipex.env);
		return ;
	}
	read_stdin(pipex, limiter);
	close(pipex.infile);
	pipex.infile = open("here_doc.txt", O_RDONLY);
	while (pipex.cmd.current < pipex.cmd.len)
	{
		if (!exec(&pipex, pipex.cmd.list[pipex.cmd.current], pipex.cmd.current,
				pipex.cmd.len - 1))
			break ;
		pipex.cmd.current++;
	}
	close_fd(pipex);
	unlink("here_doc.txt");
	ft_freesplit(pipex.env);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	cmd;

	if (argc < 5)
		return (print_error("args", EXIT_FAILURE));
	if (!envp || !envp[0])
		return (print_error("envp", EXIT_FAILURE));
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc == 6)
	{
		cmd.current = 0;
		cmd.list = &argv[3];
		cmd.len = 2;
		here_doc(argv[2], argv[argc - 1], cmd, envp);
	}
	else
	{
		cmd.current = 0;
		cmd.list = &argv[2];
		cmd.len = argc - 3;
		execute(argv[1], argv[argc - 1], cmd, envp);
	}
	waitpid(-1, NULL, 0);
	return (EXIT_SUCCESS);
}
