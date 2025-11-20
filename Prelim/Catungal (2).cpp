#include <iostream>
#include <vector>

// Task 1: 

int sumRecursive(const std::vector<int>& nums, int n) 
{
    if (n == 0) return 0;
    return nums[n - 1] + sumRecursive(nums, n - 1);
}

int sumIterative(const std::vector<int>& nums) 
{
    int total = 0;
    for (int num : nums) 
	{
        total += num;
    }
    return total;
}

// Task 2:

int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n) 
{
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) 
	{
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Main Program
int main() 
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << "Sum Recursive: " << sumRecursive(nums, nums.size()) << std::endl;
    std::cout << "Sum Iterative: " << sumIterative(nums) << std::endl;

    int n = 10;
    std::cout << "Fibonacci Recursive (" << n << "): " << fibonacciRecursive(n) << std::endl;
    std::cout << "Fibonacci Iterative (" << n << "): " << fibonacciIterative(n) << std::endl;

    return 0;
}
