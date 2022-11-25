/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:37 by gehebert          #+#    #+#             */
/*   Updated: 2022/11/24 20:35:49 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*	// static t_mini	*mx_init(void)
	// {
	// 	t_mini	*m;

	// 	m = malloc(sizeof(t_mini));
	// 	if (!m)
	// 		return (NULL);
	// 	m->full_cmd = NULL;
	// 	m->full_path = NULL;
	// 	m->infile = STDIN_FILENO;
	// 	m->outfile = STDOUT_FILENO;
	// 	return (m);
	// }
*/

// static t_token	*get_params(t_table *tab, t_token *token) //, char **a[2])//, int *i) // endtype (int)
	// {
	// 	int id;
	// 	int cmd;	
	// 	int nod;	
	// 	char ***mx;

	// 	mx = NULL;

	// 	nod = 0;
	// 	cmd = 0;
	// 	id = 0;
	// 	mx[id] = tab->cmds;//[cmd][nod];

	// 	if (tab->cmds[cmd][nod] && (nod < token->cmd_len) && (cmd < tab->token_len))
	// 	{
	// 		printf("\n\n\n");
	// 		if (mx[id][cmd][nod] == '>' && mx[id][cmd + 1] && mx[id][cmd + 1][nod] == '>')
	// 			token = get_outfile2(token, mx[id]);//nod
	// 		else if (mx[id][cmd][nod] == '>')
	// 			token = get_outfile1(token, mx[id]);//nod
	// 		/*else if (a[0][*i][0] == '<' && a[0][*i + 1] && \
	// 			a[0][*i + 1][0] == '<')
	// 			m = get_infile2(m, a[1], i);*/
	// 		else if (mx[id][cmd][nod] == '<')
	// 			token = get_infile1(token, mx[id]);	//nod
	// 		else if (mx[id][cmd][nod] != '|')
	// 		// 	m->full_cmd = ft_mx_ext(m->full_cmd, a[1][*i]);
	// 		// else
	// 		{
	// 			//mini_perror(PIPENDERR, NULL, 2);
	// 			// *i = -2;
	// 		}
	// 		return (token);
	// 	}
	// 	//mini_perror(PIPENDERR, NULL, 2);
	// 	// *i = -2;
	// 	return (token);
// }


t_table	*get_trimmed(t_table *tab)
{
	char	**temp;
	char	*aux;
	int		j;

	j = -1;
	temp = ft_mx_dup(tab->cmds);
	while (temp && temp[++j])
	{
		aux = ft_strtrim_all(temp[j], 0, 0); /* malloc machine_short */
		free(temp[j]);
		temp[j] = aux;
	}
	tab->node = temp;
	return (tab);
}
	
t_table		*fill_nodes(t_table *tab)	/*	arg[][] from splitt_all (token chunk)	*/
{
	int i;		// token id

	// t_token	**token;
		// t_list	*cmds[2];
		// token = init_token()
		// cmds[0] = NULL;
		// char	**temp[2];
		// tab = get_trimmed(tab); /* tab-node :: malloc_machine ->trim_all */
		// needed to token command

	// tab->cmds 
	i = 0;
	while (tab->cmds[i] && i < tab->token_len)
	{
		// revert from list 
			// need to set first arg => cmd 
			// 			set last arg => endtype
			//	middle arg (if so!) 	
		// cmds[1] = ft_lstlast(cmds[0]);

		if (i == 0 || (tab->cmds[i][0] == '|' && *tab->cmds[i + 1] && tab->cmds[i + 1][0]))
		{
				/*	i += args[i][0] == '|';
					ft_lstadd_back(&cmds[0], ft_lstnew(mx_init()));		// mx_start 
					cmds[1] = ft_lstlast(cmds[0]); 
				*/
		}

		  // temp[0] = args;
			// tab->token = get_params(tab, tab->node);//, &i); // params_ ended_ token_
			// token->cmd = cmds[1]->content;
			// token->arg = *temp[1];
			// token->endtype = cmds[1]->content;
			// if (i < 0)
			// 	return (stop_fill(cmds[0], args, temp[1]));
			// if (!args[i])
			// 	break ;
		i++;
	}
	// ft_mx_free(&temp[1]);
	return (tab);
}

// char	**fill_nodes(t_table *tab, int i)
	// {
	// 	// t_token	**token;
	// 	// t_list	*cmds[2];
	// 	// token = init_token()
	// 	// cmds[0] = NULL;
	// 	// char	**temp[2];

	// 	// temp[1] = get_trimmed(tab->cmds); /* malloc_machine twin part */
	// 	while (tab->cmds && i < tab->token_len)
	// 	{
	// 		// revert from list 
	// 			// need to set first arg => cmd 
	// 			// 			set last arg => endtype
	// 			//	middle arg (if so!) 	
	// 		// cmds[1] = ft_lstlast(cmds[0]);

	// 		if (i == 0 || (tab->cmds[i][0] == '|' && *tab->cmds[i + 1] && tab->cmds[i + 1][0]))
	// 		{
	// 			// i += args[i][0] == '|';
	// 		//	ft_lstadd_back(&cmds[0], ft_lstnew(mx_init()));		/* mx_start */
	// 		//	cmds[1] = ft_lstlast(cmds[0]);
	// 		}

	// 		// temp[0] = args;
	// 		tab->token = get_params(tab, tab->token);//, &i);
	// 		// token->cmd = cmds[1]->content;
	// 		// token->arg = *temp[1];
	// 		// token->endtype = cmds[1]->content;
	// 		// if (i < 0)
	// 		// 	return (stop_fill(cmds[0], args, temp[1]));
	// 		// if (!args[i])
	// 		// 	break ;
	// 	}
	// 	// ft_mx_free(&temp[1S
	// 	return (tab->node);
// }

/*
from parse.c
	fill_node 	=> t_list builder 
		get_trimmed		=> multiple cmd list
				str_trimm_all 	(malloc_machine)	==> trimm_all.c
		mx_init 		=> matrix start
		get_params		=> token_end part (struct mx)
		stop_fill		=> t_list (wrap + free)
*/