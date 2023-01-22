#include <iostream>
using namespace std;
void decre(int n)
{
    if (n == -1)
    {
        return;
    }
    cout << n << endl;
    decre(n - 1);
}
int main()
{
    int n;
    cin >> n;
    decre(n);
    return 0;
}