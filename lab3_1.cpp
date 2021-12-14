#include <iostream>
#include "Sequance.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Tests.h"
#include "Benchmark.h"
#include "ISorter.h"


template <class T>
bool cmp(T el1, T el2)
{
    return (el1 > el2);
}

void sort()
{
    int type = 0;
    int n = 0;
    bool direct = true;
    int dir = 1;
    while (type != 3)
    {
        std::cout << "1.Array\n2.List\nInput type of sequance: ";
        std::cin >> type;
        if (type != 1 && type != 2) {
            std::cout << "Wrong choice of type! Try again.\n";
            return;
        }
        switch (type) {
        case 1:
        {
            ArrayVector<float>* vec = new ArrayVector<float>;
            int todo = 0;
            float* arr = NULL;
            while (todo != 9)
            {
                std::cout << "For Array:\n1.input\n2.qsort\n3.Insort\n4.mergesort\n5.shellsort\n6.heapsort\n7.output\n8.change type\n9.exit from sort\n";
                std::cin >> todo;
                if (todo < 1 || todo > 9) continue;
                switch (todo)
                {
                case 1:
                    std::cout << "input n: ";
                    std::cin >> n;
                    arr = new float[n];
                    std::cout << "input elements: ";
                    vec->Clear();
                    vec = new ArrayVector<float>;
                    for (int i = 0; i < n; i++)
                    {
                        std::cin >> arr[i];
                        vec->Append(arr[i]);
                    }
                    delete[] arr;
                    //vec = ArrayVector<float>(arr, n);
                    break;
                case 2:
                    Sorter<float>::QSort(vec, 0, n - 1, &cmp);
                    break;
                case 3:
                    Sorter<float>::InsertSort(vec, 0, n - 1, &cmp);
                    break;
                case 4:
                    Sorter<float>::MergeSort(vec, 0, n - 1, &cmp);
                    break;
                case 5:
                    Sorter<float>::ShellSort(vec, 0, n - 1, &cmp);
                    break;
                case 6:
                    Sorter<float>::HeapSort(vec, 0, n - 1, &cmp);
                    break;
                case 7:
                    vec->Output();
                    break;
                case 8:
                    type = 2;
                    vec->Clear();
                    break;
                case 9:
                    type = 3;
                    vec->Clear();
                    break;
                }
                if (type == 2) break;
            }
        }break;
        case 2:
        {
            ListVector<float>* vec = new ListVector<float>;
            int todo = 0;
            float* arr = NULL;
            while (todo != 9)

            {
                std::cout << "For List:\n1.input\n2.qsort\n3.Insort\n4.mergesort\n5.shellsort\n6.HeapSort\n7.output\n8.change type\n9.exit from sort\n";
                std::cin >> todo;
                if (todo < 1 || todo > 9) continue;
                switch (todo)
                {
                case 1:
                    std::cout << "input n: ";
                    std::cin >> n;
                    arr = new float[n];
                    std::cout << "input elements: ";
                    vec->Clear();
                    vec = new ListVector<float>;
                    for (int i = 0; i < n; i++)
                    {
                        std::cin >> arr[i];
                        vec->Append(arr[i]);
                    }
                    delete[] arr;
                    break;
                case 2:
                    Sorter<float>::QSort(vec, 0, n - 1, cmp);
                    break;
                case 3:
                    Sorter<float>::InsertSort(vec, 0, n - 1, cmp);
                    break;
                case 4:
                    Sorter<float>::MergeSort(vec, 0, n - 1, cmp);
                    break;
                case 5:
                    Sorter<float>::ShellSort(vec, 0, n - 1, cmp);
                    break;
                case 6:
                    Sorter<float>::HeapSort(vec, 0, n - 1, cmp);
                    break;
                case 7:
                    vec->Output();
                    break;
                case 8:
                    type = 1;
                    vec->Clear();
                    break;
                case 9:
                    type = 3;
                    vec->Clear();
                    break;
                }
                if (type == 1) break;
            }
        }
        break;
        case 3:
            return;
            break;

        }

    }
}


