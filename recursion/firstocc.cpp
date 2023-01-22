#include <iostream>
using namespace std;
void firstocc(int arr[], int key, int index, int size)
{
    if (index == size)
    {
        cout << "not found";
        return;
    }
    if (arr[index] == key)
    {
        cout << index << endl;
        return;
    }
    firstocc(arr, key, index + 1, size);
}
void firstocc2(int arr[], int key, int index, int size)
{
    if (size == 0)
    {
        cout << "not found";
        return;
    }
    if (arr[0] == key)
    {
        cout << index << endl;
        return;
    }
    index = index + 1;
    firstocc(arr + 1, key, index, size - 1);
}
int lastocc(int arr[], int key, int counter, int index, int size)
{
    if (index == -1)
    {
        cout << "not found";
        return -1;
    }
    if (arr[index] == key)
    {
        return counter;
    }
    lastocc(arr, key, counter + 1, index - 1, size);
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
    firstocc(arr, 3, 0, n);
    cout << endl;
    // firstocc2(arr, 3, 0, n);

    cout << lastocc(arr, 3, 0, n - 1, n);
    return 0;
}