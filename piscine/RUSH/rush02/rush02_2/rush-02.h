/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:26:59 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/06 21:36:21 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}					t_dict;

int					help_main(char *number_str, char *dict_path);

t_dict				*parse_dict(const char *filename);
int					process_buffer(char *buffer, t_dict **dict);
int					process_line(char *line, t_dict **dict);
int					add_to_dict(t_dict **dict, char *key, char *value);
void				free_dict(t_dict *dict);
int					convert_and_print(t_dict *dict, const char *number_str);
int					print_number(t_dict *dict, const char *num);
int					print_two_digits(t_dict *dict, const char *num);
int					print_three_digits(t_dict *dict, const char *num);
int					print_large_number(t_dict *dict, const char *num, int len);
int					ft_atoi(const char *str);
int					print_word(t_dict *dict, const char *key);
void				ft_strncpy(char *dst, const char *src, int n);
void				ft_strcat(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					create_and_print_scale(t_dict *dict, char *scale,
						int scale_len);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
int					ft_strlen(const char *s);
char				*ft_trim(char *str);
int					is_valid_number(const char *str);
