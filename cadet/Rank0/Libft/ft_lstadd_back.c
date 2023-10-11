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

int main(void)
{

    t_list *mylist;
    // int d = 50;
    char *data = "test";
    t_list *new = ft_lstnew(data);
    char *data2 = "test2";
    t_list *new2 = ft_lstnew(data2);
    char *data3 = "test3";
    t_list *new3 = ft_lstnew(data3);
    mylist = new;
    ft_lstadd_back(&mylist, new2);
    ft_lstadd_back(&mylist, new3);

    t_list *res;
    res = ft_lstlast(mylist);
    // res = ft_lstlast(addn);
    printf("%s\n", ((char *)res->content));
    while (mylist != NULL)
    {
        printf("%s\n", (char *)mylist->content);
        mylist = mylist->next;
    }

    return (0);
}
