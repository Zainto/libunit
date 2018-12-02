/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 05:38:31 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/02 16:31:39 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libunit.h"

static t_list	*parent_manager(t_list	*to_test)
{
	int		checker;

	wait(&checker);
	if (WIFSIGNALED)
	{
		if (WTERMSIG(checker) == SIGSEGV)
			ft_putendl("[SEGV]");
		if (WTERMSIG(checker) == SIGBUS)
			ft_putendl("[BUSE]");
	}
	else if (WIFEXITED(checker))
	{
		if (WEXITSTATUS(checker) == 0)
			ft_putendl("[OK]");
		if (WEXITSTATUS(checker) == -1)
			ft_putendl("[KO]");
	}
	return (to_test->next);
}

void	load_test(t_list **lst, char *name, void (*f)(void))
{
	t_list	*current;
	t_test	tmp;

	tmp.name = ft_strdup(name);
	tmp.test = f;
	current = *lst;
	ft_lstaddback(lst, ft_lstnew(&tmp, sizeof(t_test)));
	return;
}

int run_test(t_list **testList)
{
	t_list	*to_test;
	pid_t	process;

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
			if (TEST(test()) == 0)
				exit(EXIT_SUCCESS);
			else
				exit(EXIT_FAILURE);
		}
	}
	return (0);
}
