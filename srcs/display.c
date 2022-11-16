#include "../includes/minishell.h"


void mx_display(char **tab)
{
    // int i = -1;
    if (tab)// && tab[0])
    {
        while(*tab++)
            printf ("%s :: ", *tab);//[i]);
        printf (" :: \n" );
    }



}

// void mx_display(t_mini *m)
// {
//     printf("\n %s ::  \n", m->full_cmd[0]);
//     if (m->full_cmd[1])
//         printf("%s :: \n", m->full_cmd[1]);   

// }