/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:26:56 by overetou          #+#    #+#             */
/*   Updated: 2017/12/22 19:44:21 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"

int ft_printf(char const *format, ...);
char	*ft_nbr_to_str(int n, int *sz);
char	*ft_addchar(char **str, char c);
char	*ft_unbr_to_str(size_t n, int *sz);
char	*ft_char_to_str(char c, int *sz);
void	ft_strnput(char *str, int n);

#endif
