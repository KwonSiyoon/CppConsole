#include <iostream>

// 피벗(Pivot) 선택 함수.
int Partition(int* array, int left, int right)
{
    // 피벗 선택.
    int first = left;
    int pivot = array[first];

    // 다음 위치로 이동.
    ++left;

    // 두 인덱스가 서로 교차할 때까지 진행.
    while (left <= right)
    {
        // left는 pivot보다 큰 값 검색.
        while (array[left] <= pivot)
        {
            ++left;
        }

        // right는 pivot보다 작은 값 검색.
        while (array[right] > pivot)
        {
            --right;
        }

        // left와 right가 교차하지 않았을 때만 값 교환.
        if (left >= right)
        {
            break;
        }
        std::swap(array[left], array[right]);

        //// left와 right가 교차하지 않았을 때만 값 교환.
        //if (left < right)
        //{
        //    std::swap(array[left], array[right]);
        //}
        //else
        //{
        //    break;
        //}
    }

    // 교환.
    std::swap(array[first], array[right]);

    // 피벗 반환.
    return right;

}



// 퀵 정렬 함수.
void QuickSort(int* array, int left, int right)
{
    // 탈출 조건.
    if (left >= right)
    {
        return;
    }

    // 분할
    int partition = Partition(array, left, right);

    // 왼쪽 배열 퀵 정렬.
    QuickSort(array, left, partition - 1);
    
    
    // 오른쪽 배열 퀵 정렬.
    QuickSort(array, partition + 1, right);



}

// 배열 출력 함수.
void PrintArray(int* array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << (i < length - 1 ? ", " : "");
    }

    std::cout << "\n";
}

int main()
{
    int array[] = { 5,3,2,6,8,10,20,7,46,23,345,34,1,7,24,52,31,52,35,46,56,58 };
    // 배열 길이.
    //int length = sizeof(array) / sizeof(int);
    int length = _countof(array);
    // 출력.
    std::cout << "정렬 전: ";
    PrintArray(array, length);

    // 정렬.
    std::cout << "정렬 후: ";
    QuickSort(array, 0,length-1);
    PrintArray(array, length);
}