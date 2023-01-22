#include <iostream>
#include <vector>
using namespace std;
void allocc(int arr[], int key, int index, int size, vector<int> &v)
{

    if (index == size)
    {
        return;
    }
    if (arr[index] == key)
    {
        v.insert(v.end(), index);
    }
    return allocc(arr, key, index + 1, size, v);
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
    vector<int> v;
    allocc(arr, 3, 0, n, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "  ";
    }
    return 0;
}