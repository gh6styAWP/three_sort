#include <iostream>
#include <ctime>
using namespace std;
//сортировка пузырьком
void Bubble(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << endl;
    
    //вывод отсортированного массива
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
//шейкерная сортировка (улучшенная сортировка пузырьком)
void Shaker(int arr[], int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;
        
        //проход массива слева направо
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        //уменьшаем конец
        swapped = false;
        end--;

        //проход массива справа налево
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        //увеличиваем начало
        start++;
    }
}
//сортировка расческой (улучшенная сортировка пузырьком)
void Comb(int arr[], int size) {
    //изначальный шаг выбирается как размер массива
    int gap = size;
    bool swapped = true;

    //постепенное уменьшение шага до 1
    while (gap != 1 || swapped) {

        //вычисление нового шага
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        swapped = false;

        //сравнение элементов на расстоянии gap друг от друга
        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

//сортировка выбором
void Choice(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp = arr[0];
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << endl;

    //вывод отсортированного массива
    for (int i = 0; i < size; i++)    
        cout << arr[i] << " "; 
}

//сортировка вставками
void Insert(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j;
        int buff = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > buff; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = buff;
    }
    cout << endl;

    //вывод отсортированного массива
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
//сортировка Шелла (улучшенная сортировка вставками)
void Shell(int arr[], int size)
{
    //начинаем с большого шага и постепенно уменьшаем его
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        //сортировка вставками для текущего шага
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;

            //перемещаем элементы, которые находятся на расстоянии gap, и больше текущего элемента
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];            
            arr[j] = temp;
        }
    }
}

//быстрая сортировка (сортировка Хоара)
void Quick(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2]; //делаем центральное значение опорным элементом

    //делим массив на части
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    //рекурсивные вызовы для обеих частей
    if (left < j) Quick(arr, left, j);
    if (i < right) Quick(arr, i, right);

}

//функция слияния двух отсортированных массивов 
void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //создаем временные массивы
    int* L = new int[n1];
    int* R = new int[n2];

    //копируем данные во временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    //индексы для перебора временных массивов и основного массива
    int i = 0; int j = 0; int k = left;

    //объединение временных массивов обратно в основной arr
    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //копируем оставшиеся элементы L[] если есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    //копируем оставшиеся элементы R[] если есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    //очистка временных массивов
    delete[] R;
    delete[] L;
}
//сортировка слиянием
void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        //сортировка первой и второй половины
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        //сливаем отсортированные массивы
        Merge(arr, left, mid, right);
    }
}

//вспомогательная функция для построения кучи
void Heapify(int arr[], int size, int root) {
    //изначально корень считаем наибольшим элементом
    int largest = root;

    //левый дочерний элемент
    int left = 2 * root + 1;

    //правый дочерний элемент
    int right = 2 * root + 2;

    //если левый дочерний элемент больше корня
    if (left < size && arr[left] > arr[largest])
        largest = left;

    //если правый дочерний элемент больше текущего наибольшего элемента
    if (right < size && arr[right] > arr[largest])
        largest = right;

    //если наибольший элемент не корень
    if (largest != root) {
        swap(arr[root], arr[largest]);

        //рекурсивно преобразуем затронутое поддерево
        Heapify(arr, size, largest);
    }
}
//сортировка кучей (пирамидальная)
void Heap(int arr[], int size) {
    //построение кучи
    for (int i = size / 2 - 1; i >= 0; i--)
        Heapify(arr, size, i);

    //один за другим извлекаются элементы из кучи
    for (int i = size - 1; i > 0; i--) {

        //корень перемещается в конец
        swap(arr[0], arr[i]);

        //вызывается heapify на уменьшенной куче
        Heapify(arr, i, 0);
    }
}

//генерация случайного массива
void MassGen(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 101 - 50;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size;)
        {
            if (arr[i] == arr[j])
                arr[i] = rand() % 101 - 50;
            else(j++);
        }
        cout << arr[i] << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    srand(time(NULL));
    int size;
    int chose;

    cout << "Здравствуйте, выберите тип сортировки:\n";
    cout << "1 - Пузырьковая, 2 - Выбором, 3 - Вставками\n";
    cout << "4 - Быстрая, 5 - Слиянием, 6 - Кучей\n";
    cout << "7 - Шелла, 8 - Шейкерная, 9 - Расчёской";
    cout << endl;
    cin >> chose;
    cout << endl;

    cout << "Введите размер массива" << endl;
    cin >> size;
    int* arr = new int[size];
    cout << endl;

    switch (chose)
    {
    case 1:
        cout << "Сортировка пузырьком:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";

        Bubble(arr, size);
        cout << " - отсортированный массив\n";

        break;

    case 2:
        cout << "Сортировка выбором:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";

        Choice(arr, size);
        cout << " - отсортированный массив\n";

        break;

    case 3:
        cout << "Сортировка вставками:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";

        Insert(arr, size);
        cout << " - отсортированный массив\n";

        break;

    case 4: 
        cout << "Быстрая сортировка:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";

        Quick(arr, 0, size - 1);

        for (int i = 0; i < size; i++)
            cout << arr[i] << " "; 
        cout << " - отсортированный массив\n";

        break;

    case 5:
        cout << "Сортировка слиянием:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";
       
        MergeSort(arr, 0, size - 1);

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << " - отсортированный массив\n";

        break;

    case 6: 
        cout << "Сортировка кучей:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";

        Heap(arr, size);

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << " - отсортированный массив\n";

        break;

    case 7:
        cout << "Сортировка Шелла:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";

        Shell(arr, size);

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << " - отсортированный массив\n";

        break;

    case 8:
        cout << "Шейкерная сортировка:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";

        Shaker(arr, size);

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << " - отсортированный массив\n";

        break;

    case 9:
        cout << "Сортировка расческой:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";

        Comb(arr, size);

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << " - отсортированный массив\n";

        break;
    }
    
}
