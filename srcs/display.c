#include "../includes/minishell.h"


void mx_display_tab(char **tab)
{
    int i = -1;
    if (tab[i])// && tab[0])
    {
        while(*tab[++i])
            printf ("%s :: ", tab[i]);
        printf (" :: \n" );
    }
}

// void mx_display_str(char *str)
// {
//     printf("%s ++++  \n", str);
// }

void mx_display_tkn(t_token *token)
{
    printf("%s == CMD :: \n", token->cmd);
    printf("%s == ARG :: \n", token->arg);   
}

