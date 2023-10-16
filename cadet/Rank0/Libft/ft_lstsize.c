#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

int ft_lstsize(t_list *lst)
{
    size_t i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
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

    // while (addn != NULL)
    // {
    //     printf("%s\n", (char *)addn->content);
    //     addn = addn->next;
    // }

    printf("%d\n", ft_lstsize(addn));

    return (0);
}