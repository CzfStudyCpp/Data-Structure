#include<iostream>
#include<utility>
#include <vector>
#include"sort.h"


template<class T1>
void insert_sort(std::vector<T1>& arr)
{
    
    for (int i = 1; i < arr.size(); i++)
    {
        T1 now = arr[i];
       unsigned int j;
        for (j = i; j > 0 && arr[j - 1] > now; j--)
        {
            arr[j] = arr[j - 1];

        }
        arr[j] = now;
    }
}

template<class T1>
void insert_sort(std::vector<T1>& arr,unsigned int left,unsigned int right)
{
    for (unsigned int i = left + 1; i <= right; i++)
    {
        T1 now = arr[i];
        unsigned int j;
        for (j = i; j > left && arr[j - 1] > now; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = now;
    }
}

template<class T3>
void select_sort(std::vector<T3>& arr)
{
    for (unsigned int i = 0; i <arr.size()-1; i++)
    {
        for (unsigned int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[i])
            {
                T3 temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

template<class T4>
void bubble_sort(std::vector<T4>& arr)
{
    for (unsigned int i = 0; i < arr.size() - 1; i++)
    {
        for (unsigned int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T4 temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



template<class T>
void quick_sort(std::vector<T>& arr)
{
    quick_sort(arr, 0, arr.size() - 1);
}

template<typename Object>
void mergeSort(std::vector<Object>& arr)
{
    std::vector<Object>TempArr(arr.size());
    mergeSort(arr, TempArr, 0, arr.size() - 1);
}

template<typename Object>
void mergeSort(std::vector<Object>& arr, std::vector<Object> TempArr, unsigned int left, unsigned int right)
{
    if (left < right)
    {
        unsigned int center = (left + right) / 2;
        mergeSort(arr, TempArr, left, center);
        mergeSort(arr, TempArr, center + 1, right);
        merge(arr, TempArr, left, center + 1, right);
    }
}

template<typename Object>
void merge(std::vector<Object>& arr, std::vector<Object> TempArr, unsigned int left, unsigned int rightPos, unsigned int rightEnd)
{
    unsigned int leftEnd = rightPos - 1;
    unsigned int tempPos = left;//��߲���
    unsigned int num_Elements = rightEnd - left + 1;//Ԫ������
    while (left <= leftEnd && rightPos <= rightEnd)
    {
        if (arr[left] <= arr[rightPos])TempArr[tempPos++] = std::move(arr[left++]);
        else TempArr[tempPos++] = std::move(arr[rightPos++]);

    }//���������ʱ����

    //����ʣ��Ԫ��
    while(left<=leftEnd)TempArr[tempPos++] = std::move(arr[left++]);
    while(rightPos<=rightEnd)TempArr[tempPos++] = std::move(arr[rightPos++]);
    //
    //����ԭ����
    for (unsigned int i = 0; i < num_Elements; i++, rightEnd--)
        arr[rightEnd] = std::move(TempArr[rightEnd]);
}

template<typename Object>
void heapSort(std::vector<Object>& arr)
{
    for (long int i = arr.size() / 2 - 1; i >= 0; --i)
        percDown(arr, i, arr.size() );//������

    for (long int j = arr.size() - 1; j > 0; --j)
        {
            std::swap(arr[0], arr[j]);
            percDown(arr, 0, j);//��������
        }
    
}

template<class T>
 void quick_sort(std::vector<T>& arr,unsigned int left,unsigned int right)
{
     if (left + 10 <= right)
     {
         unsigned int tempLeft = left;
         unsigned int tempRight = right;
         T flag = arr[(tempLeft + tempRight) / 2];
         do
         {
             while (arr[tempLeft] < flag)tempLeft++;
             while (arr[tempRight] > flag)tempRight--;
             if (tempLeft <= tempRight)
             {
                 T temp = arr[tempLeft];
                 arr[tempLeft] = arr[tempRight];
                 arr[tempRight] = temp;
                 tempLeft++;
                 tempRight--;
             }
         } while (tempLeft <= tempRight);
         if (left < tempRight)quick_sort(arr, left, tempRight);
         if (tempLeft < right)quick_sort(arr, tempLeft, right);

     }
     else
     {
         insert_sort(arr, left, right);
     }
}
 template<typename Object>
 void percDown(std::vector<Object>& arr, long int pos, unsigned int size)
 {
     long int child;
     Object temp;
     for (temp = std::move(arr[pos]); leftChild(pos) < size; pos = child)
     {
         child = leftChild(pos);
         if (child != size - 1 && arr[child] < arr[child + 1])++child;
         if (temp < arr[child])arr[pos] = std::move(arr[child]);
         else break;
     }
     arr[pos] = std::move(temp);
 }
 template<typename Object>
 void radixSort(std::vector<Object>& arr)
 {
     Object max = getMax(arr);
     std::vector<std::vector<Object>>buckets(10);
     for (long int exp = 1; max / exp > 0; exp *= 10)
     {
         unsigned int n = arr.size();
         std::vector<Object> output(n+1);
         std::vector<Object> count(10, 0);
         // ͳ��ÿ��λ�����ֵĳ��ִ���
         for ( int i = 0; i < n; ++i) {
             count[(arr[i] / exp) % 10]++;
         }
         // ��count�����ۼӣ���ʾÿ�������������������е�λ��
         for ( int i = 1; i < 10; ++i) {
             count[i] += count[i - 1];
         }
         // ��ԭ�����й�������������
         for ( int i = n - 1; i >= 0; --i) {
             output[count[(arr[i] / exp) % 10] - 1] = arr[i];
             count[(arr[i] / exp) % 10]--;
         }
         // �����������鸳ֵ��ԭ����
         for ( int i = 0; i < n; ++i) {
             arr[i] = output[i];
         }
     }
 }
 template<typename Object>
 Object getMax(const std::vector<Object>& arr)
 {
     Object maxNum = arr[0];
     for (unsigned int i = 1; i < arr.size(); ++i) {
         if (arr[i] > maxNum)  maxNum = arr[i];
         
     }
     return maxNum;
 }
 template<class T2>
void showArr(std::vector<T2>& arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

inline unsigned int leftChild(unsigned int i)
{
    return i*2+1;
}
