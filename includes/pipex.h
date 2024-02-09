/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:48:04 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/30 17:04:26 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# define BUFFER_SIZE 64

typedef enum e_fd
{
	PIPE_READ,
	PIPE_WRITE
}			t_fd;
typedef struct s_cmd
{
	char	**list;
	int		current;
	int		len;
}			t_cmd;
typedef struct s_pipex
{
	int		pipe[2];
	t_cmd	cmd;
	int		infile;
	int		outfile;
	int		pipe_saved;
	char	**env;
	char	**envp;
}			t_pipex;

void		close_file(int infile, int oufile);
int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split_cmd(char const *s, char c);
int			print_error(const char *msg, int value);
t_pipex		init_struct(t_cmd cmd, char **envp);
void		dups(int stdinfd, int stdoutfd);
bool		treat_child(t_pipex *pipex, char *cmd, int current, int max);
void		close_fd(t_pipex pipex);

#endif
