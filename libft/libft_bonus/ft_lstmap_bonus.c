
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;
    t_list  *current_node;

    if(f == NULL || del == NULL)
        return(NULL);
    new_list = NULL;
    current_node = NULL;
    while (lst)
    {
        void    *new_content;
        t_list  *new_node;
        
        new_content = f(lst->content);
        new_node = ft_lstnew(new_content);
        if (!new_node)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        if (!new_list)
            new_list = new_node;
        else
            current_node->next = new_node;
        current_node = new_node;
        lst = lst->next;
    }
    return (new_list);
}