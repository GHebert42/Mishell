# Libft #
__A list of prototype from *libft* and their uses__

- - - -
# Table
#### [==>](#ft_is) __ft_is...__
#### [==>](#ft_to) __ft_to...__
#### [==>](#ft_str) __ft_str...__
#### [==>](#ft_mem) __ft_mem...__
#### [==>](#ft_put) __ft_put...__
#### [==>](#ft_lst) __ft_lst...__
- - - -

## __Prototype__ ##
	>* __File__
	>	* __Prototype__
	>		>* __Task__
         
         
## [ft_is...](#table)

<details>
	
* #### ft_isalpha.c
	* int		ft_isalpha(int c);
		>* return (1) if 'a' || 'A'
* #### ft_isdigit.c
	* int	ft_isdigit(int c);
		>* return (1) if number
* #### ft_isalnum.c
	* int	ft_isalnum(int c);
		>* return (1) if number || letter  	
* #### ft_isascii.c
	* int		ft_isascii(int c);
		>* return (1) if ASCII
* #### ft_isprint.c
	* int		ft_isprint(int c);
		>* return (1) if _printable_

</details>
	
## [ft_to...](#table)

<details>
	
* #### ft_atoi.c
	* int		ft_atoi(const char *str);
		* shapeshift __alpha__ to __int__
* #### ft_itoa.c
	* char		*ft_itoa(int nb);
		* shapeshift __int to char__
* #### ft_toupper.c
	* int		ft_toupper(int c);
		* ... to upperCase
* #### ft_tolower.c
	* int		ft_tolower(int c);
		* ... to lowerCase	 
	
</details>

## [ft_str...](#table)

<details>
	
* #### ft_strlen.c
	* size_t	ft_strlen(const char *str);
		* return _len_ of  _str_
* #### ft_strlcat.c
	* size_t 	ft_strlcat(char *dest, const char *src, size_t n);
		* copy  __diff__ between __a and b__ into __b__ : return (size of _b_)
* #### ft_strlcpy.c
	* size_t	ft_strlcpy(char *dest, const char *src, size_t n);
		* copy n size from src int dst : return (size src)
* #### ft_strchr.c
	* char	*ft_strchr(const char *s, int c);
		* search for __c__ into __str__ : return (&addrss) || _NULL_	
* ####  ft_strrchr.c
	* char	*ft_strrchr(const char *s, int c);
		* search char from _last_ : return (&address) || _NULL_
* #### ft_strcmp.c
	* int ft_strcmp(char *s1, char *s2);
		* compare diff between 2 str : return __-1,0,1__ 			
* #### ft_strncmp.c
 	* int	ft_strncmp(const char *s1, const char *s2, size_t n);
		* compare part between 2 str : return __-1,0,1__
* #### ft_strnstr.c
	* char	*ft_strnstr(const char *h, const char *n, size_t len);
		* needle in haystack; _if(!)_ ret.(NULL)  _else_ ret.(*h++)
* #### ft_strdup.c
	* char	*ft_strdup(const char *s);
		* copy  _*const char_ into __malloc ended__ char 
* #### ft_substr.c
	* char	*ft_substr(char const *s, unsigned int start, size_t len);
		* return a part of a str __calloc ended__
* #### ft_strjoin.c
	* char	*ft_strjoin(const char *s1, const char *s2);
		* join both const char __malloc ended__ 
* #### ft_strtrim.c
	* char	*ft_strtrim(const char *s1, const char *set);
		*  return a selected-removed-chaf-from-str __purify__ 
* #### ft_split.c
	* char	**ft_split(const char *s, char c);
		* subdivide str @separator into multiple str
* #### ft_strmapi.c
	* char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
		*  _indexing_ match index to a list... kind'of
* #### ft_striteri.c
	* void	ft_striteri(char *s, void (*f)(unsigned int, char *));
		* Making of' create a array/list from any...
</details>
	
## [ft_mem...](#table)

<details>

* #### ft_calloc
	* void	*ft_calloc(size_t n, size_t size);
		* allocated multiple bloc of memory
* #### ft_bzero		
	* void	ft_bzero(void *s, size_t n);
		* __fill up__ with '\0' for size_t (len)
* #### ft_memset
	* void	*ft_memset(void *b, int c, size_t len);
		* __fill up__ a *str of _len size_ with __'c'__ and return 
* #### ft_memcpy
	* void	*ft_memcpy(void *dst, const void *src, size_t n);
		* copy __n size__ of memory from __src__ to __dst__ 
* #### *ft_memmove
	* void	*ft_memmove(void *dst, const void *src, size_t n);
		* move __mem__ from src to dst _as long as it can , not more_
* #### ft_memcmp
	* int	ft_memcmp(const void *s1, const void *s2, size_t n);
		* return diff between mem... __-1,0,1__
* #### *ft_memchr
	* void	*ft_memchr(const void *s, int c, size_t n);
		* search char into preset len of str **return *ptr || null**
	
</details>

### [ft_put...](#table)

<details>
	
* #### ft_putchar_fd.c
	* void	ft_putchar_fd(char c, int fd);
		>* _write_ __char__ at  ___fd___ 
* #### ft_putstr_fd.c
 	* void	ft_putstr_fd(char *s, int fd);
 		>*  _write_ __str__ at  ___fd___
* #### ft_putendl_fd.c
	* void	ft_putendl_fd(char *s, int fd);
		>*  _write_ '\n' __after *s__ at __fd__
* #### ft_putnbr_fd.c
	* void	ft_putnbr_fd(int n, int fd);
		>* _write_ __int__ at  ___fd___
	
</details>

## [ft_lst](#table)

<details>

* void		ft_lstiter(t_list *lst, void (*f)(void *));
	>* create a list _content,next_
* t_list	*ft_lstnew(voiid *content);
	>* create a new member _malloc_
* int		ft_lstsize(t_list *lst);
	>* member counter
* void		ft_lstadd_front(t_list **lst, t_list *new);
	>* add before ptr
* void		ft_lstadd_back(t_list **lst, t_list *new);
	>* add after ptr
* t_list	*ft_lstlast(t_list *lst);
	>* add member at the end
* void		ft_lstdelone(t_list *lst, void (*del)(void *));
	>* delete a list member
* void		ft_lstclear(t_list **lst, void (*del)(void *));
	>* delete all list member
* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
	>* _mapping_ filling list adding member one-after-other  
	
</details>

## [END](#table)
