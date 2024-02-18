#ifndef SORT_H_
#define SORT_H_
#include<vector>
template<class T1>
void insert_sort(std::vector<T1>&arr);

template<class T3>
void select_sort(std::vector<T3>& arr);


template<class T4>
void bubble_sort(std::vector<T4>& arr);

template<class T>
void quick_sort(std::vector<T>& arr, unsigned int left, unsigned int right);


template<class T>
void quick_sort(std::vector<T>& arr);

template<typename Object>
void mergeSort(std::vector<Object>& arr);

template<typename Object>
void mergeSort(std::vector<Object>& arr,std::vector<Object>TempArr,unsigned int left,unsigned int right);
template<typename Object>
void merge(std::vector<Object>& arr, std::vector<Object>TempArr, unsigned int left, unsigned int rightPos,unsigned int rightEnd);

template<typename Object>
void heapSort(std::vector<Object>& arr);

inline unsigned int leftChild(unsigned int i);

template<typename Object>
void percDown(std::vector<Object>& arr, long int pos, unsigned int size);

template<typename Object>
void radixSort(std::vector<Object>& arr);

template<typename Object>
Object getMax(const std::vector<Object>& arr);
template<class T2>
void showArr(std::vector<T2>& arr);


#endif


