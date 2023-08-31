/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:33:44 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/09 15:12:45 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *toto)
{
	t_list	*list1;

	list1 = malloc(sizeof(t_list));
	if (!list1)
		return (NULL);
	list1->next = NULL;
	list1->content = toto;
	list1->id = 0;
	list1->x = 0;
	list1->y = 0;
	list1->is_open = false;
	return (list1);
}

/*int	main()
{
	t_list *str;
	str = ft_lstnew("une dflgdfgdnfhdnghfghkjphrase");
	printf("%s\n", (char *)str->content);
	return (0);
}*/
