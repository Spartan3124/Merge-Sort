#include <iostream>
#include <vector>
#include <ctime>
#include "mergeSort.h"

void fillArray(std::vector<int> & x, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int random = 1 + rand() % 100;
        x[i] = random;
    }
}


void printArray(const std::vector<int> & x, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; ++i)
    {
         std::cout << x[i] << " ";
    }
    std::cout << "]";
}


std::vector<int> & swap(std::vector<int> & x, int ti, int j, int i)
{
    x[i] = x[j];
    x[j] = ti;
}


std::vector<int> & mergeHelper(std::vector<int> & x, int start, int end,
                               std::vector<int> & temp)
{
     
}


std::vector<int> & merge(std::vector<int> & x, int start, int mid, int start2,
                         int end, std::vector<int> & temp, int n)
{
    // start2 = mid + 1
    std::cout << "\nreceived: ";
    for (int i = start; i <= end; ++i)
    {
        std::cout << x[i] << ' ';
    }
    
    std::cout << '\n' << "temp: ";
    for (int i = start; i <= mid; ++i)
    {
        temp[i - start] = x[i];
        std::cout << temp[i - start] << ' ';
    }
    
    int left = start;
    int right = start2;
    for (int i = start; i <= end; ++i)
    {
        std::cout << "i: " << i << ' ';
        printArray(x, n);
        std::cout << '\n';
        if (left > mid && right > end) break;
        
        if (left > mid)
        {
            //std::cout << "left > mid : " << x[i] << " = " << x[right]
            //          << '\n';
            x[i] = x[right];
            ++right;
            printArray(x, n);
            //std::cout << '\n';
        }
        else if (right > end)
        {
            //std::cout << "right > end : " << x[i] << " = " << temp[left - start]
            //          << '\n';
            //break;
            x[i] = temp[left - start];
            ++left;
            printArray(x, n);
            std::cout << '\n';
        
        }
        else if (temp[left - start] < x[right])
        {
            //std::cout << "left < right : " << x[i] << " = " << temp[left - start]
            //          << '\n';
            
            x[i] = temp[left - start];
            ++left;
            printArray(x, n);
            //std::cout << '\n';
        
        }
        else if (x[right] < temp[left - start])
        {
            //std::cout << "right < left : " << x[i] << " = " << x[right]
            //          << '\n';
            x[i] = x[right];
            //std::cout << "temp[" << left << "]: " << temp[left - start] << '\n'; 
            x[right] = temp[left - start];
            ++right;
            printArray(x, n);
            //std::cout << '\n';
        
        }
        else
        {
            //std::cout << "equals\n";
            x[i] = temp[left - start];
            ++left;
        }
    }
    //std::cout << "\n\n";

    // for (int i = start; i <= mid; ++i)
    // {
    //     for (int j = start2; j <= end; ++j)
    //     {           
    //         if (x[i] < x[j])
    //         {
    //             std::cout << "less than: " << x[i] << " < " << x[j] << '\n';
    //             //break;
    //         }
    //         else
    //         {
    //             std::cout << "swap: " << x[i] << " > " << x[j] << '\n';
    //             temp[i] = x[i];
    //             x[i] = x[j];
    //             x[j] = temp[i];
    //             printArray(x, 7);
    //             std::cout << '\n';
    //             //break;
    //         }
    //     }
    // }
    
    return x;
}


std::vector<int> & mergeSort(std::vector<int> & x, int start, int end,
                             std::vector<int> & temp, int & i, int n)
{
    //Need to get length of array first, then correct index for mid
    //Can't use index values to calculate right side
    // std::cout << "recursion received: ";
    // for (int i = start; i <= end; ++i)
    // {
    //     std::cout << x[i] << ' ';
    // }
    // std::cout << "\n\n";
    
    //++i;
    int mid = ((end - start) / 2) + start;
    int start2 = mid + 1;
    if ((end - start) <= 0)
    {
        //std::cout << "RETURN\n";
        return x;
    }
    
    mergeSort(x, start, mid, temp, i, n); //L
    mergeSort(x, start2, end, temp, i, n); //R

    merge(x, start, mid, start2, end, temp, n);
    //std::vector<int> ret(10);
    //return ret = merge(x, start, mid, start2, end, temp);
    //std::vector<int> ret();
    //ret = x;
    return x;
}


int main()
{
    //Make array
    int n = 0;
    std::cin >> n;
    std::vector<int> x(n);
    std::vector<int> temp((n / 2));
    fillArray(x, n);
    
    int start = 0;
    int i = 0;
    std::cout << "\narray: ";
    printArray(x, n);
    std::cout << "\n";

    //--n;
    int nminus = n - 1;
    mergeSort(x, start, nminus, temp, i, n);
    //++n;
    std::cout << "\nsorted: ";
    printArray(x, n);
    std::cout << "\n";
    return 0;
}
