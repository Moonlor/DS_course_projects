//
//  sort.h
//  sortCompare
//
//  Created by 李坤 on 2017/11/7.
//  Copyright © 2017年 李坤. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <vector>
#include <cmath>

class BubbleSort {
private:
    int *_result;
public:
    BubbleSort(){
        _result = nullptr;
    }
    
    ~BubbleSort(){
        delete [] _result;
    }
    
    int *sort(int *numbers, int count){
        _result = new int[count]();
        for (int i = 0; i < count; i++) {
            _result[i] = numbers[i];
        }
        unsigned int swap_times = 0;
        clock_t start_time=clock();
        {
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (_result[j] > _result[j+1]) {
                        int temp = _result[j + 1];
                        _result[j + 1] = _result[j];
                        _result[j] = temp;
                        swap_times++;
                    }
                }
            }
        }
        clock_t end_time=clock();
        cout << "冒泡排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "冒泡排序交换次数：\t\t" << swap_times << endl;
        return _result;
    }
};

//======================================================================
class SelectionSort {
private:
    int *_result;
public:
    SelectionSort(){
        _result = nullptr;
    }
    
    ~SelectionSort(){
        delete [] _result;
    }
    
    int *sort(int *numbers, int count){
        _result = new int[count]();
        for (int i = 0; i < count; i++) {
            _result[i] = numbers[i];
        }
        unsigned int swap_times = 0;
        clock_t start_time=clock();
        {
            for (int i = 0; i < count - 1; i++) {
                for (int j = i; j < count; j++) {
                    if(_result[j] < _result[i]){
                        int temp = _result[j];
                        _result[j] = _result[i];
                        _result[i] = temp;
                        swap_times++;
                    }
                }
            }
        }
        clock_t end_time=clock();
        cout << "选择排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "选择排序交换次数：\t\t" << swap_times << endl;
        return _result;
    }
};

//======================================================================
class DirectionInsertionSort {
private:
    int *_result;
public:
    DirectionInsertionSort(){
        _result = nullptr;
    }
    
    ~DirectionInsertionSort(){
        delete [] _result;
    }
    
    int *sort(int *numbers, int count){
        _result = new int[count]();
        for (int i = 0; i < count; i++) {
            _result[i] = numbers[i];
        }
        unsigned int swap_times = 0;
        clock_t start_time=clock();
        {
            for (int i = 1; i < count; i++) {
                if(_result[i - 1] > _result[i]){
                    int temp = _result[i];
                    int j = i - 1;
                    for (; j >= 0 && _result[j] > temp; j--) {
                        _result[j + 1] = _result[j];
                        swap_times++;
                    }
                    _result[j + 1] = temp;
                    swap_times++;
                }
//                int current = _result[i+1];
//                int j = 0;
//                for (; j < i + 1; j++) {
//                    if(_result[j] > current){
//                        break;
//                    }
//                }
//                int temp = _result[i + 1];
//                for (int k = i + 1; k > j; k--) {
//                    _result[k] = _result[k - 1];
//                    swap_times++;
//                }
//                _result[j] = temp;
//                swap_times++;
            }
        }
        clock_t end_time=clock();
        cout << "直接插入排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "直接插入排序交换次数：\t\t" << swap_times / 2 << endl;
        return _result;
    }
};

//======================================================================
class ShellSort {
private:
    int *_result;
public:
    ShellSort(){
        _result = nullptr;
    }
    
    ~ShellSort(){
        delete [] _result;
    }
    
    int *sort(int *numbers, int count){
        _result = new int[count]();
        for (int i = 0; i < count; i++) {
            _result[i] = numbers[i];
        }
        unsigned int swap_times = 0;
        clock_t start_time=clock();
        {
            int gap = 1;
            while (gap <= count / 3) {
                gap = gap * 3 + 1;
            }
            while (gap > 0) {
                for (int i = gap; i < count; i += gap) {
                    if(_result[i - gap] > _result[i]){
                        int temp = _result[i];
                        int j = i - gap;
                        for (; j >= 0 && _result[j] > temp; j -= gap) {
                            _result[j + gap] = _result[j];
                            swap_times++;
                        }
                        _result[j + gap] = temp;
                        swap_times++;
                    }
                }
                gap = (gap - 1) / 3;
            }
        }
        clock_t end_time=clock();
        cout << "希尔插入排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "希尔插入排序交换次数：\t\t" << swap_times / 2 << endl;
        return _result;
    }
};

//======================================================================
class QuickSort {
private:
    int *_result;
    unsigned int _swap_times;
public:
    QuickSort(){
        _swap_times = 0;
        _result = nullptr;
    }
    
    ~QuickSort(){
        delete [] _result;
    }
    
    void quickSort(int *target, int left_index, int right_index){
        if(left_index < right_index){
            int key_value = target[left_index];
            int low_index = left_index;
            int high_index = right_index;
            while (low_index < high_index) {
                while (low_index < high_index && key_value < target[high_index]) {
                    high_index--;
                }
                target[low_index] = target[high_index];
                _swap_times++;
                while (low_index < high_index && key_value > target[low_index]) {
                    low_index++;
                }
                target[high_index] = target[low_index];
                _swap_times++;
            }
            target[low_index] = key_value;
            _swap_times++;
            quickSort(target, left_index, low_index - 1);
            quickSort(target, low_index + 1, right_index);
        }
    }
    
