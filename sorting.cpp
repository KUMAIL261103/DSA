
#include <iostream>
using namespace std;

void selectionSort(int arr[], int *n)
{
    for (int i = 0; i < *n - 1; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = 0;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void insertionsort(int arr[], int *n)
{
    for (int i = 1; i < *n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bubbleSort(int arr[], int *n)
{
    for (int i = 0; i < *n - 1; i++)
    {
        for (int j = 0; j < *n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = 0;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid + 1 - l;
    int n2 = r - mid;
    int a[n1]; // temp arrays
    int b[n2]; // temp arrays
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[i + l];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[i + mid + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    if (i == n1)
    {
        while (j < n2)
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    if (j == n2)
    {
        while (i < n1)
        {
            arr[k] = a[i];
            k++;
            i++;
        }
    }
}

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return (i + 1);
}
void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
    }
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
    // selectionSort(arr, &n);
    // insertionsort(arr, &n);
    // bubbleSort(arr, &n);
    // mergesort(arr, 0, n);
    quicksort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}
