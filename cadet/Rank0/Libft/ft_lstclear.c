#include <stdio.h>
#include <stdlib.h>

struct s_list
{
    void *content;
    struct s_list *next;
};
typedef struct s_list t_list;

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
    *lst = 0;
}

void del_content(void *content)
{
    free(content);
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

    ft_lstclear(&addn, del_content);

    t_list *res;
    res = addn;
    while (res != NULL)
    {
        printf("%s\n", (char *)res->content);
        res = res->next;
    }

    return (0);
}
