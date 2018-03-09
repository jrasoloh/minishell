/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:50:41 by jrasoloh          #+#    #+#             */
/*   Updated: 2016/11/30 23:47:58 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		len2;
	const char	*tmp1;
	const char	*tmp2;

	if (*little == '\0')
		return ((char *)big);
	len2 = ft_strlen(little);
	while (*big && len >= len2)
	{
		tmp1 = big;
		tmp2 = little;
		if (ft_strncmp(tmp1, tmp2, len2) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
