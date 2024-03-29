/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:28:46 by gehebert          #+#    #+#             */
/*   Updated: 2023/04/04 07:48:16 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

int	get_fd(int oldfd, char *path, int flags[2])
{
	int	fd;

	if (oldfd > 2)
		close(oldfd);
	if (!path)
		return (-1);
	if (access(path, F_OK) == -1 && !flags[0])
		chk_error(NDIR, path, 127);
	else if (!flags[0] && access(path, R_OK) == -1)
		chk_error(NPERM, path, 126);
	else if (flags[0] && access(path, W_OK) == -1 && access(path, F_OK) == 0)
		chk_error(NPERM, path, 126);
	if (flags[0] && flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (flags[0] && !flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (!flags[0] && oldfd != -1)
		fd = open(path, O_RDONLY);
	else
		fd = oldfd;
	return (fd);
}

t_node	*get_outfile1(t_node *t, char **a, int *i)
{
	char	*nl;
	int		flags[2];

	flags[0] = 1;
	flags[1] = 0;
	nl = "minishell: syntax error near unexpected node '>'";
	(*i)++;
	if (a[*i])
		t->outfile = get_fd(t->outfile, a[*i], flags);
	if (!a[*i] || t->outfile == -1)
	{
		*i = -1;
		if (t->outfile != -1)
		{
			ft_putendl_fd(nl, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (t);
}

t_node	*get_outfile2(t_node *t, char **a, int *i)
{
	char	*nl;
	int		flags[2];

	flags[0] = 1;
	flags[1] = 1;
	nl = "minishell: syntax error near unexpected node `>>'";
	(*i)++;
	if (a[++(*i)])
		t->outfile = get_fd(t->outfile, a[*i], flags);
	if (!a[*i] || t->outfile == -1)
	{
		*i = -1;
		if (t->outfile != -1)
		{
			ft_putendl_fd(nl, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (t);
}

t_node	*get_infile1(t_node *t, char **a, int *i)
{
	char	*nl;
	int		flags[2];

	flags[0] = 0;
	flags[1] = 0;
	nl = "minishell: syntax error near unexpected node `<'";
	(*i)++;
	if (a[*i])
		t->infile = get_fd(t->infile, a[*i], flags);
	if (!a[*i] || t->infile == -1)
	{
		*i = -1;
		if (t->infile != -1)
		{
			ft_putendl_fd(nl, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (t);
}

t_node	*get_infile2(t_node *t, char **a, int *i)
{
	char	*aux[2];
	char	*nl;
	char	*str[2];

	aux[0] = NULL;
	aux[1] = "minishell: warning: here-document delimited by end-of-file";
	nl = "minishell: syntax error near unexpected node `<<'";
	(*i)++;
	if (a[++(*i)])
	{
		aux[0] = a[*i];
		t->infile = get_here_doc(str, aux);
	}
	if (!a[*i] || t->infile == -1)
	{
		*i = -1;
		if (t->infile != -1)
		{
			ft_putendl_fd(nl, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (t);
}
