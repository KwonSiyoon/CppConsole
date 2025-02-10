#include <iostream>

// 삽입 정렬 함수.
void InsertionSort(int* array, int length)
{
    // 배열 순회.
    for (int i = 1; i < length; ++i)
    {
        // 키 뽑기.
        int keyValue = array[i];
        int j = i - 1;

        // 셔플링(교환).
        while (j >= 0 && array[j] > keyValue)
        {
            array[j + 1] = array[j];
            --j;
        }

        // 값 끼우기.
        array[j + 1] = keyValue;
    }
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
    int length = sizeof(array) / sizeof(int);
    // 출력.
    std::cout << "정렬 전: ";
    PrintArray(array, length);

    // 정렬.
    std::cout << "정렬 후: ";
    InsertionSort(array, length);
    PrintArray(array, length);


    std::cin.get();
}