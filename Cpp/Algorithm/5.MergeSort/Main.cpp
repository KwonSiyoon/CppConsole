#include <iostream>

// 병합 함수(Merge).
// array : 병합할 배열 변수.
// leftArray : 왼쪽 배열 변수.
// leftArrayLength : 왼쪽 배열 크기.
// rightArray : 오른쪽 배열 변수.
// rightArrayLength : 오른쪽 배열 크기.
void Merge(int* array, int* leftArray, int leftArrayLength, int* rightArray, int rightArrayLength)
{
    // 인덱스 변수 선언.
    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = 0;
    
    // 왼쪽/오른쪽 배열의 요소를 비교하면서 작은 순서로 array에 값 할당.
    while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
    {
        // 왼쪽/오른쪽 비교.
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            array[mergedIndex] = leftArray[leftIndex];
            ++leftIndex;
        }
        else
        {
            array[mergedIndex] = rightArray[rightIndex];
            ++rightIndex;
        }

        ++mergedIndex;
    }

    // 위 과정에서 남은 왼쪽 배열 요소를 최종 배열에 복사.
    while (leftIndex < leftArrayLength)
    {
        array[mergedIndex] = leftArray[leftIndex];
        ++mergedIndex;
        ++leftIndex;
    }

    // 위 과정에서 남은 오른쪽 배열 요소를 최종 배열에 복사.
    while (rightIndex < rightArrayLength)
    {
        array[mergedIndex] = rightArray[rightIndex];
        ++mergedIndex;
        ++rightIndex;
    }
}


// 병합 정렬 함수.
void MergeSort(int* array, int length)
{
    // 탈출 조건.
    if (length <= 1)
    {
        return;
    }

    // 배열 분할(나누기).
    int mid = length / 2;
    int* leftArray = new int[mid];
    int* rightArray = new int[length - mid];

    // 값 복사.
    memcpy(leftArray, array, sizeof(int) * mid);
    memcpy(rightArray, array + mid, sizeof(int) * (length - mid));

    // 재귀적 호출.
    // 왼쪽 배열에 대해 재귀 호출.
    MergeSort(leftArray, mid);
    // 오른쪽 배열에 대해 재귀 호출.
    MergeSort(rightArray, length-mid);

    // 병합.
    Merge(array, leftArray, mid, rightArray, length - mid);


    // 메모리 해제.
    delete[] leftArray;
    delete[] rightArray;

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