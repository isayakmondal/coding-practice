
#include <bits/stdc++.h>
using namespace std;

// Heapify Algorithm(max heap)
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build Heap
void buildHeap(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{

    buildHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void bubbleSort(int arr[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int mn = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mn])
                mn = j;
        }
        swap(arr[i], arr[mn]);
    }
}

void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int j = i - 1, temp = arr[i];
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int l, int h, int mid)
{

    int sizeL = mid - l + 1;
    int sizeR = h - (mid + 1) + 1;

    int L[sizeL], R[sizeR];

    for (int i = 0; i < sizeL; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < sizeR; i++)
    {
        R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;

    while (i < sizeL && j < sizeR)
    {

        if (L[i] < R[j])
            arr[k++] = L[i++];
        else if (L[i] > R[j])
            arr[k++] = R[j++];
    }

    while (i < sizeL)
        arr[k++] = L[i++];
    while (j < sizeR)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, h, mid);
    }
}
// 5 8 9 3 2 6
int partition(int arr[], int start, int end)
{

    int pivot = arr[end], pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex - 1);
        quickSort(arr, pIndex + 1, end);
    }
}

int main()
{
    // Write C++ code here
    int arr[] = {9, 9, 8, 5, 6, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    // bubbleSort(arr,n);
    // selectionSort(arr,n);
    // insertionSort(arr,n);
    // mergeSort(arr,0,n-1);
    // quickSort(arr,0,n-1);
    // heapSort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}