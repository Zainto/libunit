/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_catcher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:24:31 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/02 16:25:44 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

static void sigbuss_catch(int signal)
{
	exit(signal);
}

static void sigsegv_catch(int signal)
{
	exit(signal);
}

void	init_signal_catcher(void)
{
	if (signal(SIGBUS, sigbuss_catch) == SIG_ERR)
		ft_putendl("Error occured catching the SIGBUS.");
	if (signal(SIGSEGV, sigsegv_catch) == SIG_ERR)
		ft_putendl("Error occured catching the SIGSEGV.");
}
