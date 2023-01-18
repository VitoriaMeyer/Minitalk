/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeyer-s <vmeyer-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:39:41 by vmeyer-s          #+#    #+#             */
/*   Updated: 2022/02/25 10:39:36 by vmeyer-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* strdup allocates memory and creates a copy of (s1) in the (dst) */
/* returns a pointer to it */

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = ft_strlen(s1) + 1;
	dst = malloc(sizeof(char) * i);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, i);
	return (dst);
}
