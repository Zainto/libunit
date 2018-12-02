/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 05:38:31 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/02 13:41:17 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "libunit.h"
/*
static void	init_signal_catcher(void)
{
	if (signal(SIGINT, update_prompt) == SIG_ERR)
		ft_putendl("Error occured catching the SIGINT.");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		ft_putendl("Error occured catching the SIGQUIT.");
	if (signal(SIGTSTP, SIG_IGN) == SIG_ERR)
		ft_putendl("Error occured catching the SIGTSTP.");
}
*/
int run_test(void)
{
	int		i;
	int		checker;
	pid_t	process;

	i = 0;
	process = fork();
	if (process == 0)
	{
		wait(&checker);
		printf("process : %d\n", process);
	}
	else  
	{
		printf("process : %d\n", process);
	}
	return (0);
}
