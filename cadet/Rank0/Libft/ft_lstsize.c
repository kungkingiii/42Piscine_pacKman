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
