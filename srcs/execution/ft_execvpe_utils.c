/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execvpe_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:10:42 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 13:11:15 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <sys/stat.h>
#include <sys/types.h>

bool	exists_file(const char *path)
{
	struct stat	st;

	if (stat(path, &st) != 0)
		return (false);
	return (S_ISREG(st.st_mode));
}

bool	is_directory(const char *path)
{
	struct stat	st;

	if (stat(path, &st) != 0)
		return (false);
	return (S_ISDIR(st.st_mode));
}

/**
 * @brief 実行可能なエラーかどうかを判定する。
 * @details EACEESS:アクセス権限がない, ENOENT:パスが存在しない, ESTALE:ファイルハンドルが古い,
 * ENOTDIR: ディレクトリではない, ENODEV: デバイスが存在しない, ETIMEDOUT: 操作がタイムアウトした
 * @return true　上記のエラーである場合
 * @return false 上記以外のエラーである場合
 */
bool	is_expected_error(bool *seen_eaccess)
{
	if (errno == EACCES)
		*seen_eaccess = true;
	if (errno == EACCES || errno == ENOENT
		|| errno == ESTALE || errno == ENOTDIR
		|| errno == ENODEV || errno == ETIMEDOUT)
		return (true);
	return (false);
}
