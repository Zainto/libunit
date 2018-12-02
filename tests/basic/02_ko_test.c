/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ko_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:26:13 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/02 18:47:42 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ko_test(void)
{
	if (ft_strlen("Wesh, bien ou bien?") == 2)
		return (0);
	else
		return (-1);
}
