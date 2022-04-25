#include "PolytopeMethod.h"
#include "Pirson3Method.h"
#include <fstream>

double func(vector<double> &x)
{
	// квадратичная функция; ответ (1; 1)
	// return 100 * (x[1] - x[0]) * (x[1] - x[0]) + (1 - x[0]) * (1 - x[0]);

	// функция Розенброка; ответ (1; 1)
	return 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]) + (1 - x[0]) * (1 - x[0]);

	// заданная f(x)
	// т.к. максимизируем f(x), то минимизировать будем -f(x)
	// тут задано -f(x) нечетных вариантов
	// константы варианта 7
	// ответ
	// double A1 = 2,
	//     A2 = 3,
	//     a1 = 1, b1 = 2, c1 = 1, d1 = 2,
	//     a2 = 1, b2 = 3, c2 = 3, d2 = 3;
	// return -(A1 *
	//     exp(-((x[0] - a1) / b1) * ((x[0] - a1) / b1)
	//         - ((x[1] - c1) / d1) * ((x[1] - c1) / d1)) + A2 *
	//     exp(-((x[0] - a2) / b2) * ((x[0] - a2) / b2)
	//         - ((x[1] - c2) / d2) * ((x[1] - c2) / d2)));
}

int main()
{
	cout.precision(10);
	ofstream out("out.txt");
	out.precision(10);
	out.imbue(locale("Russian"));
	PolytopeMethod t;
	Pirson3Method tt;
	vector<double> v(2);
	v[0] = 5;
	v[1] = -5;

	// метод деформируемого многогранника
	/*int iter = t.Algorithm(v);
	cout << "Polytope method" << endl;
	cout << "Iterations: " << iter << endl;
	cout << "Result: " << v[0] << " " << v[1] << endl;
	cout << "FUNC: " << func(v) << endl;*/

	// метод Пирсона(3)
	int iter = tt.Algorithm(v);
	out << iter << "\t \t" << v[0] << "\t" << v[1] << "\t" << func(v) << endl;
	out << "Pirson method" << endl;
	out << "Iterations: " << iter << endl;
	out << "Result: " << v[0] << "\t" << v[1] << endl;
	out << "FUNC: " << func(v) << endl;

	/*cout << "Pirson method" << endl;
	cout << "Iterations: " << iter << endl;
	cout << "Result: " << v[0] << " " << v[1] << endl;
	cout << "FUNC: " << func(v) << endl;*/

	return 0;
}