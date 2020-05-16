/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include "unistd.h"
#include "ft_stock_par.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void				ft_putchar(char c)		/* функция вывода символа */
{
	write(1, &c, 1);
}



void				ft_putstr(char *str)   	/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}



/* Эта функция принимает число int разделяет на кусочки и добавляет каждой к отделенной друг от друга цифре 48 */ 

/* Зачем мы добавляем к числу 48? По тому что если сразу отправить в ft_putchar отделеное число например ft_putchar(5);
 то выведется не символ '5' а с символ '#', который хранится в таблице символов под числом 5 */

/* т.е. чтобы напечетать любое число от 0 до 9 отправляя его в путчар мы:
	либо дожны записать его код вот так ft_putchar(53); 
	либо написать сам символ в кавычках вот так ft_putchar('5'); 

	Но мы будем высчитывать код символа каждую итерацию. Так что вариант нам нужен другой вариант, котрый мы описали ниже.
	Мы будем высчитывать код символа за счет прибавления к числу кода нулевого символа. ВОТ ТАК ft_putchar(5 + 48); где 48 -код нулевого символа, ИЛИ ТАК ft_putchar(5 + '0');
	Программма при приеме этого вычисления(5 + '0'  или 5 + 48) поймет что вы хотите увидеь символ под кодом 53 и наапечатает его.
	(число должнобыть не меньше нуля и не больше 9 иначе вычисление не сработает) */

