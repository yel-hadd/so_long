/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_new_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:24:37 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/18 00:37:41 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	isnewline(char c)
{
	if (c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}
