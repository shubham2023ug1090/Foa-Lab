#include <iostream>
#include <climits>
#include <vector>
using namespace std;

long long countAndMerge(vector<long long> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<long long> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[i + l];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[m + 1 + j];
    }
    long long res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            res += n1 - i;
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (i < n2)
    {
        arr[k++] = left[i++];
    }
    return res;
}

long long count_inv(vector<long long> &arr, int l, int r)
{
    long long res = 0;
    if (l < r)
    {
        int m = (r + l) / 2;
        res += count_inv(arr, l, m);
        res += count_inv(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int main()
{
    vector<long long> arr = {4, 3, 2, 1};
    int n = arr.size();
    int cnt1 = count_inv(arr, 0, n - 1);
    cout << "the inversion count of Array : " << cnt1 << endl;
    return 0;
}