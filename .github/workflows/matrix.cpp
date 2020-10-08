#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Выберите действие: " << "\n";
	cout << "1 - Определение детерминанта" << "\n";
	cout << "2 - Решение метода Гаусса" << "\n";
	int var;
	cin >> var;
	switch (var) {
	case 1: {
		cout << "Введите матрицу 3х3" << "\n";

		//Обчислення матриці
		// d - додатня діагональ
		// d1 - 1 трикутник
		// d2 - 2 трикутник
		// 
		//
		//

		int n, m, a[3][3], d, d1, d2, v, v1, v2, det;

		det = 0;
		v = 0;
		v1 = 0;
		v2 = 0;
		d2 = 0;
		d1 = 0;
		d = 0;
		n = 3;
		m = 3;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
			cout << endl;
		}

		system("cls");
		cout << "Матрница 3x3" << "\n" << "\n";

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}

		//Додатня діагональ
		cout << "\n" << "Головная диагональ: ";
		d = a[0][0] * a[1][1] * a[2][2];
		cout << "\n" << d;

		cout << "\n" << "Трикутник 1";
		d1 = a[0][1] * a[1][2] * a[2][0];
		cout << "\n" << d1;

		cout << "\n" << "Трикутник 2";
		d2 = a[1][0] * a[2][1] * a[0][2];
		cout << "\n" << d2;

		//Від'ємна діагональ
		cout << "\n" << "Отрицательная диагональ: ";
		v = a[0][2] * a[1][1] * a[2][0];
		cout << "\n" << v;

		cout << "\n" << "Трикутник -1";
		v1 = a[0][1] * a[1][0] * a[2][2];
		cout << "\n" << v1;

		cout << "\n" << "Трикутник -2";
		v2 = a[1][2] * a[2][1] * a[0][0];
		cout << "\n" << v2;

		//Детермінант
		cout << "\n" << "Детерминант: ";
		det = d + d1 + d2 * v - v1 - v2;
		cout << det;
		cout << "\n";

		if (det > 0) {
			cout << "Уравнение решаемое";
		}
		else if (det < 0) {
			cout << "В уравнения нет решения";
		}
		break;
	}
	case 2: {
		int n, i, j, k;
		double d, s;
		cout << "Введите матрицу:" << "\n";
		cout << "Тип матрицы: " << endl;
		cin >> n;
		double** a = new double* [n];
		for (i = 0; i <= n; i++)
			a[i] = new double[n];
		double** a1 = new double* [n];
		for (i = 0; i <= n; i++)
			a1[i] = new double[n];
		double* b = new double[n];
		double* x = new double[n];
		cout << "Введите коэффициенты и свободные члены: " << endl;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				cout << "a[ " << i << "," << j << "]= ";
				cin >> a[i][j];
				a1[i][j] = a[i][j];
			}
			cout << "b,[ " << i << "]= ";
			cin >> b[i];
		}

		for (k = 1; k <= n; k++) // прямой ход
		{
			for (j = k + 1; j <= n; j++)
			{
				d = a[j][k] / a[k][k]; // формула (1)
				for (i = k; i <= n; i++)
				{
					a[j][i] = a[j][i] - d * a[k][i]; // формула (2)
				}
				b[j] = b[j] - d * b[k]; // формула (3)
			}
		}

		for (k = n; k >= 1; k--) // обратный ход
		{
			d = 0;
			for (j = k + 1; j <= n; j++)
			{
				s = a[k][j] * x[j]; // формула (4)
				d = d + s; // формула (4)
			}
			x[k] = (b[k] - d) / a[k][k]; // формула (4)
		}

		cout << "Корни системы: " << endl;
		for (i = 1; i <= n; i++)
			cout << "x[" << i << "]=" << x[i] << " " << endl;

	}
	}
	return 0;

}
