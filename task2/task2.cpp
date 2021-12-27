#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string name_file1,name_file2;
	cout << "Enter name of the first file: ";
	cin >> name_file1;
	cout << endl;
	cout << "Enter name of the second file: ";
	cin >> name_file2;
	ifstream fin;
	fin.open(name_file1);
	float r, x, y;    // радиус и координаты центра окружности
	float kx, ky;     // координаты точек
	float sum;
	while (!fin.eof()) {
		fin >> x;
		fin >> y;
		fin >> r;
	}
	fin.close();

	fin.open(name_file2);
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
