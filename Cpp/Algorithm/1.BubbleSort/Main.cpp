#include <iostream>


void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 버블 정렬 함수.
void BubbleSort(int* array, int length)
{
    // 정렬.
    for (int i = 0; i < length - 1; ++i)
    {
        for (int j = 0; j < length - 1 - i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                Swap(array[j], array[j + 1]);
            }
        }
    }
}

void PrintArray(int* array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << " ";
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
    BubbleSort(array, length);
    PrintArray(array, length);


}