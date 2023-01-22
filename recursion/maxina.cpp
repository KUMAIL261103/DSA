#include <iostream>
using namespace std;
int maxina(int arr[], int size, int index, int maxo)
{
    if (index == size)
    {
        return maxo;
    }
    maxo = max(maxo, arr[index]);
    maxina(arr, size, index + 1, maxo);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxina(arr, n, 0, -1);
    return 0;
}