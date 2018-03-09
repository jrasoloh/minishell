/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:15:26 by jrasoloh          #+#    #+#             */
/*   Updated: 2016/11/30 21:20:03 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if ((str = (void *)malloc(sizeof(*str) * size)) == NULL)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}
