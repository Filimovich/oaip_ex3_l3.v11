Для каждого x, изменяющегося от a до b с шагом h, найти значения функции Y(x), суммы S(x) и |Y(x) – S(x)| 
и вывести в виде таблицы. Значения a, b, h и n вводятся с клавиатуры. 
Так как значение S(x) является рядом разложения функции Y(x), при правильном решении значения S и Y 
для заданного аргумента x (для тестовых значений исходных данных) должны совпадать в целой части и 
в первых двух-четырех позициях после десятичной точки. 

Работу программы проверить для a = 0,1; b = 1,0; h = 0,1; 
Значение параметра n выбрать так, чтобы |Y(x) – S(x)| < 0.001 (0.0001, 0.00001).

_L3
Составить программу по заданию из п. 3.3.2, в которой нахождение суммы S(x) и функции Y(x) организовать в виде 
отдельных функций, причем расчет функции выполнять не по заданному значению n, 
а до тех пор пока разница очередного значения суммы не будет отличаться от значения функции на 
некоторую величину (погрешность) epsilon, равную, например, 0.001 (0.0001), т. е. до тех пор 
пока |S(x) – Y(x)| >= epsilon. Определить количество шагов вычисления суммы, 
при которых был достигнут указанный результат.

Вариант 11