/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:31:58 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/02 16:32:34 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*join;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	join = malloc((slen1 + slen2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (*s1)
		*join ++ = *s1 ++;
	while (*s2)
		*join ++ = *s2 ++;
	*join = '\0';
	return (join - slen1 - slen2);
}
