/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:48:49 by gehebert          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/09 04:01:44 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../incs/minishell.h"
# include "../libft/includes/libft.h"

extern int g_status;


static char **split_all(char **args, t_prompt *p)
{
    char **subsplit;
    int i;
    // int quotes[2];
=======
/*   Updated: 2022/11/11 02:08:37 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
extern int g_status;


static char **split_all(char **args, t_dot *p)
{
    char **subsplit;
    int i;
    int quotes[2];
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1

    (void) p;
    i = -1;
    while (args && args[++i])
    {
<<<<<<< HEAD
        // args[i] = expand_vars(args[i], -1, quotes, p);       
        // args[i] = expand_path(args[i], -1, quotes, \
        //     mini_getenv("HOME", prompt->envp, 4));              
        // subsplit = ft_cmdsubsplit(args[i], "<|>");              
=======
        args[i] = expand_vars(args[i], -1, quotes, p);       
        args[i] = expand_path(args[i], -1, quotes, mini_getenv("HOME", p->envp, 4));              
        subsplit = ft_cmd_div(args[i], "<|>");              
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
        ft_mx_rpl(&args, subsplit, i);                           
        i += ft_mx_len(subsplit) - 1;                          
        ft_mx_free(&subsplit);                                 
    }
    return (args); 
}

<<<<<<< HEAD
static void *parse_args(char **args, t_prompt *p)
{
    int is_exit;
    int i;

    is_exit = 0;
    // p->cmds = fill_nodes(split_all(args, p), -1);              
    if (!p->cmds)
        return (p);
    // i = ft_lstsize(p->cmds);
=======
static void *parse_args(char **args, t_dot *p)
{
    // int is_exit;
    int i;

    // is_exit = 0;
    p->cmds = fill_nodes(split_all(args, p), -1);              
    if (!p->cmds)
        return (p);
    i = ft_lstsize(p->cmds);
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
    // g_status = builtin(p, p->cmds, &is_exit, 0);             
    i = 0;
    while (i-- > 0)
        waitpid(-1, &g_status, 0);
    // if (!is_exit && &g_status == 13)
    //     g_status = 0;
    if (g_status > 255)
        g_status = g_status / 255;
<<<<<<< HEAD
    if (args && is_exit)
    {
        // ft_lstclear(&p->cmds, free_content);
        return (NULL);
    }
    return (p);
}

void    *check_args(char *out, t_prompt *p) 
{
    char    **a;
    // t_mini *n;
=======
    // if (args && is_exit)
    // {
    //     ft_lstclear(&p->cmds, free_content);
    //     return (NULL);
    // }
    return (p);
}

void *check_args(char *out, t_dot *p) 
{
    char    **tab;
    t_mini  *m;
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1

    if (!out)
    {
        printf("exit\n");
        return (NULL);
    }
    if (out[0] != '\0')
        add_history(out);                                 
<<<<<<< HEAD
    a = ft_cmdtrim(out, " ");                               
    free(out);
    if (!a)
        return ("");
    p = parse_args(a, p);                                    
    // if (p && p->cmds)
        // n = p->cmds->content;
    // if (p && p->cmds && n && n->full_cmd && ft_lstsize(p->cmds) == 1)
        // p->envp = mini_setenv("_", n->full_cmd[ft_mx_len(n->full_cmd) - 1], p->envp, 1);                                         --
=======
    tab = ft_cmdtrim(out, " ");           //input divided by space  **tab              
    free(out);
    if (!tab)
        return ("");
    p = parse_args(tab, p);                                    
    if (p && p->cmds)
        m = p->cmds->content;
    if (p && p->cmds && m && m->full_cmd && ft_lstsize(p->cmds) == 1)
        p->envp = mini_setenv("_", m->full_cmd[ft_mx_len(m->full_cmd) - 1],\
            p->envp, 1);                                  
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
    // if (p && p->cmds)
    //     ft_lstclear(&p->cmds, free_content);
    return (p); 
}
<<<<<<< HEAD
=======

>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1