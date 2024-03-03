#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void bubbleSort(vector<int> &a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
                // int temp = a[i];
                // a[i] = a[j];
                // a[j] = temp;
            }
        }
    }
}

void selectionSort(vector<int> &a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i, minVal = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < minVal)
            {
                minVal = a[j];
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void insertionSort(vector<int> &a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >= 1 && a[j - 1] > a[j])
        {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}

vector<int> mergeArray(vector<int> &a1, vector<int> &a2)
{
    int n = a1.size(), m = a2.size();
    int i = 0, j = 0;
    vector<int> res;
    while (i < n && j < m)
    {
        if (a1[i] <= a2[j])
        {
            res.pb(a1[i]);
            i++;
        }
        else
        {
            res.pb(a2[j]);
            j++;
        }
    }
    while (i < n)
    {
        res.pb(a1[i]);
        i++;
    }
    while (j < m)
    {
        res.pb(a2[j]);
        j++;
    }
    return res;
}

vector<int> subMergeSort(vector<int> &a)
{
    int n = a.size();
    if (n <= 1)
        return a;
    int m = n / 2;
    vector<int> v1(a.begin(), a.begin() + m);
    vector<int> v2(a.begin() + m, a.end());
    vector<int> s1 = subMergeSort(v1);
    vector<int> s2 = subMergeSort(v2);
    return mergeArray(s1, s2);
}

void mergeSort(vector<int> &a)
{
    vector<int> res = subMergeSort(a);
    for (int i = 0; i < a.size(); i++)
        a[i] = res[i];
}

void heapSort(vector<int> &arr, int start, int end)
{
    if (end - start <= 1)
        return;
    int pivotEle = arr[start];
    int yellow = start, green = end;
    for (int k = start; k <= end; k++)
    {
        while (yellow <= end && arr[yellow] <= pivotEle)
            yellow++;

        while (green>=0 && arr[green] >= pivotEle)
            green--;

        if (arr[k] <= pivotEle)
        {
            swap(arr[yellow], arr[k]);
            yellow++;
        }
        else
        {
            swap(arr[green], arr[k]);
            green--;
        }
    }
    swap(pivotEle, arr[green]);
    heapSort(arr, 0, green - 1);
    heapSort(arr, green + 1, end);
}
int main()
{
    // vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> arr = {3, 89, 78, 6, 0, 3265, 776, 9};
    // bubbleSort(arr, arr.size());
    // selectionSort(arr, arr.size());
    // insertionSort(arr, arr.size());
    // mergeSort(arr);
    heapSort(arr, 0, arr.size() - 1);
    print(arr);
}