    int *sort(int *numbers, int count){
        _result = new int[count]();
        for (int i = 0; i < count; i++) {
            _result[i] = numbers[i];
        }
        clock_t start_time=clock();
        {
            quickSort(_result, 0, count - 1);
        }
        clock_t end_time=clock();
        cout << "快速排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "快速排序交换次数：\t\t" << _swap_times << endl;
        return _result;
    }
};


//======================================================================
class HeapSort {
private:
    int *_result;
    unsigned int _swap_times;
public:
    HeapSort(){
        _swap_times = 0;
        _result = nullptr;
    }
    
    ~HeapSort(){
        delete [] _result;
    }
    
    void adjustHeap(int *heap, int start, int end){
        int temp = heap[start];//start为堆顶部
        for (int i = 2*start + 1; i <= end; i = i * 2 + 1) {//i为左节点, i+1为右节点
            if(heap[i] < heap[i + 1] && i + 1 <= end){
                i++;
            }
            if(heap[i] < temp){
                break;
            }
            heap[start] = heap[i];
            start = i;
            _swap_times++;
        }
        heap[start] = temp;
        _swap_times++;
    }
    
    void heapSort(int *heap, int count)
    {
        for (int i = (count - 1) / 2; i >= 0; i--) {
            adjustHeap(heap, i, count - 1);
        }
        
        for (int i = count - 1; i >= 0; i--) {
            int temp = heap[i];
            heap[i] = heap[0];
            heap[0] = temp;
            _swap_times++;
            
            adjustHeap(heap, 0, i - 1);
        }
    }
    
    int *sort(int *numbers, int count){
        _result = new int[count]();
        for (int i = 0; i < count; i++) {
            _result[i] = numbers[i];
        }
        clock_t start_time=clock();
        {
            heapSort(_result, count);
        }
        clock_t end_time=clock();
        cout << "堆排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "堆排序交换次数：\t\t" << _swap_times << endl;
        return _result;
    }
};

//======================================================================
class MergeSort {
private:
    int *_result;
    int *_buffer;
    unsigned int _swap_times;
public:
    MergeSort(){
        _swap_times = 0;
        _result = nullptr;
        _buffer = nullptr;
    }
    
    ~MergeSort(){
        delete [] _result;
        delete [] _buffer;
    }
    
    void merge(int* input, int start, int mid, int end, int* output)
    {
        int first_index = start;
        int second_index = mid + 1;
        int out_index = start;
        while (first_index <= mid && second_index <= end) {
            if(input[first_index] < input[second_index]){
                output[out_index++] = input[first_index++];
                _swap_times++;
            }else{
                output[out_index++] = input[second_index++];
                _swap_times++;
            }
        }
        while (first_index <= mid) {
            output[out_index++] = input[first_index++];
            _swap_times++;
        }
        while (second_index <= end) {
            output[out_index++] = input[second_index++];
            _swap_times++;
        }
        for (int i = start; i <= end; i++) {
            input[i] = output[i];
            _swap_times++;
        }
    }
    
    void msort(int *numbers, int start, int end){
        if(start < end){
            int mid = (start + end) / 2;
            msort(numbers, start, mid);
            msort(numbers, mid + 1, end);
            merge(numbers, start, mid, end, _buffer);
        }
    }
    
    int *sort(int *numbers, int count){
        _result = new int[count]();
        _buffer = new int[count]();
        for (int i = 0; i < count; i++) {
            _result[i] = numbers[i];
        }
        clock_t start_time=clock();
        {
            msort(_result, 0, count - 1);
        }
        clock_t end_time=clock();
        cout << "归并排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "归并排序交换次数：\t\t" << _swap_times << endl;
        return _result;
    }
};

//======================================================================
class RadixSort {
private:
    int *_result;
    int *_buffer;
    unsigned int _swap_times;
public:
    RadixSort(){
        _swap_times = 0;
        _result = nullptr;
        _buffer = nullptr;
    }
    
    ~RadixSort(){
        delete [] _result;
    }
    
    int getBitNumber(int *bucket, int index, int bit){
        int n = bucket[index] / (int)pow(10, bit) - (bucket[index] / (int)pow(10, bit + 1)) * 10;
        return n;
    }
    
    int* radixSort(int *target, int bit, int total_number){
        int* count = new int[10]();
        int* bucket = new int[total_number]();
        int number_of_zeros = 0;
        
        for (int i = 0; i < total_number; i++) {
            count[getBitNumber(target, i, bit)]++;
        }
        
        number_of_zeros = count[0];
        
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        for (int i = total_number - 1; i >= 0; i--) {
            int temp_bit = getBitNumber(target, i, bit);
            bucket[count[temp_bit] - 1] = target[i];
            _swap_times++;
            count[temp_bit]--;
        }
        
        if(number_of_zeros == total_number){
            return bucket;
        }else{
            return radixSort(bucket, bit + 1, total_number);
        }
    }
    
    int *sort(int *numbers, int count){
        _result = new int[count]();
        for (int i = 0; i < count; i++) {
            _result[i] = numbers[i];
        }
        clock_t start_time=clock();
        {
            int *temp = radixSort(_result, 0, count);
            for (int i = 0; i < count; i++) {
                _result[i] = temp[i];
            }
        }
        clock_t end_time=clock();
        cout << "基数排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "基数排序交换次数：\t\t" << _swap_times << endl;
        return _result;
    }
};


#endif /* sort_h */
