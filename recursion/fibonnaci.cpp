#include <iostream>
using namespace std;
int fibonnaci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int sum = fibonnaci(n - 1) + fibonnaci(n - 2);
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << fibonnaci(n);
    return 0;
}