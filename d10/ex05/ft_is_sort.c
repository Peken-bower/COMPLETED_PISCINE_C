/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** *
 *
 * 
 *	• Создайте функцию 'ft_is_sort', которая возвращает 1, если массив отсорти-
 *	рован, и 0, если нет.
 * 
 *	• Функция, заданная в качестве аргумента, должна возвращать отрицательное
 *	целое число, если первый аргумент меньше второго, 0, если они равны или
 *	положительны. целое число для чего-нибудь еще
 * 
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *					int		ft_is_sort(int *tab, int length, int(*f)(int, int))
 * 
 *
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int		i;

	i = 0;
	while (i < (length - 1))
	{
		if (f(tab[i + 1], tab[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			i++;
		else
			i = length;
	}
	if (i == (length - 1))
		return (1);
	i = 0;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			i++;
		else
			i = length;
	}
	if (i == (length - 1))
		return (1);
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	if (length == 0 || length == 1)
		return (1);
	if (f(tab[0], tab[length - 1]) < 0)
	{
		while (i < length - 1)
		{
			if (!(f(tab[i], tab[i + 1]) <= 0))
				return (0);
			i++;
		}
	}
	else
	{
		i = length - 1;
		while (i > 0)
		{
			if (!(f(tab[i], tab[i - 1]) <= 0))
				return (0);
			i--;
		}
	}
	return (1);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int erreur;

	i = 0;
	erreur = 0;
	if (length < 2)
		return (1);
	while (i < length - 1 && !erreur)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			erreur = 1;
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
	}
	return (1);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */