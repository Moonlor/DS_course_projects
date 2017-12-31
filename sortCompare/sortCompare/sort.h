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

//===========================冒泡排序==================================
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
        clock_t start_time=clock();         //计时开始
        {
            for (int i = 0; i < count - 1; i++) {
                bool flag = true;
                for (int j = 0; j < count - i - 1; j++) {
                    //当发生后一个元素小于前一个元素的情况，将后一个元素前移，与前面一个元素交换
                    if (_result[j] > _result[j+1]) {
                        int temp = _result[j + 1];
                        _result[j + 1] = _result[j];
                        _result[j] = temp;
                        swap_times++;
                        flag = false;
                    }
                }
                if (flag) break;
            }
        }
        clock_t end_time=clock();   //计时结束
        cout << "冒泡排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "冒泡排序交换次数：\t\t" << swap_times << endl;
        return _result;
    }
};

//=================================选择排序=====================================
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

//===============================直接插入排序=======================================
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
        clock_t start_time=clock();     //计时开始
        {
            for (int i = 1; i < count; i++) {
                //当未排序元素的第一个元素小于已排序元素序列中的最后一个元素
                if(_result[i - 1] > _result[i]){
                    int temp = _result[i];  //将未排序元素的第一个元素选为目标插入元素
                    int j = i - 1;
                    //从已排序序列的最后一个元素开始向前搜索，将已排序元素一一向后移位，直至可以插入目标元素
                    for (; j >= 0 && _result[j] > temp; j--) {
                        _result[j + 1] = _result[j];
                        swap_times++;
                    }
                    _result[j + 1] = temp;
                    swap_times++;
                }
            }
        }
        clock_t end_time=clock();       //计时结束
        cout << "直接插入排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "直接插入排序交换次数：\t\t" << swap_times / 2 << endl;
        return _result;
    }
};

//===================================希尔排序===================================
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
        clock_t start_time=clock();     //计时开始
        {
            int gap = 1;
            //以gap = 1的最终值进行反推，求出gap增量序列的最大值
            while (gap <= count / 3) {
                gap = gap * 3 + 1;
            }
            while (gap > 0) {
                for (int i = gap; i < count; i++) {
                    //按gap将无序序列分为count/gap个组，对每个组进行插入排序
                    if(_result[i - gap] > _result[i]){
                        //将此时的较小值保存
                        int temp = _result[i];
                        int j = i - gap;
                        //从较大值开始，将其一个一个后移，直到找到合适的插入位置
                        for (; j >= 0 && _result[j] > temp; j -= gap) {
                            _result[j + gap] = _result[j];
                            swap_times++;
                        }
                        //当前值比保存值还小时，则证明上一个位置是正确位置，将之前保存的值插入
                        _result[j + gap] = temp;
                        swap_times++;
                    }
                }
                //得到下一个gap序列值
                gap = (gap - 1) / 3;
            }
        }
        clock_t end_time=clock();       //计时结束
        cout << "希尔插入排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "希尔插入排序交换次数：\t\t" << swap_times / 2 << endl;
        return _result;
    }
};

//===================================快速排序===================================
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
        //当左右索引重合时，递归结束，序列已经有序
        if(left_index < right_index){
            int key_value = target[left_index];     //主元
            int low_index = left_index;             //左起点
            int high_index = right_index;           //右起点
            //此时主元素所在的位置为空位
            while (low_index < high_index) {
                //从右边开始搜索，直到发现比主元小的元素
                while (low_index < high_index && key_value < target[high_index]) {
                    high_index--;
                }
                //将找到的较小元素放入到空出来的位置，此时其原位置为空，可被放置一个较大元素
                target[low_index] = target[high_index];
                _swap_times++;
                //从左边继续搜索，直到发现比主元大的元素
                while (low_index < high_index && key_value > target[low_index]) {
                    low_index++;
                }
                //将找到的较大元素放入刚刚空出来的位置，此时其原位置为空，可被放置一个较小元素
                target[high_index] = target[low_index];
                _swap_times++;
            }
            //将主元素填入交换完成后剩下的空位，此时主元素左边的所有元素均小于主元素，右边均大于主元素
            target[low_index] = key_value;
            _swap_times++;
            //分别对左右序列进行递归
            quickSort(target, left_index, low_index - 1);
            quickSort(target, low_index + 1, right_index);
        }
    }
    
    int *sort(int *numbers, int count){
        _result = new int[count]();
        for (int i = 0; i < count; i++) {
            _result[i] = numbers[i];
        }
        clock_t start_time=clock();     //开始计时
        {
            //调用递归函数进行快速排序，初始下待排序数组左下标为0，右下标为数组元素个数-1
            quickSort(_result, 0, count - 1);
        }
        clock_t end_time=clock();       //计时结束
        cout << "快速排序所用时间：\t\t" << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
        cout << "快速排序交换次数：\t\t" << _swap_times << endl;
        return _result;
    }
};


//=====================================堆排序=================================
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
        for (int i = 2*start + 1; i <= end; i = i * 2 + 1) {
            //i为左节点, i+1为右节点
            //将i调整为指向左、右节点中较大节点的索引
            if(heap[i] < heap[i + 1] && i + 1 <= end){
                i++;
            }
            //如果左右节点中的较大值都比父节点小，则无需调整
            if(heap[i] < temp){
                break;
            }
            //将左右节点中较大的值与父节点的值交换
            //此次调整可能会造成较大值节点所在的子树不平衡，不再满足大顶堆的性质
            //以较大值节点为下一次循环的父节点，继续自上而下调整
            heap[start] = heap[i];
            start = i;
            _swap_times++;
        }
        //将调整结束后原顶部元素放置到适当的位置
        heap[start] = temp;
        _swap_times++;
    }
    
    void heapSort(int *heap, int count)
    {
        //从第倒数第一个非叶子节点开始，自下而上调整堆使其成为大顶堆
        for (int i = (count - 1) / 2; i >= 0; i--) {
            adjustHeap(heap, i, count - 1);
        }
        //每次取出堆顶端的元素，即取出最大元素放入堆的末尾，之后调整时不再对末尾有序元素进行调整
        //进行n-1次取值和调整后，存放堆的数组从0开始即位一个有序数组
        for (int i = count - 1; i >= 0; i--) {
            //交换堆顶值与末尾值
            int temp = heap[i];
            heap[i] = heap[0];
            heap[0] = temp;
            _swap_times++;
            //交换完成后调整堆使其依然保持为大顶堆
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

//============================归并排序==========================================
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
        int first_index = start;    //第一个待合并序列的起点
        int second_index = mid + 1; //第二个待合并序列的起点
        int out_index = start;      //合并结果的有序序列的起点
        while (first_index <= mid && second_index <= end) {
            //如果第一个序列的值小于第二个序列的值
            if(input[first_index] < input[second_index]){
                //将第一个序列的值插入有序序列
                output[out_index++] = input[first_index++];
                _swap_times++;
            }else{//如果第一个序列的值大于第二个序列的值
                output[out_index++] = input[second_index++];
                //将第二个序列的值插入有序序列
                _swap_times++;
            }
        }
        //如果两个序列中已经有一个序列插入完成
        //将第一个序列剩余的元素直接插入有序序列
        while (first_index <= mid) {
            output[out_index++] = input[first_index++];
            _swap_times++;
        }
        //将第二个序列剩余的元素直接插入有序序列
        while (second_index <= end) {
            output[out_index++] = input[second_index++];
            _swap_times++;
        }
        //将合并结果放回原数组中
        for (int i = start; i <= end; i++) {
            input[i] = output[i];
            _swap_times++;
        }
    }
    
    void msort(int *numbers, int start, int end){
        if(start < end){
            int mid = (start + end) / 2;
            //对左边序列进行排序
            msort(numbers, start, mid);
            //对右边序列进行排序
            msort(numbers, mid + 1, end);
            //将左右两边的有序序列合并为一个有序序列
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
