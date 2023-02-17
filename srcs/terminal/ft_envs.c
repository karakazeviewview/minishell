/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:19:00 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/11 21:31:08 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @file ft_envs.c
 * @brief 環境変数の登録・更新・削除・取得
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "terminal.h"

/**
 * @brief キーに該当する環境変数をテーブルから取得する。
 *
 * @param key キーとなる環境変数名
 * @param envs　環境変数テーブル
 * @return char*　取得した環境変数の値
 */
char	*ft_getenv(const char *key, t_hashmap *envs)
{
	char	*p_value;

	if (!ft_hashmap_find(envs, key, (void **)&p_value))
		return (NULL);
	return (p_value);
}

/**
 * @brief 環境変数を値を更新する（キーが重複する場合は上書きする）。
 *
 * @param env　更新するキーと値の値構造体
 * @param envs　環境変数テーブル
 * @return int　更新に成功した場合は0を、失敗した場合は-1を返す。
 */
int	ft_putenv(t_env *env, t_hashmap *envs)
{
	int	ok;

	ok = ft_hashmap_insert(envs, env->key, env->value);
	if (!ok)
		return (-1);
	return (0);
}

/**
 * @brief 環境変数の値を追加する。
 *
 * @param env　追加するキーと値の構造体
 * @param envs　環境変数のテーブル
 * @param overwrite 0の場合は既存のキーがない場合のみ更新。1の場合は強制的に上書き更新。
 * @return int
 */
int	ft_setenv(t_env *env, t_hashmap *envs, int overwrite)
{
	int	ok;

	if (overwrite == 0)
	{
		ok = ft_hashmap_find(envs, env->key, NULL);
		if (!ok)
			return (0);
	}
	return (ft_putenv(env, envs));
}

/**
 * @brief 環境変数の値を削除する。
 *
 * @param key　削除する環境変数のキー
 * @param envs　環境変数のテーブル
 * @return int
 */
int	ft_unsetenv(const char *key, t_hashmap *envs)
{
	int	ok;

	ok = ft_hashmap_remove(envs, key);
	if (!ok)
		return (-1);
	return (0);
}
