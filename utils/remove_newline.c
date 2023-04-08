/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_newline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:05:20 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/08 18:08:18 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char*	remove_newline(char* str)
{
	size_t	len;
	char*	new_str;

	len = ft_strlen(str);
	if (len > 0 && str[len-1] == '\n')
	{
		new_str = ft_calloc(len, sizeof(char));
		if (new_str == NULL)
			return NULL;
		ft_memcpy(new_str, str, len-1);
		return new_str;
	}
	else if (len > 0)
		return (ft_strdup(str));
	else
		return (ft_strdup("X"));
}
