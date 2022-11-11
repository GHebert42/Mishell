/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:59:09 by gehebert          #+#    #+#             */
/*   Updated: 2022/11/10 22:01:20 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../includes/minishell.h"
# include "../libft/incs/libft.h"

extern int g_status;

int				ps_atoi(char *s);
long long		ps_atoll(char *s);



static void mini_getpid(t_prompt *p) 
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

static t_prompt init_vars(t_prompt prompt, char *str, char **av)
{
    char *num;

    str = getcwd(NULL, 0);                                            
    prompt.envp = mini_setenv("PWD", str, prompt.envp, 3);           
    free(str);
    str = mini_getenv("SHLVL", prompt.envp, 5);                       
    if(!str)
        num = ft_strdup("1");
    else if(!(ps_atoi(str)))
        num = ft_strdup("1");
    else
        num = ft_itoa(ps_atoi(str) + 1);
    free(str);
    prompt.envp = mini_setenv("SHLVL", num, prompt.envp, 5);       
    free(num);
    str = mini_getenv("PATH", prompt.envp, 4);                       
    if(!str)
        prompt.envp = mini_setenv("PATH", "/usr/local/sbin/:/usr/local/bin:/usr/bin:/bin", prompt.envp, 4);
    free(str);
    str = mini_getenv("_", prompt.envp, 1);                          
    if (!str)
        prompt.envp = mini_setenv("_", av[0], prompt.envp, 1);         
    free(str);
    return (prompt); 
}

static t_prompt init_prompt(char **av, char **envp) 
{
    t_prompt prompt;
    char *str;

    str = NULL;
    prompt.cmds = NULL;
    prompt.envp = ft_mx_dup(envp);                              
    g_status = 0;
    mini_getpid(&prompt);                          
    prompt = init_vars(prompt, str, av);            
    return (prompt); 
}

int main(int ac, char **av, char **envp) 
{
    char *str;
    char *input;
    t_prompt prompt;

    prompt = init_prompt(av, envp);                   
    while (av && ac) {
        signal(SIGINT, handle_sigint);               
        signal(SIGQUIT, SIG_IGN);                    
        str = mini_getprompt(prompt);                
        if (str)
            input = readline(str);                    
        else
            input = readline("guest@minishell $ ");     
        free(str);
        if (!check_args(input, &prompt))             
            break;
    }
    exit(g_status); 
}
   // int main()
    // {
    //     // Configure readline to auto-complete paths when the tab key is hit.
    //     rl_bind_key('\t', rl_complete);

    //     while (1) {
    //         // Display prompt and read input
    //         char* input = readline("prompt> ");

    //         // Check for EOF.
    //         if (!input)
    //             break;

    //         // Add input to readline history.
    //         add_history(input);
    //         // Do stuff...

    //         // Free buffer that was allocated by readline
    //         free(input);
    //     }
    //     return 0;
   // }