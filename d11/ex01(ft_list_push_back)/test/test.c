/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										 * подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */


/* ************************************************************************** */

void	ft_putchar(char c)				/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void	ft_putstr(char *str)			/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

/* ************************************************************************** */

void	ft_put_struct(t_list *list)		/* Функция печатает данные одного из элементов каждого экземпляра связаных между собой вглубь экземпляров */
{
	t_list *temp;

	temp = list;
	while(temp)							/* Запускаем цикл, который пройдется вглубь связаных между собой экземпляров структур и напечатает  
										 * данные 'одного из элеменетов' каждого экземпляра связаных между собой структрур */
	{
		ft_putstr((char *)(temp->data));/* Приводим получаемый адрес предпологаемой строки к типу 'char' и отравляем на печать. Так мы печатаем  
										 * данные одного из элеменетов первого экземпляра структуры */
		temp = temp->next; 				/* Для того чтобы дойти до самого последнего эземпляра связанных между собой экземпляров структуры типа
										 * 't_list' мы в указателе 'temp' хранящем адрес текущего экземпляра структуры cохраняем адрес следующего  
										 * экземпляра структуры, хранящегося в одном из элементов текущего экземпляра структуры (указателе структуры 
										 * типа t_list) */
	}
}

/* ************************************************************************** */


t_list		*ft_create_elem(void *data)	/* Функция создает экземпляр структуры типа t_list, заполняет его данными - адресс из указателя data в первый элемент экземпляра
										 * структуры, нулевой адрес во второй элемент экземпляра структуры. И в конце функция его возвращает адрес созданого экземпляра 
										 * структуры типа t_list*/
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адресс выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры адресс принятого в аргументах элемента 
										 * неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}


void	ft_list_push_back(t_list **begin_list, void *data)	/* Функция, которая в последнем экземпляре структуры, среди связаных между собой последовательно 
									 * экземпляров структур, создаст экземпляр структуры типа t_list и сохранит его адрес в элементе(указатель на
									 * экземпляр структуры типа 't_list') последнего экземпляра структуры(который является указателем на экземпляр
									 * структуры типа t_list) */
{
	t_list	*list;					/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */

	if (*begin_list)				/* Проверяем хранится ли в 'указателе' принятом в рагументах функции адресс 'экземпляра структуры типа t_list' */
	{
		list = *begin_list;			/* Сохраняем в указателе на экземпляр структруры типа 't_list' адрес экземпляра структуры типа 't_list'*/
		while (list->next)			/* Запускаем цикл, который пройдеться вглубь связаных между собой экземпляров структур, найдет в этой цепочке адресс последней структуры */
			list = list->next;		/* Для того чтобы дойти до самого последнего экземпляра структуры типа 't_list' мы cохраняем в указателе предыдущей структуры типа 't_list'
									 * адрес хранящийся в одном из элементов(указатель структуры типа t_list) текущего экземпляра структуры типа t_list*/
		list->next = ft_create_elem(data); /* Запишем в одном из элементов(указателе на экземпляр структуры типа 't_list') найденого нами последнего экземпляра в цепочке 
											* экземпляра структуры типа 't_list' адресс нового экземпляра структуры типа 't_list', который содержит данные принятые в
											* аргументах(data) */
	}
	else									/* Если мы дошли до сюда значит в 'указателе на указатель' принятом в рагументах функции не хранится адрес */
		*begin_list = ft_create_elem(data);	/* Тогда мы вызваем функцию по созданию экземпляра структуры, которая запишет в нее данные принятые 'data' в агументах и вернет
											 * адресс который мы сохраним в */
}


int			main(void)
{
	t_list	**tab_list;						/* Обьявим указатель на указатель структуры типа t_list для хранения адреса указателя хранящего адресс экземпляра 
											 * структуры типа t_list */
	t_list	*list;							/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */

	list = ft_create_elem("Bro ");			/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
											 * данных которыем мы ей отправим) и вернет адресс этого экземпляра структуры типа t_list,
											 * который мы сохраним в указателе на экземпляр структуры типа t_list */

	list->next = ft_create_elem("Hey ");	/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
											 * данных которыем мы ей отправим) и вернет адресс этого экземпляра структуры типа t_list 
											 * И сохранит этот адресс в указателе на экземпляр структуры типа t_list, который хранится в одном из элементов 
											 * текущего экземпляра структуры, адрес которой хранится в указателе 'list' */
	tab_list = &list;						/* Сохраняем адресс указателя на экземпляр структуры типа t_list  в указателе на указатель структуры типа t_list */


	ft_list_push_back(tab_list, "Hello");	/* Запускаем функцию, которая в последнем экземпляре структуры, среди связаных между собой последовательно 
											 * экземпляров структур, создаст экземпляр структуры типа t_list и сохранит его адрес в элементе(указатель на
											 * экземпляр структуры типа 't_list') последнего экземпляра структуры(который является указателем на экземпляр
											 * структуры типа t_list) */


	ft_put_struct(*tab_list);				/* Чтобы проверить что у нас получислось мы напечатем данные одного из элементов каждого экземпляра связаных между
											 * собой вглубь экземпляров */
	ft_putchar('\n');						/* Печатаем символ переноса строки для кореектного отображения вывода */

	return (0);								/* Завершаем функцию и возвращаем ноль */
}

	/*	Вот несколько способов чтобы получить данные экземпляра структуры из первого элементам массива указателей "t_list	**tab_list"
		ft_putstr((char *)((*tab_list).next->data));
		ft_putstr((char *)((*(**tab_list).next).data));

		ft_putstr((char *)((*tab_list[0]).next->data));
		ft_putstr((char *)((*(*tab_list[0]).next).data));

		ft_putstr((char *)(tab_list[0][0].next->data));
		ft_putstr((char *)(tab_list[0][0].next[0].data));

		ft_putstr((char *)((*tab_list)->next->data));
		ft_putstr((char *)(tab_list[0]->next->data));
	*/