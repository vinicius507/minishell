/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:23:25 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 16:30:54 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <execute/execute.h>

#define ERRO -2

static int	handle_red_stdout(int fd, t_redirection *redirection)
{
	int	fmode;
	int	fperm;

	if (fd >= 0)
		close(fd);
	fmode = O_WRONLY | O_CREAT | O_TRUNC;
	if (redirection->type == RED_APPND)
		fmode = O_WRONLY | O_CREAT | O_APPEND;
	fperm = S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH;
	fd = open(redirection->content, fmode, fperm);
	if (fd == -1)
		return (ERRO);
	if (redirection->type == RED_STDOUT)
		ft_putstr_fd("", fd);
	return (fd);
}

static int	set_stdout_fd(t_redirection *redirections)
{
	int	fd;
	int	dup_fd;

	fd = -1;
	while (redirections != NULL)
	{
		if (redirections->type == RED_STDOUT || redirections->type == RED_APPND)
		{
			fd = handle_red_stdout(fd, redirections);
			dup_fd = dup2(fd, STDOUT_FILENO);
			close(fd);
			if (dup_fd == -1)
				return (ERRO);
		}
		redirections = redirections->next;
	}
	return (fd);
}

static int	handle_red_stdin(int fd, t_redirection *redirection)
{
	int	heredoc_perm;

	if (fd >= 0)
		close(fd);
	heredoc_perm = S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH;
	if (redirection->type == RED_HDOC)
		fd = open(HDOC_TMPFILE, O_RDWR | O_CREAT | O_TRUNC, heredoc_perm);
	else
		fd = open(redirection->content, O_RDONLY, 0);
	if (fd == -1)
		return (ERRO);
	if (redirection->type == RED_HDOC)
	{
		ft_putstr_fd(redirection->content, fd);
		fd = open(HDOC_TMPFILE, O_RDONLY, 0);
		if (fd == -1)
			return (ERRO);
	}
	return (fd);
}

static int	set_stdin_fd(t_redirection *redirections)
{
	int				fd;
	int				dup_fd;

	fd = -1;
	while (redirections != NULL)
	{
		if (redirections->type == RED_STDIN || redirections->type == RED_HDOC)
		{
			fd = handle_red_stdin(fd, redirections);
			if (fd == ERRO)
				return (ERRO);
			dup_fd = dup2(fd, STDIN_FILENO);
			close(fd);
			if (dup_fd == -1)
				return (ERRO);
		}
		redirections = redirections->next;
	}
	unlink(HDOC_TMPFILE);
	return (fd);
}

int	handle_redirects(t_redirection *redirections)
{
	int	stdout_fd;
	int	stdin_fd;

	stdout_fd = set_stdout_fd(redirections);
	if (stdout_fd == ERRO)
		return (-1);
	stdin_fd = set_stdin_fd(redirections);
	if (stdin_fd == ERRO)
		return (-1);
	return (0);
}
