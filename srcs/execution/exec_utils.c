/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:22:53 by event             #+#    #+#             */
/*   Updated: 2023/01/27 01:22:54 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_utils.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief executionに付随するヘルパー関数群（主に型変換に用いる）。
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "execution.h"
#include "ft_snprintf.h"

/**
 * @brief ベクター型を文字列の配列に変換する
 *
 * @param src
 * @return char**
 */
char	**convert_vector_to_array(t_vector *src)
{
	char	**arr;
	size_t	len;
	t_env	env;
	size_t	i;

	len = 0;
	arr = (char **)ft_xmalloc(sizeof(char *) * (ft_vector_size(src) + 1));
	i = 0;
	while (!ft_vector_is_empty(src))
	{
		if (!ft_vector_pop_back(src, &env))
			return (NULL);
		if (env.key && env.value)
		{
			len = ft_strlen(env.key) + ft_strlen(env.value) + 1 + 1;
			arr[i] = (char *)ft_xmalloc(sizeof(char) * len);
			ft_snprintf(arr[i], len, "%s=%s", env.key, env.value);
		}
		free(env.key);
		free(env.value);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

/**
 * @brief コールバック用関数：ハッシュテーブルの各値をベクター型に格納する
 *
 * @param map_data
 * @param p_envs
 * @return int
 */
static int	set_env(t_hashmap_data *map_data, void *p_envs)
{
	t_vector	*envs;
	t_env		*env;

	envs = (t_vector *)p_envs;
	env = (t_env *)ft_xmalloc(sizeof(t_env));
	env->key = map_data->key;
	env->value = map_data->value;
	return (ft_vector_push_back(envs, env));
}

/**
 * @brief ハッシュテーブルを文字列の配列に変換する
 *
 * @param envs
 * @return char**
 */
char	**construct_environ(t_hashmap *envs)
{
	t_vector	*tmp_envs;
	char		**envp;

	tmp_envs = ft_vector_init(sizeof(t_env), 64);
	ft_hashmap_iterate(envs, set_env, tmp_envs);
	envp = convert_vector_to_array(tmp_envs);
	ft_vector_delete(&tmp_envs);
	ft_hashmap_delete(&envs);
	return (envp);
}
