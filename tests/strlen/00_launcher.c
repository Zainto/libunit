/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:43:43 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/02 17:23:00 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "01_basic_test.h"
#include "libunit.h"

int		strlen_launcher(void)
{
	t_list *testList;

	testList = NULL;
	load_test(&testList, "Basic test", basic_test);
	return (run_test(&testList));
}
