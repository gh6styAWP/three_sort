﻿#include <iostream>
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
//сортировка кучей (пирамидальная)
void Heap() {

}
//сортировка Шелла (улучшенная сортировка вставками)
void Shell(){
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
    cout << "4 - Быстрая, 5 - Слиянием";
    cin >> chose;

    cout << "Введите размер массива" << endl;
    cin >> size;
    int* arr = new int[size];

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
        cout << " - отсортированный массив\n";

        for (int i = 0; i < size; i++)
            cout << arr[i] << " "; 
        cout << endl;

        break;

    case 5:
        cout << "Сортировка слиянием:\n";

        MassGen(arr, size);
        cout << " - сгенерированный массив\n";
       
        MergeSort(arr, 0, size - 1);
        cout << " - отсортированный массив\n";

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;

        break;
    }
    


}
