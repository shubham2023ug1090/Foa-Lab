#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(vector<int> &arr)
{
    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {2, 3, -8, 9, -1, 2, 3};
    cout << "Maximum subarray sum is " << maxSubarraySum(arr) << endl;
    return 0;
}