/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:27:51 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/04 12:30:47 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>

typedef struct data
{
	int	n;
	int	na;
	int	nb;
	int	error;
	int	*a;
	int	*b;
}				t_data;

/*MAIN*/
int			main(int argc, char **argv);
int			ft_set_two(t_data *d, char **ar);
int			ft_set_more(t_data *d, char **ar);
int			ft_two_arg(char	**ar);
int			ft_more_arg(char **ar);

/*ERROR*/
int			ft_char_error(char *s);
int			ft_int_error(char *s);
int			ft_rep_check(t_data *d);
int			ft_comma_error(char *ar);
int			ft_comma_aux(char *s);

/*SPLIT*/
char		**ft_split(char const *s);
int			ft_strcount(const char *s);
char		*ft_subsplit(char const *s, int i);
void		*ft_del(char **array, int j);
size_t		ft_strlen(const char *s);

/*PUSH_SWAP*/
int			ft_swap(t_data *d);
long int	ft_atoi(char *s);
void		*ft_del_ar(char **ar);
int			ft_check(t_data *d);
void		ft_free(t_data *d);
/* void		ft_print(t_data *d); */

/*OP_A*/
void		ft_free(t_data *d);
void		ft_sa(t_data *d);
void		ft_sb(t_data *d);
void		ft_pb(t_data *d);
void		ft_pa(t_data *d);

/*OP_B*/
void		ft_ra(t_data *d);
void		ft_rb(t_data *d);
void		ft_rra(t_data *d);
void		ft_rrb(t_data *d);
void		ft_dup_mov(t_data *d, int i);

/*MOVE*/
void		ft_move(t_data *d, char *str);

/*GNL*/
char		*get_next_line(int fd);

#endif