void menu() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "1.Sum\n" << "2.MultOnScal\n" << "3.Norm\n" << "4.ScalMult\n" << "5.exit\n" << "6.Sort\n" << "Make your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        if (choice < 1 || choice > 6) {
            std::cout << "Wrong choice! Try again.\n";
            continue;
        }
        int type;
        int n;

        switch (choice) {
        case 1: {
            std::cout << "1.Array\n2.List\nInput type of sequance: ";
            std::cin >> type;
            if (type != 1 && type != 2) {
                std::cout << "Wrong choice of type! Try again.\n";
                continue;
            }
            switch (type) {
            case 1: {
                ArrayVector<float> vec1;
                ArrayVector<float> vec2;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec1.Append(data);
                }
                std::cout << "Input vector2: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec2.Append(data);
                }
                vec1.Sum(&vec2);
                std::cout << "Sum= ";
                vec1.Output();
                vec1.Clear();
                vec2.Clear();
            }
                  break;

            case 2: {
                ListVector<float> vec3;
                ListVector<float> vec4;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec3.Append(data);
                }
                std::cout << "Input vector2: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec4.Append(data);
                }
                vec3.Sum(&vec4);
                std::cout << "Sum= ";
                vec3.Output();
            }
                  break;
            }
        }
              break;
        case 2: {
            std::cout << "1.Array\n2.List\nInput type of sequance: ";
            std::cin >> type;
            if (type != 1 && type != 2) {
                std::cout << "Wrong choice of type! Try again.\n";
                continue;
            }
            switch (type) {
            case 1: {
                ArrayVector<float> vec1;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec1.Append(data);
                }
                int scal;
                std::cout << "Input Scalar: ";
                std::cin >> scal;

                vec1.MultOnScal(scal);
                std::cout << "Mult on scal= ";
                vec1.Output();
            }
                  break;
            case 2: {
                ListVector<float> vec3;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec3.Append(data);
                }
                int scal2;
                std::cout << "Input Scalar: ";
                std::cin >> scal2;

                vec3.MultOnScal(scal2);
                std::cout << "Mult on scal= ";
                vec3.Output();
            }
                  break;
            }
        }
              break;
        case 3: {
            std::cout << "1.Array\n2.List\nInput type of sequance: ";
            std::cin >> type;
            if (type != 1 && type != 2) {
                std::cout << "Wrong choice of type! Try again.\n";
                continue;
            }
            switch (type) {
            case 1: {
                ArrayVector<float> vec1;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec1.Append(data);
                }

                float norm = vec1.Norm();
                std::cout << "Norm= " << norm << std::endl;
            }
                  break;
            case 2: {
                ListVector<float> vec3;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec3.Append(data);
                }
                float norm2 = vec3.Norm();
                std::cout << "Norm= " << norm2 << std::endl;
            }
                  break;
            }
        }
              break;
        case 4: {
            std::cout << "1.Array\n2.List\nInput type of sequance: ";
            std::cin >> type;
            if (type != 1 && type != 2) {
                std::cout << "Wrong choice of type! Try again.\n";
                continue;
            }
            switch (type) {
            case 1: {
                ArrayVector<float> vec1;
                ArrayVector<float> vec2;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec1.Append(data);
                }
                std::cout << "Input vector2: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec2.Append(data);
                }
                float scalMult = vec1.ScalMult(&vec2);
                std::cout << "ScalMult= " << scalMult << std::endl;

            }
                  break;
            case 2: {
                ListVector<float> vec3;
                ListVector<float> vec4;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec3.Append(data);
                }
                std::cout << "Input vector2: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec4.Append(data);
                }
                vec3.ScalMult(&vec4);
                std::cout << "ScalMult= " << vec3.ScalMult(&vec4) << std::endl;
            }
                  break;
            }
        }
              break;
        case 5: {
            std::cout << "Exit the program...\n";
            return;
        }
              break;
        case 6:
        {
            sort();
            break;
        }
        }
    }
}



int main()
{
    menu();
    //SortTime();
    //SortTimeSorted();
    //SortTimeSortedReverse();

    Test_Sum_Arr();
    Test_MultOnScal_Arr();
    Test_Norm_Arr();
    Test_ScalMult_Arr();
    Test_Concat_Arr();
    Test_GetSubVec_Arr();
    Test_Sort_Fast_Arr();
    Test_Sort_Insert_Arr();
    Test_Sort_Shell_Arr();
    Test_Sort_Merge_Arr();
    Test_Sort_Heap_Arr();

    Test_Sum_List();
    Test_MultOnScal_List();
    Test_Norm_List();
    Test_ScalMult_List();
    Test_Concat_List();
    Test_GetSubVec_List();
    Test_Sort_Fast_List();
    Test_Sort_Insert_List();
    Test_Sort_Shell_List();
    Test_Sort_Merge_List();

}