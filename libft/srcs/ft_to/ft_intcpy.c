/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:15:14 by gehebert          #+#    #+#             */
/*   Updated: 2023/03/15 10:54:13 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intcpy(int *src, int *dst, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
	}
}
