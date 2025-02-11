#include <iostream>
#include <vector>

void Heapify(std::vector<int>& array, int length, int idx)
{
    while (true)
    {
        int largest = idx;              // 힙 구성을 위한 인덱스 변수.
        int left = 2 * idx + 1;         // 왼쪽 자손 인덱스.
        int right = 2 * idx + 2;        // 오른쪽 자손 인덱스.

        if (left < length && array[left] > array[largest])
        {
            largest = left;
        }
        if (right < length && array[right] > array[largest])
        {
            largest = right;
        }
        if (largest == idx)
        {
            break;
        }
        std::swap(array[idx], array[largest]);
        idx = largest;
    }
}

void HeapSort(std::vector<int>& array)
{
    int length = (int)array.size();
    for (int i = length / 2 - 1; i >= 0; --i)
    {
        // 힙(자료구조) 만들기.
        Heapify(array, length, i);
    }

    // 정렬.
    for (int i = length - 1; i > 0; --i)
    {
        std::swap(array[0], array[i]);
        Heapify(array, i, 0);
    }

}

// 배열 출력 함수.
void PrintArray(std::vector<int> array)
{
    int length = (int)array.size();
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << (i < length - 1 ? ", " : "");
    }

    std::cout << "\n";
}


int main()
{
    std::vector<int> array = { 5,3,2,6,8,10,20,7,46,23,345,34,1,7,24,52,31,52,35,46,56,58 };
    // 배열 길이.
    //int length = sizeof(array) / sizeof(int);
    //int length = _countof(array);
    //int length = array.size();
    
    // 출력.
    std::cout << "정렬 전: ";
    PrintArray(array);

    // 정렬.
    std::cout << "정렬 후: ";
    HeapSort(array);
    PrintArray(array);
}