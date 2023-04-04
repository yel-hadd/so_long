/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:06:28 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/02 17:06:41 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	s2 = ft_calloc((ft_strlen((char *)s1) + 1), sizeof(char));
	if (!s2)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		s2[i] = s1[i];
	}
	return (s2);
}
