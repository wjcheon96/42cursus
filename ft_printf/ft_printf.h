/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 05:25:54 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/26 11:22:26 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

char	*ft_itoa_base(unsigned long long int n, char *base);
size_t	ft_strlen(const char *s);
int		ft_print_char(int ap);
int		ft_print_str(char *ap);
int		ft_print_ptr(uintptr_t ap);
int		ft_print_int(long long ap);
int		ft_print_uint(unsigned int ap, char type);
int		ft_printf(const char *format, ...);

#endif
