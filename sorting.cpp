#include <iostream>
using namespace std;
class MergeSort
{
public:
    void sort(int *Array, int low, int high)
    {
        if (low == high)
            return;

        int mid = low + (high - low) / 2;
        sort(Array, low, mid);
        sort(Array, mid + 1, high);
        merge(Array, low, mid, high);
    }

private:
    void merge(int *Array, int low, int mid, int high)
    {
        int temp[high - low + 1];
        int i = low;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= high)
        {
            if (Array[i] <= Array[j])
            {
                temp[k] = Array[i];
                i++;
                k++;
            }
            else
            {
                temp[k] = Array[j];
                j++;
                k++;
            }
        }

        while (i <= mid)
        {
            temp[k] = Array[i];
            i++;
            k++;
        }

        while (j <= high)
        {
            temp[k] = Array[j];
            j++;
            k++;
        }

        k = 0;
        while (low <= high)
        {
            Array[low] = temp[k];
            low++;
            k++;
        }
    }
};

class BubbleSort
{
public:
    void sort(int *Array, int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (Array[j] > Array[j + 1])
                {
                    int temp = Array[j];
                    Array[j] = Array[j + 1];
                    Array[j + 1] = temp;
                }
            }
        }
    }
};

class SelectionSort
{
public:
    void sort(int *Array, int size)
    {
        int minIndex;
        for (int i = 0; i < size - 1; i++)
        {
            minIndex = i;
            for (int j = i + 1; j < size; j++)
            {
                if (Array[j] < Array[minIndex])
                {
                    minIndex = j;
                }
            }

            int temp = Array[i];
            Array[i] = Array[minIndex];
            Array[minIndex] = temp;
        }
    }
};

class InsertionSort
{
public:
    void sort(int *Array, int size)
    {
        for (int i = 1; i < size; i++)
        {
            int key = Array[i];
            int j = i - 1;
            while (j >= 0 && Array[j] > key)
            {
                Array[j + 1] = Array[j];
                j--;
            }

            Array[j + 1] = key;
        }
    }
};

class PrintArray
{
public:
    void display(int *Array, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << Array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MergeSort mergeSort;
    BubbleSort bubbleSort;
    SelectionSort selectionSort;
    InsertionSort insertionSort;
    PrintArray print;

    int Array[] = {80, 70, 60, 50, 40, 30, 20, 10, 0};
    int size = sizeof(Array) / sizeof(int);

    print.display(Array, size);
    // bubbleSort.sort(Array, size);
    // selectionSort.sort(Array, size);
    // insertionSort.sort(Array, size);
    mergeSort.sort(Array, 0, size - 1);
    print.display(Array, size);

    return 0;
}