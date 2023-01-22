#include <iostream>
using namespace std;
void reversearr(int arr[], int n, int index)
{
    if (index == n)
    {
        return;
    }
    reversearr(arr, n, index + 1);
    cout << arr[index] << "  ";
}
void reversearr2(int arr[], int n, int index)
{
    if (index == -1)
    {
        return;
    }
    cout << arr[index] << "  ";
    reversearr2(arr, n, index - 1);
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
    reversearr(arr, n, 0);
    cout << endl;
    reversearr2(arr, n, n - 1);
    return 0;
}