#include <iostream>
#include <chrono>
#include <random>

// Сортировка выбором (Selection Sort)
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// Функция для выделения динамического буфера заданного размера и заполнения его случайными числами
int* createRandomArray(int size) {
    // Выделение памяти под массив
    int* arr = new int[size];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); 

    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }

    return arr;
}
// Слияние отсортированных массивов для сортировки слиянием (Merge Sort)
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

// Сортировка пузырьком (Bubble Sort)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Рекурсивная функция сортировки слиянием (Merge Sort)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

// Функция разбиения для быстрой сортировки (Quick Sort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Линейный поиск (Linear Search)
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Если элемент не найден
}

// Бинарный поиск (Binary Search)
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == key) {
            return middle;
        }

        if (arr[middle] < key) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1; // Если элемент не найден
}

void testSelectionSort(int size) {
    int* dynamicArray = createRandomArray(size);

    auto start_time = std::chrono::high_resolution_clock::now();
    selectionSort(dynamicArray, size);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Selection Sort: " << duration.count() << " microseconds" << std::endl;

    delete[] dynamicArray;
}

void testBubbleSort(int size) {
    int* dynamicArray = createRandomArray(size);

    auto start_time = std::chrono::high_resolution_clock::now();
    bubbleSort(dynamicArray, size);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Bubble Sort: " << duration.count() << " microseconds" << std::endl;

    delete[] dynamicArray;
}


void testMergeSort(int size) {
    int* dynamicArray = createRandomArray(size);

    auto start_time = std::chrono::high_resolution_clock::now();
    mergeSort(dynamicArray, 0, size - 1);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Merge Sort: " << duration.count() << " microseconds" << std::endl;

    delete[] dynamicArray;
}

void testQuickSort(int size) {
    int* dynamicArray = createRandomArray(size);

    auto start_time = std::chrono::high_resolution_clock::now();
    quickSort(dynamicArray, 0, size - 1);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Quick Sort: " << duration.count() << " microseconds" << std::endl;

    delete[] dynamicArray;
}

void testLinearSearch(int size, int key) {
    int* dynamicArray = createRandomArray(size);

    auto start_time = std::chrono::high_resolution_clock::now();
    int result = linearSearch(dynamicArray, size, key);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    if (result != -1) {
        std::cout << "Linear Search: Element found at index " << result << std::endl;
    } else {
        std::cout << "Linear Search: Element not found" << std::endl;
    }

    std::cout << "Execution Time for Linear Search: " << duration.count() << " microseconds" << std::endl;

    delete[] dynamicArray;
}

void testBinarySearch(int size, int key) {
    int* dynamicArray = createRandomArray(size);
    quickSort(dynamicArray, 0, size - 1); // Ensure array is sorted for binary search

    auto start_time = std::chrono::high_resolution_clock::now();
    int result = binarySearch(dynamicArray, 0, size - 1, key);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    if (result != -1) {
        std::cout << "Binary Search: Element found at index " << result << std::endl;
    } else {
        std::cout << "Binary Search: Element not found" << std::endl;
    }

    std::cout << "Execution Time for Binary Search: " << duration.count() << " microseconds" << std::endl;

    delete[] dynamicArray;
}

int main() {
// testSelectionSort(10);  0 microseconds
    // testSelectionSort(1000); 0 microseconds
    // testSelectionSort(10000); 115571 microseconds
    // testSelectionSort(100000); 11742064 microseconds
    // testSelectionSort(100500); 11355315 microseconds

    //testBubbleSort(10); // 0 microseconds
    //testBubbleSort(1000); // 0 microseconds
    //testBubbleSort(10000); // 408639 microseconds
    //testBubbleSort(100000); // 43232779 microseconds
    //testBubbleSort(100500); // 44125232 microseconds

    //testQuickSort(10); // 0 microseconds
    //testQuickSort(1000); // 0 microseconds
    //testQuickSort(10000); // 0 microseconds
    //testQuickSort(100000); // 129548 microseconds
    //testQuickSort(100500); // 133175 microseconds

    //testBinarySearch(10, 5); // 0 microseconds
    //testBinarySearch(1000, 5); // 0 microseconds
    //testBinarySearch(10000, 5); // 0 microseconds
    //testBinarySearch(100000, 5); // 0 microseconds
    //testBinarySearch(100500, 5); // 0 microseconds

    //testLinearSearch(10, 5); // 0 microseconds
    //testLinearSearch(1000, 5); // 0 microseconds
    //testLinearSearch(10000, 5); // 0 microseconds
    //testLinearSearch(100000, 5); // 0 microseconds
    //testLinearSearch(100500, 5); // 0 microseconds

    testBubbleSort(10000);
    testMergeSort(100000);
    testQuickSort(100000);
    testBinarySearch(100000, 5);
    testLinearSearch(100000, 5);
}