void				ft_putnbr(int nb)     			 /* Функция вывода числа */
{
	int	temp;						/* создадим переменню для временного хранения данных в нее будем сохранять переменную nb */
	int	size;						/* создадим переменню для хранения размера числа*/

	size = 1;						/* Установим ей начальный размер */

	if (nb < 0)						/* Проверяем яляется полученное нами число в nb отрицательным если число отрицательное то в начале выведем этот '-' символ. */	
	{								/* а содержимое переменной nb делаем положительным с помощью хитрости( nb = -nb) помня из математики что минус на минус дает плюс */
		ft_putchar('-');
		nb = -nb;					
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;						/* сохраним в переменную temp наше число nb для вычисления размера этого числа */

	while ((temp /= 10) > 0)		/* Вычисляем размер числа c помощью накопления количества умноженых десяток друг на друга*/ 
		size *= 10;					/* Если результ деления нашего числа в temp на 10 больше нуля то увеличиваем переменную size умножив ее содержимое на 10 */

									/* НУЖО ПОМНИТЬ что при делении целого числа на целое результат сохраняемый в переменной типа int будет без плавающей точки. 
									 * она автоматически отбрасывается */ /* ПРимер: делим 4  на 10  в итоге результат будет 0.4 а вот сохранится в переменной 
									 * типа int только 0 по тому что все после точки отбрасывается и не записывается в целочисленную переменную. */

	temp = nb;						/* восстановим расстерзаноеделением число в переменную temp оно нам снова понадобится 
									для того чтобы отделить цифры нужного нам числа и напечатать по отдельности */

	while (size)					/* проверяем длинну числа если длинна еще не равна нулю (в результате уменьшения на 10 в цикле) то продолжаем работу цикла */
	{
		ft_putchar((char)((temp / size)) + 48);/* делим число на размер, который у нас получился */   /* тут тоже хитрость */  
									/* допустим размер полученогонами числа 345 получисля равным 100 */ 
									/* деля 345 на 100  мы получим 3.45*/ /* 0.45 отбрасывается по тому что идет приведение к целому числу */ /* и остаеться 3 */
									/* Так вот мы и отделяем 3 от 45 и уже можем ее напечатать тройку прибавив к ней 48, чтоб полуить код символа '3' */

		temp %= size;				/* Здесь с помощь деления числа temp (в примере у нас это 345) по модулю на size (в примере у нас это 100) мы получим 
									оставшуюся часть без первого символа temp ( т.е у нас получится 45. Тройка канула в лету. Так мы ее отбрасываем чтоб потом,
									на новой итерации цикла напечатать 4 и 5 и т.д по мере отделения и печати чисел,  и помере того как size уменьшается */
									
		size /= 10;					/* после то как отделили 3 от 45 в числе 345 и после того как оставили себе только 45 для дальнейшего отделения. число 100 нам больше не нужно.
									Так что делим size на 10 чтобы в след итерации число 45 уже делилось на 10 отдавая 4 на печать, и еще 45 делилось по модулю на 10 сохраняя 5 
									на следующую итерацию, потом снова уменьшение size на 10 (чтобы можно было работать с temp, которое теперь уже хранит 5). 
									Теперь 5 делм на 1 получаем пять отдаем его на печать, 5 деленное по модулю на 1 сохраняет в переменную 0 но это нам уже не нужно.
									Потому что дальше size делится на 10 снова и размер size становится равным нулю. А при след итерации цикл будет проверять размер size 
									и если он равен 0 то цикл завершается */
									/* И жили они долго и счастливо, конец */
	}
}

void	ft_show_tab(struct s_stock_par *par)/* Функция печати нужной нам структуры */
{
	int	i;							/* Обьявляем переменную для счетчика чтобы перемечаться по экземплярам структур */
	int	j;							/* Обьявляем переменную для счетчика чтобы перемечаться от строки к строке и печатать таблицу со строками */

	i = 0;							/* Инициализируем счетчик нулем, чтобы начать работать с нулевой ячейки хранящей адресс самого первого экземпляра */
	while (par[i].str)				/* Если у текущего экземпляра структуры хранится слово то запускаем цикл печатающий все его элементы */ 
	{
		ft_putstr(par[i].copy);		/* Печатаем дубликат строки "str", адрес которой хранится в указателе "copy" */
		ft_putchar('\n');			/* Печатаем символ перехода на новую строку */
		ft_putnbr(par[i].size_param);/* Печатаем число отображающее количество символов в строке "str" */
		ft_putchar('\n');			/* Печатаем символ перехода на новую строку */
		j = 0;						/* Инициализируем счетчик нулем. Он укажет какую строку в на текущей итерации нужно печатать */
		while (par[i].tab[j])		/* Если в текущей ячейке массива строк есть строка то */
		{
			ft_putstr(par[i].tab[j++]);/* Печатаем строку из текущей ячейки массива строк и увеличиваем счетчик переходя к след ячейке */
			ft_putchar('\n');		/* Печатаем символ перехода на новую строку */
		}
		i++;						/* Увеличиваем счетчик переходя к след экземпляру структуры */
	}
}

/*#############################################################################*/

int					ft_isspace(char c)		/* Функция узнает является ли наш символ разделителем между словами */
{
	return (c == ' ' || c == '\t' || c == '\n');/* Если наш символ это пробел или табуляция, или концом строки */
												 /* То завершаем функцию и возвращаем '1' */ 
												 /* Если это какой то др символ то завершаем функцию и возвращаем '0' */
}



int					ft_wordcount(char *str) /* Функция считает количество слов в строке */
{
	int		words;				/* Обьявляем переменную для хранения количества найденых слов */

	words = 0;					/* Инициализируем переменную хранящую количество найденых слов нулем */
	while (*str)				/* Запускаем цикл который пройдеться по строке и посчитает слова пока не дойдет до конца строки */
	{
		if (!(words) && !(ft_isspace(*str)))/* Если нам не встречались символы слова и эта ячейка содержит не пустой символ */ 
			words++;			/* Значит мы встретили первое слово. Прибавляем к переменной один */
		else if (ft_isspace(*(str - 1)) && !(ft_isspace(*str)))/* Если в этой ячейке ячейке хранится первая буква слова */
			words++;			/* Значит мы встретили еще одно слово. Прибавляем к переменной один */
		str++;					/* Проходимся по всему массиву символо(строке) пока не дойдем до последней */
	}
	return (words);				/* Завершаем функцию и возвращаем количество слов в строке */
}



int					ft_wordlen(char *str)	/* Функция вычисляет размер первого слова найденого в строке */
{
	int		len;				/* Обьявляем переменную для хранения размера слова */

	len = 0;					/* Инициализируем переменную хранящую размер слова нулем */
	while (ft_isspace(*str))	/* Цикл пропустит символы в начале массива, которые не являются словом */
		str++;
	while (*str && !(ft_isspace(*str)))/* Цикл который будет считать каждый символ пока не закончится слово */
	{
		str++;
		len++;
	}
	return (len);				/* Завершаем функцию и возвращаем размер слова */
}



char				**ft_split_whitespaces(char *str)/* функция разбирает строку на отдельные слова создавая для них массивы символов, 
											  * записывает адреса созданных массивов в массив указателлей на указатели и 
											  * возвращает адресс массива указателей на указатели */
{
	int		i;					/* Обьявляем переменную для счетчика чтоб перемечаться по созданным строкам */
	int		j;					/* Обьявляем переменную для счетчика чтоб перемечаться по созданному массиву символов */
	char	**arr;				/* Обьявляем указатель на указатель в который мы сохраним адресс выдленой памяти с адресами массивов */
	int		words;				/* Обьявим переменную для хранения вычесленного количества строк */

	words = ft_wordcount(str);	/* Вызываем функцию по вычислению количества слов в строке и записываем результат в переменную */
	i = 0;						/* Инициализируем счетчик 'i' нулем чтобы начать работу с нулевого массива */
	if (!str || (((arr = (char **)malloc(sizeof(char*) * (words + 1)))) == ((void *)0)))/* Выделяем память нужного размера
								 * под указатели на адресам массивов которые будут содержать строки со словами.
								 * И проверяем прошло ли выделение памяти без ошибок. */ 
		return ((void*)0);		/* Если были проблемы то завершаем функцию и возвращаем нулевой указатель */
	/* Если выше всё прошло удачно то мы переходим к созданию памяти для каждого слова */
	while (i < words)			/* Этот цикл будет создавать память под слова и записывать символы этих слов в выделеную память  */
	{
		if ((arr[i] = (char *)malloc(sizeof(char) * (ft_wordlen(str) + 1))) == ((void *)0))/* Выделяем память под указатели(их будет
								 * столько же сколько слов нашла функция ft_wordcount в строке, плюс один указатель под завершающий
								 * - нулевой указатель). В эти указатели мы поместим адреса каждого добытого слова помещеных в строку
								 * (массивов символов). И проверяем прошло ли выделение памяти без ошибок. */ 
			return ((void*)0);	/* Если что то пошло не так то завершаем функцию и возвращаем нулевой указатель */
		j = 0;					/* Инициализируем счетчик 'j' нулем чтобы начать работу с нулевой ячейки выбранного массива */
		while (ft_isspace(*str))/* Пропускаем ячейки с символами которые не являються частью слова */
			str++;				/* чтобы добраться до ячейки массива где начинается слова */
		while (*str && !(ft_isspace(*str)))/* Пока мы не дошли символа конца строки или не встретили пустой символ */
			arr[i][j++] = *str++;/* Копируем символы найденого текущего слова в новый массив */
		arr[i][j] = '\0';		/* После слова в конце массива добавляем символ конца массива */
		i++;					/* Переходим к след строке чтобы скопировать туда след слово, которое мы найдем с помощью
								 * str, в котором сохранилась информация о позиции ячейки после прошлого слова. 
								 * Эту позицию мы и используем как точку отсчета для поиска нового(последующего) слова */
	}
	arr[i] = ((void*)0);		/* В конце массива указателей на указатели, хранящего адреса строк, добавляем нулевой адрес как 
								 * символ конца этого массива указателей на указатели */
	return (arr);				/* Заавершаем функцию и возвращаем адресс массива с указателями на указатели(адреса массивов со
								 * словами) */
}

/*#############################################################################*/


struct s_stock_par	*ft_param_to_tab(int ac, char **av)	/* Функция разбирает каждую строку массива строк на состовляющие(делает копию строки, получает размер строки,
								 * отделяет слова в строке друг от друга и сохраняет их отдельно в массив строк), а потом сохраняет получены данные по экземплярам и в
								 * самом конце возвращает сам адрес массива с экземплярами структуры "struct s_stock_par" */
{
	int			i;				/* Обьявляем переменную для счетчика, чтобы перемечаться по экземплярам структур и строкам массива строк "av" */
	int			j;				/* Обьявляем переменную для счетчика, которую используем для подсчета выбранной строки и для перемещения по символам выбраной строки */
	t_stock_par	*ret;			/* Создаем указатель на экземпляр структуры "t_stock_par"(struct s_stock_par), который будет хранить адрес выделеной памяти */

	if ((ret = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1))) == ((void *)0))/* выделяем память типа "t_stock_par"(struct s_stock_par) под массив экземпляров 
								 * на столько же экземпляров сколько у нас строк храниться в массиве строк "av" и плюс один для завершающего нуля */
		return ((void *)0);		/* Если что то пошло не так то возвращаем указатель типа NULL и завершаем функцию */
	i = 0;						/* Инициализируем счетчик i нулем чтобы начать разбор каждой строки массива строк на состовляющие части с нулевой ячейки и записывать 
								 * извлеченные данные в экземпляры структуры типа "t_stock_par"(struct s_stock_par) начиная с нулевого экземпляра */
	while (i < ac)				/* Запускаем цикл который разберет каждую строку из массива строк и заполнит этим каждый экземпляр типа t_stock_par"(struct s_stock_par) */
	{
		j = 0;					/* Инициализируем 'j' нулем для подсчета туда количества символов текущей строки*/
		while (av[i][j])		/* Запускаем цикл подсчета количества симолов в строке */
			j++;
		ret[i].size_param = j;	/* Сохраняем найденое количество символов в переменной "size_param" текущего экземпляра типа t_stock_par"(struct s_stock_par) */
		ret[i].str = av[i];		/* Сохраняем адрес текущей строки в указателе "str" текущего экземпляра типа t_stock_par"(struct s_stock_par) */
		if((ret[i].copy = (char *)malloc(sizeof(char) * (ret[i].size_param + 1))) == ((void *)0))/* Выделяем память для копирование текущей строки и сохраняем адресс 
								 * выделеной памяти в указателе "copy" текущего экземпляра типа t_stock_par"(struct s_stock_par) */
			return ((void *)0);	/* Если что то пошло не так то возвращаем указатель типа NULL и завершаем функцию */
		j = 0;					/* Записываем ноль в перменную 'j' для использования её как счетчика при копировании текущей строки в выделеную память */
		while (j < ret[i].size_param)/* Запускаем цикл, который скопирует текущую строку в выделеную для нее память */
		{
			ret[i].copy[j] = av[i][j];/* Копируем каждый символ из текущей строки в выделеную память */
			j++;					  /* увеличиваем счетчик для перехода к след ячейке с символом */
		}
		ret[i].copy[j] = '\0';	/* после создания дубликата строки в конце добавляем завершающий символ нуля */
		ret[i].tab = ft_split_whitespaces(av[i]);/* Запускаем функцию которая разберет текущую строку на слова */
		i++;					/* увеличиваем счетчик для перехода к след экземпляру типа t_stock_par"(struct s_stock_par) */
	}
	ret[i].str = ((void *)0);	/* Сохраняем "нулевой указатель" в указателе "str" последнего экземпляра типа t_stock_par"(struct s_stock_par) как символ того что этот
								 * экземпляр пустой и создан как */ 
	return (ret);				/* Возвращаем адрес нулевого экземпляра полученых и завершаем функцию */
}

int					main(int argc, char **argv)
{
	struct s_stock_par *a;		/* Создаем указатель на экземпляр структуры типа t_stock_par"(struct s_stock_par) */
	a = ft_param_to_tab(argc, argv);/* Отправляем в аргументы функции - число с отображающее количество аргументов отправленное в программу и адресс массива со строками
								 * полученые программой вместе с именем программы */
	ft_show_tab(a);				/* Печатаем полученый в указатель  адресс массива экземпляров типа t_stock_par"(struct s_stock_par) содержащий аргументы программы разложеные на составляющие */
	return (0);					/* Возвращаем ноль и завершаем программу */
}