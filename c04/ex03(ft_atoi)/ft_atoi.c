/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/02/16 23:37:55 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* **************************************************************************
**  
**  
**  - Напишите функцию, которая преобразует начальную часть строки, на которую
**  указывает 'str', в ее представление 'int'
**
**  - Строка может начинаться с произвольного количества пробелов (как определено
**  с помощью isspace (3)).
**
**  - За строкой может следовать произвольное количество знаков '+' и '-', 
**  знак '-' изменит знак возвращаемого целого числа 'int' в зависимости от 
**  количества '-' нечетных или четных.
**
**  - Наконец, за строкой могут следовать любые числа с основанием 10(десятичные).
**
**  - Ваша функция должна читать строку до тех пор, пока она не перестанет следовать
**  правилам и не вернет число, найденное до сих пор.
**
**  - Не стоит заботиться о переполнении или опустошении. В этом случае результат
**  может быть неопределенным.
**
**  Вот пример программы, которая печатает возвращаемое значение atoi:
--------------------------------------------------------------------------------
    
    $>./a.out "  ---+--+1234ab567"
    -1234
    $>
    
--------------------------------------------------------------------------------
**  
**
**  - Вот как это должно быть обьявлено:
**
**       int	ft_atoi(char *str);
**
**  
** ************************************************************************** **
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
/* ************************************************************************** */


int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-')
		sign = -1;
	while ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + ((int)*str - '0');
		str++;
	}
	return (num * sign);
}



/* ************************************************************************** */
/* ************************************************************************** */


int			ft_atoi(char *str)
{
	int		v;
	int		n;

	n = 0;
	if (*str == '-')
	{
		str++;
		n = 1;
	}
	v = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			v = (v * 10) + (*str - '0');
		else
			return (0);
		str++;
	}
	return ((v > 0 && n) ? -v : v);
}


/* ************************************************************************** */
/* ************************************************************************** */


int	ft_atoi(char *str)
{
	int	x;
	int total;
	int is_negative;

	is_negative = 0;
	x = 0;
	total = 0;
	while (str[x] == ' ' || str[x] == '\n' || str[x] == '\r' || str[x] == '\f'
			|| str[x] == '\t' || str[x] == '\v' || str[x] == '+')
		x++;
	if (str[x] == '-')
	{
		is_negative = 1;
		x++;
	}
	while ((str[x] == '-') || (str[x] == '+'))
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		total *= 10;
		total += ((int)str[x] - 48);
		x++;
	}
	if (is_negative)
		return (-total);
	else
		return (total);
}


/* ************************************************************************** */
/* ************************************************************************** */


int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str[i])
		return (0);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r' \
		|| str[i] == '\f' || str[i] == ' ')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - 48);
	return (nbr * sign);
}


/* ************************************************************************** */
/* ************************************************************************** */
