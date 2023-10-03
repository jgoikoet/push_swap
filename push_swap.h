/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:27:51 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/01 11:27:15 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct start
{
	int	cmin;
	int	cmax;
	int	mina;
	int	maxa;
	int	minb;
	int	maxb;
}				t_start;

typedef struct data
{
	int	n;
	int	na;
	int	nb;
	int	dup;
	int	movn;
	int	movd;
	int	ntmov;
	int	ndar;
	int	ndarr;
	int	ppos;
	int	*a;
	int	*b;
	int	*c;
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
void		ft_ord_3(t_data *d);
void		ft_ord_5(t_data *d);
void		ft_ord(t_data *d);
long int	ft_atoi(char *s);
/* void		ft_print(t_data *d); */

/*PUSH_SWAP_UTILS*/
void		ft_c(t_data *d);
int			ft_pos(t_data *d);
void		ft_mov(t_data *d);
void		ft_mov_u(t_data *d);
void		ft_mov_d(t_data *d);

/*START_SET*/
void		ft_start(t_data *d, t_start *s);
void		ft_mm_a(t_data *d, t_start *s);
void		ft_mm_b(t_data *d, t_start *s);
void		ft_set_range(t_data *d, t_start *s);
int			ft_first_push(t_data *d, t_start *s, int n);

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

/*CHECKS*/
int			ft_check(t_data *d);
int			ft_check_sub(t_data *d);
int			ft_check_min(t_data *d);
int			ft_check_dis(t_data *d, int i);
void		ft_check_mov(t_data *d);

/*CHECK_UTILS*/
void		*ft_del_ar(char **ar);
void		ft_a_need(t_data *d);
int			ft_search_a(t_data *d, int n);
void		ft_a_fin_need(t_data *d);
void		ft_final_swap(t_data *d);

#endif