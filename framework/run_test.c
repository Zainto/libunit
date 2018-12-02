/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 05:38:31 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/02 14:49:09 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "libunit.h"
#include <string.h>

static void sigbuss_catch(int signal)
{
	printf("Signal is = %d\n", signal);
	ft_putendl("Sigbuss caught");
	exit(EXIT_FAILURE);
}


static void sigsegv_catch(int signal)
{
	printf("Signal is = %d\n", signal);
	ft_putendl("Segfault caught");
	exit(EXIT_FAILURE);
}

static void	init_signal_catcher(void)
{
	if (signal(SIGBUS, sigbuss_catch) == SIG_ERR)
		ft_putendl("Error occured catching the SIGBUS.");
	if (signal(SIGSEGV, sigsegv_catch) == SIG_ERR)
		ft_putendl("Error occured catching the SIGSEGV.");
}


int run_test(void)
{
	int		i;
	int		checker;
	char	*buss_error = "Yo";
	char	*segv = NULL;
	pid_t	process;

	i = 0;
	while (i < 2)
	{
		init_signal_catcher();
		i++;
		process = fork();
		if (process == 0)
		{
			wait(&checker);
			printf("process : %d\n", process);
		}
		else if (i == 1) 
			*buss_error = 'c';	
		else if (i == 2)
		{
			ft_putstr("Ready to segv\n");
			strlen(segv);
		}
	}
	return (0);
}
