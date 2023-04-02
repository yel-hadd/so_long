/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:31:07 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/02 16:31:28 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			tst_overflow;
	size_t			i;

	i = 0;
	if (!size || !count)
		return (NULL);
	tst_overflow = count * size;
	if (tst_overflow != 0 && tst_overflow / size != count)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (i < size)
		p[i ++] = 0;
	return (p);
}

