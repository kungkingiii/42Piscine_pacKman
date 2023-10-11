#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!new)
    {
        return;
    }
    new->next = *lst;
    *lst = new;
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
    ft_lstadd_front(&mylist, new);
    ft_lstadd_front(&mylist, new2);

    while (mylist != NULL)
    {
        printf("%s\n", (char *)mylist->content);
        mylist = mylist->next;
    }

    return (0);
}