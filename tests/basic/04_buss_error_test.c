/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_buss_error_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:33:06 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/02 18:46:38 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		buss_test(void)
{
	if (ft_strcpy("Salut", "tocard"))
		return (0);
	else
		return (-1);
}
