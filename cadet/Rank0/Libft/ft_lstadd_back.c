#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstlast(t_list *lst)
{
    while (lst->next)
    {
        lst = lst->next;
    }

    return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;

    if (!new)
    {
        return;
    }

    if (!*lst)
    {
        *lst = new;
    }
    else
    {
        last = ft_lstlast(*lst);
        last->next = new;
    }
}
