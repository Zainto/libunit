/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:27:55 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/18 02:32:35 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# define TEST(x) ((t_test *)(to_test->data))->x
# include "libft.h"
# define RED "\x1b[031m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[033m"
# define BLUE "\x1b[034m"
# define NC "\x1b[0m"

int 	run_test(t_list **testList);
void	load_test(t_list **lst, char *name, int (*f)(void));

typedef struct	s_test{
	char	*name;
	int		(*test)(void);
}				t_test;
#endif
