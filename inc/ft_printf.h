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
#include <inttypes.h>


int ft_printf(char const *format, ...);
char	*ft_nbr_to_str(int n, int *sz);
char	*ft_addchar(char **str, char c);
char	*ft_unbr_to_str(size_t n, int *sz);
char	*ft_char_to_str(char c, int *sz);
void	ft_strnput(char *str, int n);
int		ft_putnbr_lhex(uintmax_t n, char *flags);
int		ft_putnbr_l(intmax_t n, char *flags);
int		ft_putnbr_loct(unsigned long int n, char *flags);
int		ft_putunbr_l(uintmax_t n, char *flags);
int		ft_putwstr(wchar_t *wstr);
int		ft_process_flag(const char **format, va_list vlst);
int		ft_putnbr_printf(int n, char *flags);
int		ft_putstr(char const *s);
int		ft_putunbr(unsigned int n, char *flags);
int		ft_putnbr_hex(unsigned int n, char *flags);
int		ft_putnbr_oct(int n, char *flags);
int		ft_putnbr_mhex(unsigned int n, char *flags);
int		ft_putwchar(wchar_t wc);
short	ft_detect(char *flags, char to_find);
int		ft_getwidth(char *flags);
int		ft_putpercent(char *flags);
void 	ft_handle_null(char *flags, char **padding, char **to_dsp, char **to_del);
int 	ft_handle_wdth(int width, char **padding, char **to_del, char **to_dsp);
int 	ft_padding_right(char **to_dsp, int width, int i);
int		ft_count(char *flags, char to_find);
int		ft_getprec(char *flags);
short	ft_detect_0(char *flags);
int		ft_add_precision(int i, int prec, char **to_dsp);
void	ft_set_to_null(int *i, char **to_dsp);
void	ft_initialise(char **to_dsp, char **padding);
int		ft_add_precision_x(int i, int prec, char **to_dsp, char *flags);
int		ft_handle_wdth_x(int width, char **padding, char **to_del, char **to_dsp);
void	ft_handle_null_x(char *flags, char **padding, char **to_dsp, char **to_del);
int		ft_add_precision_mx(int i, int prec, char **to_dsp, char *flags);
void	ft_handle_null_mx(char *flags, char **padding, char **to_dsp, char **to_del);
int		ft_putnbr_mlhex(uintmax_t n, char *flags);
int		ft_putnbr_p(unsigned long int n, char *flags);

#endif
