#include <iostream>
#include <array>
using namespace std;
void printarr(int arr[], int n, int index)
{
    if (index == n)
    {
        return;
    }
    cout << arr[index] << " ";
    printarr(arr, n, index + 1);
}
void printarr2(int arr[], int size)
{

    if (size == 0)
    {
        return;
    }
    cout << arr[0] << " ";
    printarr2(arr + 1, size - 1);
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
    printarr(arr, n, 0);
    printarr2(arr, n);
    return 0;
}