#include <iostream>
#include "lab1.h"
using namespace std;

namespace PROG_1 {

    int getNum(int& m)
    {
        cin >> m;
        while (!cin.good())
            return 1;
        return 0;
    }

    Int** memory(Int** mas, int* p, int* n)
    {
        int m = *p;
        int Er;
        cout << "Enter number of cols --> ";
        Er = getNum(*n); // number of cols
        if (Er)
        {
            return nullptr;
        }
        try {
            mas = new Int * [m];
        }
        catch (std::bad_alloc & ba) {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            delete[] mas;
            return nullptr;
        }
        return mas;
    }

    Int** create(Int** mas, int *p, int*n)
    {
        int m = *p, Er, h = 1, key, ii, jj;
        mas = memory(mas, p, n);
        if (mas == nullptr) return nullptr;
        int* str = new int[*n];
        for (int i = 0; i < m; i++) { mas[i] = new Int; mas[i][0].n = 0; }
        while (h) {
            for (int i = 0; i < *n; i++)  str[i] = 0;
            cout << "---------------------------" << endl << "Enter your row number --> ";
            Er = getNum(ii);
            if (Er) return nullptr;
            if ((ii > m) || (ii < 1)) {
                cout << "Incorrect row number " << endl;
                continue;
            }
            jj = 1;
            int k = 0;
            while (jj) {
                cout << "------------" << endl << "Enter your col number(if you want to exit, enter 0) --> ";
                Er = getNum(jj);
                if (Er) return nullptr;
                if (jj == 0)
                    break;
                if ((jj > *n) || (jj < 0)) {
                    cout << "Incorrect col number " << endl;
                    continue;
                }
                cout << "Enter your key --> ";
                Er = getNum(key);
                if (Er) return nullptr;
                if (key == 0) {
                    cout << "Incorrect key" << endl;
                    continue;
                }
                if (str[jj - 1] == 0) k++;
                str[jj - 1] = key;
            }
            for (int i = 0; i < mas[ii - 1][0].n; i++)  //здесь мы дополняем массив str уже существующими элементами cтроки mas[i]
                if (str[mas[ii - 1][i].col] == 0){
                    str[mas[ii - 1][i].col] = mas[ii - 1][i].key;
                    k++;
                }
            delete[] mas[ii - 1];
            mas[ii - 1] = new Int[k];
            mas[ii - 1][0].n = k;
            int nn = 0;
            for (int j = 0; j < *n; j++){
                if (str[j] != 0)
                {
                    mas[ii - 1][nn].key = str[j];
                    mas[ii - 1][nn].col = j;
                    mas[ii - 1][nn].str = ii-1;
                    nn++;
                }
                if (nn > k) break;
            }
            cout << "if you want to exit, enter 0; If not, enter 1, or another to continue --> ";
            getNum(h);
        }
        delete[] str;
        int nn = 0;
        for (int i = 0; i < m; i++) if (mas[i][0].n != 0) nn++;
        mas = realloc(mas, m);
        *p = nn;
        return mas;
    }

    Int** realloc(Int**mas, int m)
    {
        Int** new_mas = nullptr;
        int nn = 0;
        for (int i = 0; i < m; i++)
        {
            if (mas[i][0].n != 0) {
                nn++;
            }
        }
        try {
            new_mas = new Int * [nn];
        }
        catch (std::bad_alloc & ba) {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            delete[] mas;
            return nullptr;
        }
        int p = 0;
        for (int i = 0; i < m; i++)
        {
            if (mas[i][0].n != 0) {
                new_mas[p] = new Int[mas[i][0].n];
                for (int j = 0; j < mas[i][0].n; ++j)
                new_mas[p][j] = mas[i][j];
                p++;
            }
        }
        errase(mas, m);
        return new_mas;
    }

    int count_Un(Int *str)
    {
        int* buf = new int[str[0].n];
        int zap = 0, ch, rez = 0;
        bool check = true;
        for (int j = 0; j < str[0].n; ++j)
        {
            ch = 1;
            for (int k = 0; k < str[0].n; ++k)
                if (str[j].key == str[k].key && j != k)
                    ++ch;
            if (ch > 1)
            {
                for (int p = 0; p < str[0].n; ++p)
                    if (buf[p] == str[j].key)
                    {
                        check = false;
                        break;
                    }
                if (check)
                {
                    buf[zap] = str[j].key;
                    ++zap;
                    ++rez;
                }
                check = true;
            }
            else if (ch == 1) ++rez;
        }
        delete[] buf;
        return rez;
    }

    Int* createMas(Int** mas, int m)
    {
        int n = 0;
        int nn = 0;
        for (int i = 0; i < m; i++)
        {
            if (mas[i][0].n != 0) {
                nn++;
            }
        }
        Int* a = new Int[nn];
        a[0].n = nn;
        for (int i = 0; i < m; i++)
        {
            
            int count = count_Un(mas[i]);
            
            if (count) {
                a[n].key = (int)count;
                a[n].col = mas[i][0].str;
                ++n;
            }
        }
        return a;
    }

    void errase(Int** mas, int m) {
        for (int i = 0; i < m; i++)
            delete[] mas[i];
        delete[] mas;
    }

    void output(Int** mas, int m, int n, int new_m)
    {
        cout << "Output process:" << endl;
        //cout << " M = " << m << endl;
        for (int i = 0; i < m; i++) {
            cout << mas[i][0].str + 1 << ". ";
            int g = mas[i][0].n;
            for (int j = 0; j < mas[i][0].n; j++) {
                //cout << "[i;j] = [" << i << ";" << j <<"] ";
                cout << mas[i][j].key << '(' << mas[i][j].col + 1 << ')' << '|';
            }
            cout << endl;
        }/*
        cout << "\nFirst output:" << endl;
        for (int i = 0; i < new_m; i++, cout << endl) {
            //cout << i << "  "<< mas[i][0].str << endl;
            if (i != mas[i][0].str)
            {
                int buf = n;
                int k = 0;
                while (buf--)
                {
                    cout << "0[" << i + 1 << ";" << k + 1 << "]| ";
                    ++k;
                }
                continue;
            }
            int t = 0;
            int ch;
            if (mas[i][0].n == 0) ch = n;
            else ch = mas[i][t].col;
            for (int j = 0; j < n; j++)
            {
                //cout << "CH = " << ch << endl;
                if (j != ch)
                    cout << "0[" << i + 1 << ";" << j + 1 << "]| ";
                else
                {
                    cout << mas[i][t].key << '[' << mas[i][0].str + 1 <<
                        ";" << mas[i][t].col + 1 << "]| ";
                    ++t;
                    if (t >= mas[i][0].n) t = n - 1;
                    if (mas[i][0].n == 0) ch = n;
                    else ch = mas[i][t].col;
                }
            }
                
        }*/
    }

    void output(Int* mas)
    {
        int n = mas[0].n;
        cout << "\nSecond output:\n";
        for (int i = 0; i < n; i++)
        {
            cout << mas[i].key << "[" << mas[i].col + 1 << "]|";
            if ((i+1) % 10 == 0) cout << endl;
        }
        cout << endl;
    }
}
/*
1 2 3 1 5 2

вспомогательный 1 2 */