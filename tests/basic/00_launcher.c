/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:43:43 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/18 03:51:00 by cedricmpa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"
#include "libft.h"

int		strlen_launcher(void)
{
	t_stack tests;

	ft_stckinit(&tests);;
	ft_putstr("Basic tests :\n");
	load_test(&tests, "Ok test", ok_test);
	load_test(&tests, "Ko test", ko_test);
	load_test(&tests, "Segmentation fault test", segfault_test);
	load_test(&tests, "Buss error test", buss_test);
	return (run_test(&tests));
}
