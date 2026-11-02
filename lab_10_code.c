#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>
#include <math.h>
#define math_e 2.71828182846
#define math_pi 3.14159265359

double fa(double x);
double fb(double x);
double numb_task1(int x);
double sin_N(double x, int N); 
int fact(int x); // функция нахождения факториала числа x
double sin_eps(double x, double eps);
double area_triangle(float a);
char treug(char symb, int a);

int main()
{
	setlocale(LC_ALL, "");
	int numb_task;
	printf("Выберите задание:\n1. Задание 1\n2. Задание 2\n3. Задание 3 (Домашнее)\n");
	scanf("%d", &numb_task);
	switch (numb_task)
	{
	case 1:
	{
		double x, y;
		int numb;
		printf("\tЗадание 1\n");
		printf("Введите x:\n");
		scanf("%lf", &x);
		printf("Выберите действие:\n");
		printf("1. Рассчитать значение функции fa(x)\n");
		printf("2. Рассчитать значение функции fb(x)\n");
		printf("3. Рассчитать произведение значений функций\n");
		printf("4. Рассчитать разность квадратов значений функций\n");
		printf("5. Рассчитать удвоенную сумму значений функций\n");
		scanf("%d", &numb);
		if (numb_task1(numb) == -0.00000001) printf("Неизвестный номер действия\n");
		else printf("%lf", numb_task1(numb));
		break;
	}
	case 2:
	{
		double x;
		int N;
		double eps;
		printf("\n\n\tЗадание 2\n");
		printf("Способ 1\n");
		printf("Введите значение x:\n");
		scanf("%lf", &x);
		printf("Синуc %lf равен %lf (вычисленно с помощью sin(x) из math.h)\n", x, sin(x));
		printf("Способ 2\n");
		printf("Введите число суммируемых k-ых членов ряда:\n");
		scanf("%d", &N);
		printf("       N |   sin_N  | отколнение\n");
		for (int i = 1; i <= N; i++)
		{
			printf("    %4d | %lf | %+le\n", i, sin_N(x, i), sin(x) - sin_N(x, i));
		}
		printf("Способ 3\n");
		printf("Введите точность вычисления:\n");
		scanf("%lf", &eps);
		printf("Синуc %lf равен %lf (вычисленно с помощью функции, вычисляющей значение через ряд Маклорена)\n", x, sin_eps(x, eps));
		break;
	}
	case 3:
	{
		int numb;
		float a;
		char symb;
		int dl;
		printf("\tЗадание 3 | Вариант 7\n");
		printf("Равносторонний треугольник\n");
		printf("Выберите действие:\n");
		printf("1. Рассчитать площадь\n");
		printf("2. Вывести определение фигуры\n");
		printf("3. Нарисовать фигуру\n");
		scanf("%d", &numb);
		switch (numb)
		{
		case 1:
		{
			printf("Введите длину стороны:\n");
			scanf("%f", &a);
			printf("Площадь правильного треугольника со стороной %f равна %lf\n", a, area_triangle(a));
			break;
		}
		case 2:
		{
			printf("Равносторонний треугольник - треугольник у которого равны все стороны и углы,\n");
			break;
		}
		case 3:
		{
			printf("Введите символ из котрого будет построена фигура:\n");
			scanf(" %c", &symb);
			printf("Введите длину стороны:\n");
			scanf("%d", &dl);
			treug(symb, dl);
			break;
		}
		default: printf("Неизвестное действие\n");
		}
	}
	return 0;
	}
}

double fa(double x)
{
	if (x <= 3) return x * x - 3 * x + 9;
	else return 1 / (pow(x, 3) + 3);
}

double fb(double x)
{
	return x * pow(math_e, sin(x * x));
}

double numb_task1(int x)
{
	switch (x)
	{
	case 1:
		return fa(x);
		break;
	case 2:
		return fb(x);
		break;
	case 3:
		return fa(x) * fb(x);
		break;
	case 4:
		return pow(fa(x), 2) - pow(fb(x), 2);
		break;
	case 5:
		return 2 * (fa(x) + fb(x));
		break;
	default: return -0.00000001; 
	}
}

int fact(int x)
{
	int res = 1;
	for (int i = 1; i <= x; i++)
	{
		res = res * i;
	}
	return res;
}

double sin_N(double x, int N)
{
	double res = 0;
	for (int k = 1; k <= N; k++)
	{
		res = res + (pow(-1, k - 1) * (pow(x, 2 * k - 1) / fact(2 * k - 1)));
	}
	return res;
}

double sin_eps(double x, double eps)
{
	double res = 0;
	int k = 1;
	while (fabs(res) > eps)
	{
		res = res + (pow(-1, k) * (pow(x, 2 * k + 1) / fact(2 * k + 1)));
		k++;
	}
	return res;
}

double area_triangle(float a)
{
	return (a * a * pow(3, 0.5)) / 4;
}

char treug(char symb, int a)
{
	for (int i = 0; i < a; i++)
	{
		for (int space = 1;space <= a - i;space++)
		{
			printf(" ");
		}
		for (int s = 1; s <= (2 * i + 1); s++)
		{
			if ((i >= 1 && i < a - 1) && (s > 1 && s < (2 * i + 1))) printf(" ");
			else printf("%c", symb);
		}
		printf("\n");
	}
}