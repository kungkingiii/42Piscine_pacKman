#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

void add_text(void *content)
{
    char *text;

    text = (char *)content;
    printf("%s\n", text);
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
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

    ft_lstiter(addn, add_text);

    t_list *res;
    res = addn;
    while (res != NULL)
    {
        printf("%s\n", (char *)res->content);
        res = res->next;
    }

    return (0);
}
