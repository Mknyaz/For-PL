#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    vector <int> nums;
    int value;
    float sum = 0;
    int count = 0;
    ifstream fin;
    fin.open("file.txt");
    while (!fin.eof()) {
        fin >> value;
        nums.push_back(value);
        sum += value;
        count++;
    }
    fin.close();
    sum = round(sum / count);
    value = 0;
    for (int i = 0; i < count; i++)
        value += abs(nums[i] - sum);
    cout << value;

    return 0;
}
