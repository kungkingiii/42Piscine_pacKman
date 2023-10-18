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
    *lst = 0;
}
