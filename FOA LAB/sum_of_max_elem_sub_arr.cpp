#include <iostream>
#include <vector>
#include <algorithm>

int sumOfMaxElements(std::vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            int maxElement = *std::max_element(arr.begin() + i, arr.begin() + j + 1);
            sum += maxElement;
        }
    }

    return sum;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int result = sumOfMaxElements(arr);
    std::cout << "Sum of maximum elements: " << result << std::endl;
    return 0;
}