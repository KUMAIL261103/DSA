#include <iostream>
using namespace std;
void incre(int n)
{
    if (n == -1)
    {
        return;
    }
    incre(n - 1);
    cout << n << endl;
}
int main()
{
    int n;
    cin >> n;
    incre(n);
    return 0;
}