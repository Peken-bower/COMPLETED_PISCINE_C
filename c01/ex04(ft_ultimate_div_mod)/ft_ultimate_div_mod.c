/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/02/16 23:31:06 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex04/
**  Файлы для сдачи: ft_ultimate_div_mod.c	
**  Разрешенные функции: отсутствуют
**
** ************************************************************************** **
**
**
**  - Эта функция делит параметры 'a' на 'b'. результат этого деления 
**  сохраняется в 'int', указанном 'a'. Остаток от деления хранится в 
**	переменной типа 'int' указывает на 'b'.
**
**
**  - Вот как это должно быть обьявлено:
**
**        void	ft_ultimate_div_mod(int *a, int *b);
**
**
** ************************************************************************** **
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
/* ************************************************************************** */



void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}




/* ************************************************************************** */
/* ************************************************************************** */


void		ft_ultimate_div_mod(int *a, int *b)
{
	int t;

	if (b != 0)
	{
		t = *a;
		*a = *a / *b;
		*b = t % *b;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int c;
	int d;

	c = *a;
	d = *b;
	*a = c / d;
	*b = c % d;
}




/* ************************************************************************** */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int div;
	int mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}




/* ************************************************************************** */
/* ************************************************************************** */


void	ft_ultimate_div_mod(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a /= *b;
	*b = tmp % *b;
}



/* ************************************************************************** */
/* ************************************************************************** */
