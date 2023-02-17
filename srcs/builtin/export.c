/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:58:18 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 15:21:23 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file export.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief ビルトイン - exportコマンド
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "terminal.h"
#include "ft_printf.h"
#include "libft.h"
#include "ft_pqueue.h"
#include "ft_hashmap.h"

/**
 * @brief ヒープソート用の比較関数。
 *
 * @param p_data1
 * @param p_data2
 * @return int
 */
static int	compare_key(const void *p_data1, const void *p_data2)
{
	const t_env	*env1 = p_data1;
	const t_env	*env2 = p_data2;
	int			res;

	res = ft_strcmp(env1->key, env2->key);
	if (res > 0)
		return (1);
	else if (res < 0)
		return (-1);
	return (0);
}

/**
 * @brief ハッシュテーブルの値を優先度付きキューに格納する。
 *
 *
*/
static int	set_priority_queue(t_hashmap_data *hash_data, void *p_pqueue)
{
	t_env		*env;
	t_pqueue	*pqueue;

	pqueue = (t_pqueue *)p_pqueue;
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (HASHMAP_FAILURE);
	env->key = hash_data->key;
	env->value = hash_data->value;
	ft_priority_queue_push(pqueue, env);
	return (HASHMAP_SUCCESS);
}

/**
 * @brief 環境変数をASCII順に一覧表示する。
 *
 * @param envs
 */
static int	print_sorted_envs(t_hashmap *envs)
{
	t_pqueue	*pqueue;
	t_env		*env;

	pqueue = ft_priority_queue_init(1, compare_key);
	ft_hashmap_iterate(envs, set_priority_queue, pqueue);
	while (!ft_priority_queue_is_empty(pqueue))
	{
		ft_priority_queue_pop(pqueue, (void **)&env);
		if (ft_strcmp(env->key, "_") != 0)
		{
			if (!*env->value)
				ft_printf("declare -x %s\n", env->key);
			else
				ft_printf("declare -x %s=\"%s\"\n", env->key, env->value);
		}
		free(env);
	}
	return (0);
}

/**
 * @brief 文字列の配列を環境変数テーブルに追加する。
 *
 * @param args
 * @param map
 */
static int	insert_envs(char **args, t_shell *msh)
{
	size_t	i;
	t_env	new_env;

	i = 1;
	while (args[i] != NULL)
	{
		new_env = parse_environ(args[i]);
		if (!new_env.key || !new_env.value)
		{
			builtin_perror(MSG_NOT_VALID_ID, args[i], args[0], msh);
			return (1);
		}
		ft_hashmap_insert(msh->envs, new_env.key, new_env.value);
		i++;
	}
	return (0);
}

/**
 * @brief ビルトイン関数：export
 *
 * @param args
 * @param msh
 * @return int
 */
int	builtin_export(char **args, t_shell *msh)
{
	int	argc;

	argc = ft_matrixlen((const char **)args);
	if (argc == 1)
		return (print_sorted_envs(msh->envs));
	return (insert_envs(&args[0], msh));
}
