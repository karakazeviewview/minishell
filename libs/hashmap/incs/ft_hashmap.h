/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:28:43 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/23 16:28:43 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHMAP_H
# define FT_HASHMAP_H
# define HASHMAP_SUCCESS 1
# define HASHMAP_FAILURE 0

# define PRIME_1 73
# define PRIME_2 5009
# define REHASH_THRESHOLD 0.8

# include <stdlib.h>
# include <stdbool.h>

/**
 * @brief テーブル内部で用いる構造体
 *
 */
typedef struct s_hashmap_data {
	char	*key;
	void	*value;
	bool	in_use;
}	t_hashmap_data;

/**
 * @brief ハッシュ構造体
 *
 */
typedef struct s_hashmap {
	size_t			nbits;
	size_t			mask;
	t_hashmap_data	*data;
	size_t			len;
	size_t			cap;
	size_t			(*hash)(const void *);
	void			(*destr)(void *);
}	t_hashmap;

/**
 * @brief 初期化の関数
 *
 * @param hash ハッシュ関数。NULLで既定の関数が呼ばれる。
 * @return t_hashmap*　ハッシュマップ構造体
 */
t_hashmap	*ft_hashmap_init(size_t(*hash) \
	(const void *data), void(*destr)(void *));

/**
 * @brief メモリをfreeするための関数。最後に忘れず呼び出す。
 *
 * @param map ハッシュマップ構造体
 */
void		ft_hashmap_delete(t_hashmap **map);

/**
 * @brief　キーとデータを格納する
 *
 * @param map ハッシュマップ構造体
 * @param key　キーとなる文字列（"USER"）
 * @param value 値となるデータのアドレス
 * @return int　成功なら1が返る。キーが重複した場合は0が返る。
 */
int			ft_hashmap_insert(t_hashmap *map, char *key, void *value);

/**
 * @brief　キーに該当するデータを削除する
 *
 * @param map　ハッシュマップ構造体
 * @param key　キーとなる文字列
 * @return int　成功なら1が帰る。キーが見つからない場合は0が返る。
 */
int			ft_hashmap_remove(t_hashmap *map, const char *key);

/**
 * @brief 格納されている各データを第2引数で指定した関数に渡す
 *
 * @param map ハッシュマップ構造体
 * @param f コールバック関数。
 * @param data　コールバック関数に渡すデータ。使用しない場合はNULL。
 * @return int 成功なら1が返る。失敗したら0が返る。
 */
int			ft_hashmap_iterate(t_hashmap *map, \
				int (*f) (t_hashmap_data *, void *), void *data);
void		ft_hashmap_clear(t_hashmap *map);
int			ft_hashmap_resize(t_hashmap *map);
int			ft_hashmap_find(t_hashmap *map, const char *key, void **arg);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *p, int c, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
size_t		hashmap_hash_int(const void *data);

#endif