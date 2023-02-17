/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:41:30 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/10 10:41:30 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# define DEQUE_SUCCESS 1
# define DEQUE_FAILURE 0

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

// ********** Data structure ********** //
typedef struct s_deque{
	void		*data;
	void		*begin;
	void		*end;
	size_t		len;
	size_t		cap;
	size_t		data_size;
}	t_deque;

// ********** Constructor ********** //
t_deque	*ft_deque_init(size_t data_size, size_t cap);

// ********** Deconstructor ********** //
void	ft_deque_delete(t_deque **deque);

// ********** Modifier ********** //
int		ft_deque_push_front(t_deque *deque, const void *data);
int		ft_deque_push_back(t_deque *deque, const void *data);
int		ft_deque_pop_front(t_deque *deque, void *data);
int		ft_deque_pop_back(t_deque *deque, void *data);
void	ft_deque_clear(t_deque *deque);

// ********** Capacity ********** //
bool	ft_deque_is_full(t_deque *deque);
bool	ft_deque_is_empty(t_deque *deque);
size_t	ft_deque_size(t_deque *deque);
int		ft_deque_realloc(t_deque *deuqe);

// ********** Iterator ********** //
void	*ft_deque_front(t_deque *deque);
void	*ft_deque_back(t_deque *deque);
void	*ft_deque_next(t_deque *deque, void *i, size_t n);
void	*ft_deque_prev(t_deque *deque, void *i, size_t n);
void	ft_deque_foreach(t_deque *deque, void (*func)(void *));

#endif