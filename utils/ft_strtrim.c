/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:33:25 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/11 00:33:28 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static int	char_exists(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set ++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	len;
	char	*end;

	if (!s1 || !set)
		return (0);
	while (char_exists(*s1, (char *)set))
		s1 ++;
	len = ft_strlen(s1);
	end = (char *)s1 + len - 1;
	while (char_exists(*end --, (char *)set))
		len --;
	return (ft_substr((char *) s1, 0, len));
}
