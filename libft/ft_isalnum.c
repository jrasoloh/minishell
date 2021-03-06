/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 07:56:23 by jrasoloh          #+#    #+#             */
/*   Updated: 2016/11/20 15:58:13 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if ((c > 47 && c < 58) ||
		(c > 64 && c < 91) ||
		(c > 96 && c < 123))
		return (1);
	return (0);
}
