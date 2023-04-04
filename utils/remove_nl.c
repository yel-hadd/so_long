/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_nl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:20:48 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/02 18:29:43 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*remove_nl(char *s1)
{
	char	*s2;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) - 1;
	s2 = ft_calloc((len + 1), sizeof(char));
	if (!s2)
		return (0);
	ft_memcpy(s2, (void *) s1, (len * sizeof(char)));
	return (s2);
}
