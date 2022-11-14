/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:59:09 by gehebert          #+#    #+#             */
/*   Updated: 2022/11/11 03:02:01 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int g_status;

static void mini_getpid(t_dot *p) 
{
    pid_t   pid;

    pid = fork();                                             
    if (pid < 0)
    {
        //mini_perror(FORKERR, NULL, 1);                        
        ft_mx_free(&p->envp);                              
        exit(1);
    }
    if (!pid)
    {
       ft_mx_free(&p->envp);                                  
        exit(1);
    }
    waitpid(pid, NULL, 0);                                    
    p->pid = pid - 1; 
}

static t_dot init_vars(t_dot p, char *str, char **av)
{
    char *num;
    // t_mini m;

    str = getcwd(NULL, 0);                                            
    p.envp = mini_setenv("PWD", str, p.envp, 3);          // 
    free(str);
    str = mini_getenv("SHLVL", p.envp, 5);                       ///
    if (!str || ft_atoi(str) <= 0)
        num = ft_strdup("1");
    else
        num = ft_itoa(ps_atoi(str) + 1);
    free(str);
    p.envp = mini_setenv("SHLVL", num, p.envp, 5);       //
    free(num);
    str = mini_getenv("PATH", p.envp, 4);                       ///
    if(!str)
        p.envp = mini_setenv("PATH", "/usr/local/sbin/:/usr/local/bin:/usr/bin:/bin", p.envp, 4);  //
    free(str);
    str = mini_getenv("_", p.envp, 1);                          ///
    if (!str)
        p.envp = mini_setenv("_", av[0], p.envp, 1);         //
    free(str);
        return (p); 
}

static t_dot init_prompt(char **av, char **envp) 
{
    t_dot p;
    // t_mini m;
    char *str;

    str = NULL;
    p.cmds = NULL;
    p.envp = ft_mx_dup(envp);                              
    g_status = 0;
    mini_getpid(&p);                          
    p = init_vars(p, str, av);            
    return (p); 
}

int main(int ac, char **av, char **envp) 
{
    char *str;
    char *input;
    t_dot p;

    p = init_prompt(av, envp);                   
    while (av && ac) {
        signal(SIGINT, handle_sigint);               
        signal(SIGQUIT, SIG_IGN);                    
        str = mini_getprompt(p);                
        if (str)
            input = readline(str);                    
        else
            input = readline("guest@minishell $ ");     
        free(str);
        if (!check_args(input, &p))
            break;
  
    }
    exit(g_status); 
}

