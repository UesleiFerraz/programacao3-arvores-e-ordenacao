#include <cstdlib>
#include <unordered_set>
#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
using namespace std;

enum methodOfGeneration {
    ASC_ORDENED,
    DESC_ORDENED,
    RANDOM_WITHOUT_REPETITION,
    RANDOM_WITH_REPETITION
};

enum methodOfSorting {
    BUBBLE_SORT,
    INSERTION_SORT,
    SELECTION_SORT,
    HEAP_SORT,
    SHELL_SORT,
    MERGE_SORT,
    QUICK_SORT
};

void generateArray(int *array, int size, int method) {
    unordered_set<int> uniqueNumbers;
    int generatedNumber;
    switch (method) {
        case ASC_ORDENED:
            for (int i = 0; i < size; i++) {
                array[i] = i;
            }
            break;
        case DESC_ORDENED:
            for (int i = 0; i < size; i++) {
                array[i] = size - i;
            }
            break;
        case RANDOM_WITHOUT_REPETITION: 
            for (int i = 0; i < size; i++) {
                do {
                    generatedNumber = rand();
                } while (uniqueNumbers.find(generatedNumber) != uniqueNumbers.end());
                uniqueNumbers.insert(generatedNumber);
                array[i] = generatedNumber;
            }
            break;
        case RANDOM_WITH_REPETITION:
            for (int i = 0; i < size; i++) {
                array[i] = rand();
            }
            break;
        default:
            break;
    }
}

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

void insertionSort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && array[j] < array[j - 1]) {
            int aux = array[j];
            array[j] = array[j - 1];
            array[j - 1] = aux;
            j--;
        }
    }
}

void selectionSort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        int aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
}

void heapify(int *array, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && array[left] > array[largest]) {
        largest = left;
    }
    if (right < size && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != i) {
        int aux = array[i];
        array[i] = array[largest];
        array[largest] = aux;
        heapify(array, size, largest);
    }
}

void heapSort(int *array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        int aux = array[0];
        array[0] = array[i];
        array[i] = aux;
        heapify(array, i, 0);
    }
}

void shellSort(int *array, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void merge(int *array, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = array[middle + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            int aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }
    int aux = array[i + 1];
    array[i + 1] = array[high];
    array[high] = aux;
    return i + 1;
}

void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void sortArray(int *array, int size, int method) {
    switch (method) {
        case BUBBLE_SORT:
            bubbleSort(array, size);
            break;
        case INSERTION_SORT:
            insertionSort(array, size);
            break;
        case SELECTION_SORT:
            selectionSort(array, size);
            break;
        case HEAP_SORT:
            heapSort(array, size);
            break;
        case SHELL_SORT:
            shellSort(array, size);
            break;
        case MERGE_SORT:
            mergeSort(array, 0, size - 1);
            break;
        case QUICK_SORT:
            quickSort(array, 0, size - 1);
            break;
        default:
            break;
    }
}

long double calculateAverage(long long *array, int size) {
    long double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

long double calculateVariance(long long *array, int size) {
    long double average = calculateAverage(array, size);
    long double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(array[i] - average, 2);
    }
    return sum / (size - 1);
}

long double calculateStandardDeviation(long long *array, int size) {
    return sqrt(calculateVariance(array, size));
}

long double calculateAverageWithoutOutliers(long long *array, int size) {
    long double average = calculateAverage(array, size);
    long double standardDeviation = calculateStandardDeviation(array, size);
    long double sum = 0;
    long double count = 0;
    for (int i = 0; i < size; i++) {
        if (abs(array[i] - average) < standardDeviation) {
            sum += array[i];
            count++;
        }
    }
    return sum / count;
}

string formatToTwoDecimalPlaces(long double value) {
    ostringstream out;
    if (value != value) {
        return "0.00";
    }

    out << fixed << setprecision(2) << value;
    return out.str();
}

string generateHeaderInMarkdown() {
    string result = "| Tamanho do Array (n) | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort (Original) | Merge Sort | Quick Sort (Pivot no final) |";
    result += "\n| --- | --- | --- | --- | --- | --- | --- | --- |";
    return result;
}

string getMethodOfGeneration(int method) {
    switch (method) {
        case ASC_ORDENED:
            return "Ordenado de forma ascendente";
        case DESC_ORDENED:
            return "Ordenado de forma descendente";
        case RANDOM_WITHOUT_REPETITION:
            return "Aleatório sem repetição";
        case RANDOM_WITH_REPETITION:
            return "Aleatório com repetição";
        default:
            return "";
    }
}

void generateArrayAndTest() {
  string resultFinal = "";
  for (int methodOfGeneration = 0; methodOfGeneration <= 3; methodOfGeneration++) {
    resultFinal += "\n## Método de Geração: " + getMethodOfGeneration(methodOfGeneration) + "\n";
    resultFinal += generateHeaderInMarkdown();

    for (int size = 128; size <= 65536; size *= 2) {
      resultFinal += "\n| " + to_string(size) + " |";
      for (int methodOfSorting = 0; methodOfSorting <= 6; methodOfSorting++) {
        long long results[10];

        for (int i = 0; i < 10; i++) {
          int array[size];
          generateArray(array, size, methodOfGeneration);

          auto start = chrono::high_resolution_clock::now();
          sortArray(array, size, methodOfSorting);
          auto end = chrono::high_resolution_clock::now();

          auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
          results[i] = duration;

        }
        cout << resultFinal << endl;

        double average = calculateAverageWithoutOutliers(results, 10);
        resultFinal += " " + formatToTwoDecimalPlaces(average) + "ns |";
      }

    }
  }

  ofstream file;
  file.open("results.md");
  file << resultFinal;
  file.close();
}

int main() {
  generateArrayAndTest();
  return 0;
}