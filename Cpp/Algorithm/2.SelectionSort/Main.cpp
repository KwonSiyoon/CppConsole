#include <iostream>

void SelectionSort(int* array, int length)
{
    for (int i = 0; i < length - 1; ++i)
    {
        // 최소값 저장할 변수.
        int minIndex = i;
        for (int j = i + 1; j < length; ++j)
        {
            // 비교.
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        // 값 바꾸기.
        std::swap<int>(array[i], array[minIndex]);
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
    SelectionSort(array, length);
    PrintArray(array, length);

}