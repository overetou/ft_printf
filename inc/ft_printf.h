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
int		ft_putnbr_lhex(long int n);
int		ft_putnbr_l(long int n);
int		ft_putnbr_loct(unsigned long int n, char *flags);
int		ft_putunbr_l(unsigned long int n);
int		ft_putwstr(wchar_t *wstr);
int		ft_process_flag(const char **format, va_list vlst);
int		ft_putnbr_printf(int n, char *flags);
int		ft_putstr(char const *s);
int		ft_putunbr(unsigned int n);
int		ft_putnbr_hex(unsigned int n, char *flags);
int		ft_putnbr_oct(unsigned int n, char *flags);
int		ft_putnbr_mhex(unsigned int n, char *flags);
int		ft_putwchar(wchar_t wc);
short	ft_detect(char *flags, char to_find);
int		ft_getwidth(char *flags);
int		ft_putpercent(char *flags);

#endif
