/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:59:21 by ycostode          #+#    #+#             */
/*   Updated: 2024/02/07 17:46:01 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss2[i] && ss1[i] && ss1[i] == ss2[i])
		i++;
	return (ss1[i] - ss2[i]);
}

int	print_error(const char *msg, int value)
{
	perror(msg);
	return (value);
}

t_pipex	init_struct(t_cmd cmd, char **envp)
{
	t_pipex	pipex;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		++i;
	}
	if (!envp[i])
		pipex.env = NULL;
	else
		pipex.env = ft_split(&envp[i][5], ':');
	pipex.envp = envp;
	pipex.infile = -1;
	pipex.outfile = -1;
	pipex.pipe_saved = -1;
	pipex.cmd = cmd;
	return (pipex);
}

void	close_file(int infile, int oufile)
{
	if (infile != -1)
		close(infile);
	if (oufile != -1)
		close(oufile);
}

void	close_fd(t_pipex pipex)
{
	if (pipex.pipe_saved != -1)
		close(pipex.pipe_saved);
	close(pipex.infile);
	close(pipex.outfile);
}
