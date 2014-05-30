#include <iostream>
#define LEN 1000
using namespace std;

void sum(int a[LEN + 2], int b[LEN + 2])
{
    int mem = 0;
    for (int i = LEN + 1; i >= 0; --i){
        int tempa = a[i];
        a[i] = ((a[i] + b[i]) + mem) % 10;
        mem = (tempa + b[i] + mem) / 10;
    }
}
bool isOK(int a[LEN + 2])
{
    for (int i = 2; i >= 0; --i){
        if (a[i] != 0) return true;
    }
    return false;
}
void swap(int a[LEN + 2], int b[LEN + 2])
{
    int t[LEN + 2];
    for (int i = 0; i < LEN + 2; ++i){
        t[i] = a[i];
        a[i] = b[i];
        b[i] = t[i];
    }
}
int main()
{
    int counting = 2;
    int a[LEN + 2];
    int b[LEN + 2];
    for (int i = 0; i < LEN + 1; ++i){
        a[i] = b[i] = 0;
    }
    a[LEN + 1] = b[LEN + 1] = 1;
    while (!isOK(b)){
        sum(a, b);
        swap(a, b);
        ++counting;
    }
    cout << counting;
    return 0;
}