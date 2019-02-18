/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 05:38:31 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/18 01:53:27 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include "libunit.h"


static void		signal_catch(int signal)
{
	if (WTERMSIG(signal) == SIGSEGV)
		ft_putendl(RED" [SEGV]"NC);
	if (WTERMSIG(signal) == SIGBUS)
		ft_putendl(RED" [BUSE]"NC);
	exit(3);
}

static void		init_signal_catcher(void)
{
	if (signal(SIGBUS, signal_catch) == SIG_ERR)
		ft_putendl("Error occured catching the SIGBUS.");
	if (signal(SIGSEGV, signal_catch) == SIG_ERR)
		ft_putendl("Error occured catching the SIGSEGV.");
}

static t_list	*parent_manager(t_list	*to_test)
{
	int		checker;

	wait(&checker);
	if (WIFEXITED(checker) && WEXITSTATUS(checker) != 3)
	{
		if (WEXITSTATUS(checker) == 0)
			ft_putendl(GREEN" [OK]"NC);
		else 
			ft_putendl(RED" [KO]"NC);
	}
	return (to_test->next);
}

void			load_test(t_list **lst, char *name, int (*f)(void))
{
	t_list	*current;
	t_test	tmp;

	tmp.name = ft_strdup(name);
	tmp.test = f;
	current = *lst;
	ft_lstaddback(lst, ft_lstnew(&tmp, sizeof(t_test)));
	return;
}

int				run_test(t_list **testList)
{
	t_list	*to_test;
	pid_t	process;
	int		checker;

	to_test = *testList;
	init_signal_catcher();
	while (to_test)
	{
		process = fork();
		if (process != 0)
			to_test = parent_manager(to_test);
		else
		{
			ft_putstr("> ");
			ft_putstr(TEST(name));
			checker = TEST(test());
			if (checker == 0)
				exit(EXIT_SUCCESS);
			else
				exit(EXIT_FAILURE);
		}
	}
	return (0);
}
