#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("file1.txt");
	float r, x, y;    // радиус и координаты центра окружности
	float kx, ky;     // координаты точек
	float sum;
	while (!fin.eof()) {
		fin >> x;
		fin >> y;
		fin >> r;
	}
	fin.close();

	fin.open("file2.txt");
	while (!fin.eof()) {
		fin >> kx;
		fin >> ky;
		sum = abs(sqrt(pow(x - kx, 2) + pow(y - ky, 2)));
		//cout << "X = " << kx << " Y= " << ky << endl;
		if (sum < r)
			cout << 1 << endl;      //точка лежит внутри
		else if (sum == r)
			cout << 0 << endl;      //точка лежит на окружности
		else
			cout << 2 << endl;      //точка лежит снаружи
	}
	fin.close();

	return 0;
}
