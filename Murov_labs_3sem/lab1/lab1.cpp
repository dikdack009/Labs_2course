#include <iostream>
#include "lab1.h"

using namespace std;
using namespace PROG_1;

int main() {
    Int** mas = nullptr;
    int m;
    cout << "Enter number of rows --> ";
    int Er = getNum(m); // number of rows
    if (Er)
    {
        return 1;
    }
    int n;
    int b = m;
    mas = create(mas, &m, &n);
    if (!mas) {
        cout << "ERROR" << endl;
        return 1;
    }
    output(mas, m, n, b);
    Int* a = createMas(mas, m);
    output(a);
    return 0;
}
