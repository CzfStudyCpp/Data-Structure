#include<random>
#include<vector>
#include <chrono>

#include"sort.cpp"

//#include<windows.h>
using namespace std;

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());  // 使用 Mersenne Twister 引擎

    // 创建一个分布对象，指定随机数的范围
    std::uniform_int_distribution<> dis(1, 10000);
    std::vector<int>arr(100);
    std::vector<int>arr1(1000);
    std::vector<int>arr2(10000);
    for (int i = 0; i < 100; i++)
    {
        
              arr[i] = dis(gen);
    }

    for (int i = 0; i < 1000; i++)
    {

        arr1[i] = dis(gen);
    }
    for (int i = 0; i < 10000; i++)
    {

        arr2[i] = dis(gen);
    }
    insert_sort(arr);
    auto start_time = std::chrono::high_resolution_clock::now();

   // showArr(arr);
    
    // insert_sort(arr1);
   //  insert_sort(arr2);
   //select_sort(arr);
  //  bubble_sort(arr);
    quick_sort(arr);
  //  mergeSort(arr);
   // heapSort(arr);
  //  start = timeGetTime();
    //radixSort(arr);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // 输出运行时间
    std::cout << "程序运行时间: " << duration.count() << " 微秒" << std::endl;

   showArr(arr);
   // showArr(arr1, n1);
    return 0;
}