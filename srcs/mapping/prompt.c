/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:58:53 by gehebert          #+#    #+#             */
/*   Updated: 2023/02/21 23:45:38 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

static	char	*get_home(t_table tab)
{
	char	*tmp;
	char	*pwd;
	char	*home;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_strdup("∅ ");
	home = ms_getenv("HOME", tab.envp, 4);
	if (home && home[0] && ft_strnstr(pwd, home, ft_strlen(pwd)))
	{
		tmp = pwd;
		pwd = ft_strjoin("~", &pwd[ft_strlen(home)]);
		free(tmp);
	}
	free (home);
	home = ft_strjoin(BLUE, pwd);
	free (pwd);
	pwd = ft_strjoin(home, " ");
	free (home);
	return (pwd);
}

static	char	*get_user(t_table tab)
{
	char	**user;
	char	*tmp;
	char	*tmp2;

	user = NULL;
	tmp2 = NULL;
	execustom(&user, "/usr/bin/whoami", "whoami", tab.envp);
	if (!user)
		user = ft_mx_ext(user, "guest");
	if (!ft_strncmp(user[0], "root", 4))
		tmp2 = ft_strjoin(NULL, RED);
	else if ((int)(user[0][0]) % 5 == 0)
		tmp2 = ft_strjoin(NULL, CYAN);
	else if ((int)(user[0][0]) % 5 == 1)
		tmp2 = ft_strjoin(NULL, GRAY);
	else if ((int)(user[0][0]) % 5 == 2)
		tmp2 = ft_strjoin(NULL, GREEN);
	else if ((int)(user[0][0]) % 5 == 3)
		tmp2 = ft_strjoin(NULL, MAGENTA);
	else
		tmp2 = ft_strjoin(NULL, YELLOW);
	tmp = ft_strjoin(tmp2, *user);
	free(tmp2);
	ft_mx_free(&user);
	return (tmp);
}

char	*getprompt(t_table tab)
{
	char	*tmp;
	char	*tmp2;
	char	*aux;

	tmp = get_user(tab);
	tmp2 = ft_strjoin(tmp, "@minishell");
	free(tmp);
	aux = get_home(tab);
	tmp = ft_strjoin(tmp2, aux);
	free(aux);
	free(tmp2);
	if (!g_status || g_status == -1)
		tmp2 = ft_strjoin(tmp, BLUE);
	else
		tmp2 = ft_strjoin(tmp, RED);
	free(tmp);
	tmp = ft_strjoin(tmp2, "$ ");
	free(tmp2);
	tmp2 = ft_strjoin(tmp, DEFAULT);
	free(tmp);
	return (tmp2);
}

/*
from check.c
		getprompt   => build ID prompt return char*
		get_user    => strjoin user data
		get_home    => strjoin folder data
*/
