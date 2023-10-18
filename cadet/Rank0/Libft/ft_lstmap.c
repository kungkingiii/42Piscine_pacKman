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
t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));

    if (!new)
    {
        return 0;
    }

    new->content = content;
    new->next = 0;

    return new;
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *first;
    t_list *new;

    if (!f || !del)
        return (NULL);
    first = NULL;
    while (lst)
    {
        if (!(new = ft_lstnew((*f)(lst->content))))
        {
            while (first)
            {
                new = first->next;
                (*del)(first->content);
                free(first);
                first = new;
            }
            lst = NULL;
            return (NULL);
        }
        ft_lstadd_back(&first, new);
        lst = lst->next;
    }
    return (first);
}
