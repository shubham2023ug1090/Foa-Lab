#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int inversion_cnt(int arr[], int n)
{
    int inv_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                inv_cnt++;
            }
        }
    }
    return inv_cnt;
}

int main()
{  
    int n = 12;
   int  arr[n] = {1, 5, 4, 8, 10, 2, 6, 19, 12, 11, 3, 7};
    int cnt = inversion_cnt(arr, n);
    cout << "the inversion count of array: " << cnt << endl;
}