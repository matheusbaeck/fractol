/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:02:23 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/03/03 19:02:24 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_nodo;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			new_nodo = ft_lstlast(*lst);
			new_nodo->next = new;
		}
	}
}
