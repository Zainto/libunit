/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:27:55 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/02 16:29:14 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# define TEST(x) ((t_test *)(to_test->data))->x
# include "libft.h"

int 	run_test(void);
void	init_signal_catcher(void);
void	load_test(t_list **lst, char *name, void (*f)(void));

typedef struct	s_test{
	char	*name;
	int		(*test)(void);
}				t_test;
#endif
