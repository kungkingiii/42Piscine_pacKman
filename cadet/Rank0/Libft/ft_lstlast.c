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
    char *data = "Hello, World!";
    char *data2 = "gg";
    // int d = 50;
    t_list *new;
    t_list *new2;
    t_list *addn;

    new = ft_lstnew(data);
    addn = new;
    new2 = ft_lstnew(data2);
    new2->next = addn;
    addn = new2;
    // t_list *last;
    // if (addn == NULL)
    // {
    //     addn = new2;
    // }
    // else
    // {
    //     last = ft_lstlast(addn);
    //     last->next = new2;
    // }
    // while (addn != NULL)
    // {
    //     printf("%s\n", (char *)addn->content);
    //     addn = addn->next;
    // }
    t_list *res;

    res = ft_lstlast(new2);
    // res = ft_lstlast(addn);
    printf("%s\n", ((char *)res->content));

    return (0);
}