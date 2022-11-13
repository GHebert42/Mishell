#ifndef MINISHELL_H
# define MINISHELL_H


# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/incs/libft.h"
# include "../includes/get_next_line.h"
# include <readline/readline.h>
# include <readline/history.h>


/* fd Refs*/
# define READ_END 0
# define WRITE_END 1

/* Colors Defined*/
# define DEFAULT "\001\033[0;39m\002"
# define GRAY "\001\033[0;90m\002"
# define RED "\001\033[0;91m\002"
# define GREEN "\001\033[0;92m\002"
# define YELLOW "\001\033[0;93m\002"
# define BLUE "\001\033[0;94m\002"
# define MAGENTA "\001\033[0;95m\002"
# define CYAN "\001\033[0;96m\002"
# define WHITE "\001\033[0;97m\002"

/* Token type Define*/
enum TokenType{
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_AMPERSAND = '&',
	CHAR_SQUOTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SEMICOLON = ';',
	CHAR_SPACE = ' ',
	CHAR_ESCAPESEQ = '\\',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_NULL = 0,
	TOKEN = -1,
};

typedef struct s_dot t_dot;
typedef struct s_token t_token;
typedef struct s_lexer t_lexer; 
typedef struct s_mini t_mini;

struct s_dot
{
	t_list *cmds;
	char **envp;
	pid_t	pid;
};

struct s_token
{
	char *data;
	int type;
	t_token *next;
};


struct s_lexer
{
	t_token *listok;
	int  ntok;
};

struct s_mini
{
	char **full_cmd;
	char *full_path;
	int infile;
	int outfile;
};

//signal
void    	handle_sigint(int sig);
char		*mini_getenv(char *var, char **envp, int n);
char		**mini_setenv(char *var, char *value, char **envp, int n);
// //prompt 
char   		*mini_getprompt(t_dot p);
//parse
void	*check_args(char *out, t_dot *p);
//subsplit
char 	**ft_cmdtrim(const char *s, char *set);
//div_cmd
char	**ft_cmd_div(char const *s, char *set);
//update
void    exec_custom(char ***out, char *full, char *args, char **envp) ;
//expand
char	*expand_vars(char *str, int i, int quotes[2], t_dot *p);
char	*expand_path(char *str, int i, int quotes[2], char *var);
//nodes
t_list	*fill_nodes(char **args, int i);
//redir
t_mini *get_outfile1(t_mini *token, char **args, int *i);
t_mini *get_outfile2(t_mini *token, char **args, int *i);
t_mini *get_infile1(t_mini *token, char **args, int *i);
t_mini *get_infile2(t_mini *token, char **args, int *i);
int	get_fd(int oldfd, char *path, int flags[2]);
	//  static t_dot	init_vars(t_dot prompt, char *str, char **av);
	//  static t_dot	init_prompt(char **av, char **envp); 
	// static char **split_all(char **args, t_dot p);
	// static t_dot 	parse_args(char **args, t_dot p);
#endif
