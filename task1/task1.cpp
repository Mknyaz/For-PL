#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    if (m > n)
        m -= n;
    int z=1;
    do {
        cout << z;
        z += m - 1;
        if (z > n)
          z -= n;
     } while (z != 1);

    return 0;
}
