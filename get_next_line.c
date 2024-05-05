/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:20:56 by kaokazak          #+#    #+#             */
/*   Updated: 2024/05/05 01:24:30 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1024

// char *ft_read(int fd, char *cache) {
//     if (cache == NULL) {  // NULL チェック
//         cache = (char *)malloc(sizeof(char) * 1);  // キャッシュを初期化
//         if (!cache) {  // メモリ割り当て失敗
//             return NULL;
//         }
//         cache[0] = '\0';  // ヌル終端
//     }

//     char *buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));  // バッファを確保
//     if (!buf) {  // メモリ割り当て失敗
//         return NULL;
//     }

//     int read_bytes = 1;
//     while (!ft_strchr(cache, '\n') && read_bytes != 0) {  // 改行まで読み込む
//         read_bytes = read(fd, buf, BUFFER_SIZE);
//         if (read_bytes == -1) {  // 読み込みエラー
//             free(buf);
//             free(cache);
//             return NULL;
//         }

//         buf[read_bytes] = '\0';  // ヌル終端
//         char *new_cache = ft_strjoin(cache, buf);  // キャッシュを追加
//         if (!new_cache) {  // メモリ割り当て失敗
//             free(buf);
//             free(cache);
//             return NULL;
//         }

//         cache = new_cache;  // キャッシュを更新
//     }

//     free(buf);  // バッファを解放
//     return cache;  // キャッシュを返す
// }

char *ft_read(int fd, char *cache)
{
    char *buf;
    int read_bytes;
    
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    read_bytes = 1;
    while (!ft_strchr(cache, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, buf, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(buf);
            free(cache);
            return (NULL);
        }
        buf[read_bytes] = '\0';
        cache = ft_strjoin(cache, buf);
    }
    free(buf);
    return (cache);
}

char *ft_get_line(char *cache)
{
    char *line;
    int linelen;
    int i;
    
    if (!cache)
        return (NULL);
    linelen = ft_linelen(cache);
    line = (char *)malloc(sizeof(char) * (linelen + 2));
    if (!line)
        return (NULL);
    i = 0;
    while (i < linelen)
    {
        line[i] = cache[i];
        i++;
    }
    if (cache[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char *ft_save(char *cache)
{
    int i;
    int j;
    char *res;

    if (!cache)
        return (NULL);
    i = ft_linelen(cache);
    if (cache[i] != '\n')
    {
        free(cache);
        return (NULL);    
    }
    res = (char *)malloc(sizeof(char) * (ft_linelen(&cache[i+1]) + 1));
    if (!res)
    {
        free(cache);
        return (NULL);
    }
    i++;
    j = 0;
    while (cache[i] != '\0')
        res[j++] = cache[i++];
    res[j] = '\0';
    free(cache);
    return(res);
}

char *get_next_line(int fd)
{
    char *line;
    static char *cache;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    cache = ft_read(fd, cache);
    if (!cache)
        return (NULL);
    line = ft_get_line(cache);
    if (!line)
        return (NULL);
    cache = ft_save(cache);
    if (!cache)
        return(line);
    return (line);
}
