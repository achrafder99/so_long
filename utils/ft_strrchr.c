/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:49:35 by adardour          #+#    #+#             */
/*   Updated: 2023/02/08 14:07:43 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	if (c == 0)
		return ((char *)s + length);
	while (length--)
	{
		if (s[length] == (unsigned char)c)
			return ((char *)s + length);
	}
	return (NULL);
}
