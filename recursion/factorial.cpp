#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int sum = n * factorial(n - 1);
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << factorial(n) << endl;

    return 0;
}
