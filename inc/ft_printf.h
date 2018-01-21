/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:26:56 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 15:44:22 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <inttypes.h>

int		ft_printf(char const *format, ...);
char	*ft_nbr_to_str(int n, int *sz);
char	*ft_addchar(char **str, char c);
char	*ft_unbr_to_str(size_t n, int *sz);
char	*ft_char_to_str(char c, int *sz);
void	ft_strnput(char *str, int n);
int		ft_pn_lhex(uintmax_t n, char *flags);
int		ft_pn_l(intmax_t n, char *flags);
int		ft_pn_loct(unsigned long int n, char *flags);
int		ft_pun_l(uintmax_t n, char *flags);
int		ft_sort_di(char *flags, va_list vlst);
int		ft_sort_u(char *flags, va_list vlst);
int		ft_sort_o(char *flags, va_list vlst);
int		ft_sort_x(char *flags, va_list vlst);
int		ft_sort_xx(char *flags, va_list vlst);
void	ft_putwstrn(wchar_t *wstr, int n);
int		ft_process_flag(const char **format, va_list vlst);
int		ft_pn_printf(int n, char *flags);
int		ft_pun(unsigned int n, char *flags);
int		ft_pn_hex(unsigned int n, char *flags);
int		ft_pn_oct(unsigned int n, char *flags);
int		ft_pn_mhex(unsigned int n, char *flags);
int		ft_putwchar(wchar_t wc);
short	ft_detect(char *flags, char to_find);
int		ft_getwidth(char *flags);
int		ft_putpercent(char *flags);
void	ft_handle_null(char *flags, char **pad, char **dsp, char **del);
int		ft_handle_wdth(int width, char **pad, char **del, char **dsp);
int		ft_pad_right(char **dsp, int width, int i);
int		ft_count(char *flags, char to_find);
int		ft_getprec(char *flags);
short	ft_detect_0(char *flags);
int		ft_add_precision(int i, int prec, char **dsp);
void	ft_set_to_null(int *i, char **dsp);
void	ft_initialise(char **dsp, char **pad);
int		ft_addprec_x(int i, int prec, char **dsp, char *flags);
int		ft_handle_wdth_x(int width, char **pad, char **del, char **dsp);
void	ft_handle_null_x(char *flags, char **pad, char **dsp, char **del);
int		ft_add_prec_mx(int i, int prec, char **dsp, char *flags);
void	ft_handle_null_mx(char *flags, char **pad, char **dsp, char **del);
int		ft_pn_mlhex(uintmax_t n, char *flags);
int		ft_pn_p(unsigned long int n, char *flags);
int		ft_putchar_printf(char c, char *flags);
void	ft_handle_width_c(char **pad, char **dsp, int *i, int width);
int		ft_putstr_printf(char *str, char *flags);
int		ft_putwstr_printf(wchar_t *wstr, char *flags);
char	*ft_add_bfr(char *to_add, char **del);
short	ft_detect_0ud(char *flags);
int		ft_handle_wchar(wchar_t wc, char *flags);
int		ft_sort_c(char *flags, va_list vlst);
int		ft_sort_s(char *flags, va_list vlst);
char	ft_find_conv(const char *format);
int		ft_process_conv(char conv, va_list vlst, char *flags);

#endif
