/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:16:55 by adardour          #+#    #+#             */
/*   Updated: 2023/02/15 23:12:39 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bb;

	i = 0;
	bb = (unsigned char *)b;
	while (len--)
	{
		bb[i] = (unsigned char)c;
		i++;
	}
	return (bb);
}
