/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:43:43 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/02 18:46:53 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"
#include "libunit.h"

int		strlen_launcher(void)
{
	t_list *testList;

	testList = NULL;
	ft_putstr("Basic tests :\n");
	load_test(&testList, "Ok test", ok_test);
	load_test(&testList, "Ko test", ko_test);
	load_test(&testList, "Segmentation fault test", segfault_test);
	load_test(&testList, "Buss error test", buss_test);
	return (run_test(&testList));
}
