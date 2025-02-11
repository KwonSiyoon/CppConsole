#include <iostream>

void Merge(int* array, int* leftArray, int leftLength, int* rightArray, int rightLength)
{
    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = 0;
    while (leftIndex < leftLength && rightIndex < rightLength)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            array[mergeIndex] = leftArray[leftIndex];
            ++leftIndex;
        }
        else
        {
            array[mergeIndex] = rightArray[rightIndex];
            ++rightIndex;
        }
        ++mergeIndex;
    }

    // 위에서 비교하며 넣고나서 왼쪽 혹은 오른쪽 배열이 남음.
    // 남은 배열 넣어주기.
    // 이미 Merge하면서 정렬이 되었기 때문에 남은거 순서대로 붙이면 끝.
    while (leftIndex < leftLength)
    {
        array[mergeIndex] = leftArray[leftIndex];
        ++mergeIndex;
        ++leftIndex;
    }
    while (rightIndex < rightLength)
    {
        array[mergeIndex] = rightArray[rightIndex];
        ++mergeIndex;
        ++leftIndex;
    }
}


void MergeSort(int* array, int length)
{
    if (length <= 1)
    {
        return;
    }

    int mid = length / 2;
    int leftLength = mid;
    int rightLength = length - mid;
    int* rightArray = new int[rightLength];
    int* leftArray = new int[leftLength];

    memcpy(leftArray, array, mid);
    memcpy(leftArray, array+mid, length-mid);

    MergeSort(leftArray, leftLength);
    MergeSort(rightArray, rightLength);

    Merge(array, leftArray, leftLength, rightArray, rightLength);

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
    MergeSort(array, length);
    PrintArray(array, length);
}