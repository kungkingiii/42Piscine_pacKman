#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
    {
        return;
    }
    del(lst->content);
    free(lst);
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *current;

    if (!lst || !del)
    {
        return;
    }
    while (lst && *lst)
    {
        current = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = current;
    }
    *lst = NULL;
}

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

void *map_list(void *content)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->content = content;
    new_node->next = NULL;
    return (void *)new_node;
}

void del_content(void *content)
{
    free(content);
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

int main(void)
{
    char *data = "Hello, ";
    char *data2 = "World!";
    // int d = 50;
    t_list *new;
    t_list *new2;
    t_list *addn;

    new = ft_lstnew(data);
    addn = new;
    new2 = ft_lstnew(data2);
    new2->next = addn;
    addn = new2;

    t_list *new_mapped_list = ft_lstmap(addn, map_list, del_content);

    t_list *res;
    res = new_mapped_list;
    while (res != NULL)
    {
        printf("%s\n", (char *)res->content);
        res = res->next;
    }

    return (0);
}
