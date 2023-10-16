#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

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
    // char *data = "Hello, World!";
    int d = 50;
    // char d = 'h';
    t_list *new;

    new = ft_lstnew(&d);

    if (new)
    {
        printf("New node content: %d\n", *((unsigned int *)new->content));
    }
    else
    {
        printf("Failed to create a new node.\n");
    }

    return (0);
}