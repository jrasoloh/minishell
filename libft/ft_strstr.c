/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 08:12:23 by jrasoloh          #+#    #+#             */
/*   Updated: 2016/11/20 16:15:40 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[j] != '\0')
	{
		while ((str[j] == to_find[i]) && to_find[i] != '\0')
		{
			j++;
			i++;
			if (to_find[i] == '\0')
				return ((char *)&str[j - ft_strlen(to_find)]);
		}
		j = j - i + 1;
		i = 0;
	}
	return (NULL);
}
