#include "Benchmark.h"
#include "Sequance.h"
#include "Sequance.cpp"
#include <cmath>
#include <fstream>
#include "DynamicArray.cpp"
#include "LinkedList.cpp"
#include <iomanip>
template <class T>
bool cmp(T el1, T el2)
{
	return el1 > el2;
}

void SortTime()
{
	std::ofstream outf("SortTime.txt");
	int n = 10000;
	float tm1, tm2, tm3, tm4, tm5, tm6, tm7, tm8, tm9;
	srand(time(NULL));
	for (int k = 0; k < 10; k++) 
	{	
		std::cout << k << std::endl;
		tm1 = 0; tm2 = 0; tm3 = 0; tm4 = 0; tm5 = 0; tm6 = 0; tm7 = 0; tm8 = 0; tm9 = 0;
		for (int average = 0; average < 5; average++)
		{
			int* arr1 = new int[n];
			for (int i = 0; i < n; i++)
			{
				int rnd = rand() % 5000000;
				arr1[i] = rnd;
			}
			ArrayVector<int>* vec1 = new ArrayVector<int>(arr1, n);

			ArrayVector<int>* vec2 = new ArrayVector<int>(arr1, n);

			ArrayVector<int>* vec3 = new ArrayVector<int>(arr1, n);

			ArrayVector<int>* vec4 = new ArrayVector<int>(arr1, n);

			ArrayVector<int>* vec5 = new ArrayVector<int>(arr1, n);

			ListVector<int>* vec6 = new ListVector<int>(arr1, n);

			ListVector<int>* vec7 = new ListVector<int>(arr1, n);

			ListVector<int>* vec8 = new ListVector<int>(arr1, n);

			ListVector<int>* vec9 = new ListVector<int>(arr1, n);


			//std::cout << k << "\n";
			/*
			vec1->Output();
			std::cout << "--------------not sorted-----------------------\n";
			vec2->Output();
			std::cout << "\n\n\n";
			*/

			float before = (float)clock();
			//vec1->InsertSort(true, 0, n - 1,cmp);
			tm1 += (float)clock() - before;
			//outf << tm1 << "        ";

			/*
			vec1->Output();
			std::cout << "--------------vec1 sorted-----------------------\n";
			vec2->Output();
			std::cout<< "\n\n\n";
			*/

			before = (float)clock();
			vec2->FastSort(true, 0, n - 1, cmp);
			tm2 += (float)clock() - before;
			//outf << tm2 << "        ";

			before = (float)clock();
			vec3->ShellSort(true, 0, n - 1, cmp);
			tm3 += (float)clock() - before;
			//outf << tm3 << "        ";

			before = (float)clock();
			vec4->MergeSort(true, 0, n - 1, cmp);
			tm4 += (float)clock() - before;
			//outf << tm4 << "  | Array<-||" << n << "|||->List |  ";

			before = (float)clock();
			vec5->HeapSort(true, 0, n - 1,cmp);
			tm5 += (float)clock() - before;
			//outf << tm5 << "        ";

			before = (float)clock();
			vec6->InsertSort(true, 0, n - 1, cmp);
			tm6 += (float)clock() - before;
			//outf << tm6 << "        ";

			before = (float)clock();
			vec7->FastSort(true, 0, n - 1, cmp);
			tm7 += (float)clock() - before;
			//outf << tm7 << "        ";

			before = (float)clock();
			//vec8->ShellSort(true, 0, n - 1, cmp);
			tm8 += (float)clock() - before;

			before = (float)clock();
			vec9->MergeSort(true, 0, n - 1, cmp);
			tm9 += (float)clock() - before;

			//outf << tm8 << "\n";

			//std::cout << "*\n";

			
			/*
			vec1->Output();
			std::cout << "--------------sorted-----------------------\n";
			vec2->Output();
			*/

			vec1->~ArrayVector();
			vec2->~ArrayVector();
			vec3->~ArrayVector();
			vec4->~ArrayVector();
			vec5->~ArrayVector();
			vec6->~ListVector();
			vec7->~ListVector();
			vec8->~ListVector();
			vec9->~ListVector();
			delete[] arr1;
		}
		outf << tm1/5 << "        ";
		outf << tm2/5 << "        "; 
		outf << tm3/5 << "        ";
		outf << tm4/5 << "        ";
		outf << tm5/5 << "  | Array<-|insert-fast-shell-merge-heap|" << n << "|insert-fast-shell-merge|->List |  ";
		outf << tm6/5 << "        ";
		outf << tm7/5 << "        ";
		outf << tm8/5 << "        ";
		outf << tm9/5 << "\n";
		n += 10000;
	}
	
	return;
}



void SortTimeSorted()
{
	std::ofstream outf("SortTimeSorted.txt");
	int n = 10000;
	float tm1, tm2, tm3, tm4, tm5, tm6, tm7, tm8, tm9;
	srand(time(NULL));
	for (int k = 0; k < 10; k++)
	{
		std::cout << k << std::endl;
		tm1 = 0; tm2 = 0; tm3 = 0; tm4 = 0; tm5 = 0; tm6 = 0; tm7 = 0; tm8 = 0; tm9 = 0;
		for (int average = 0; average < 5; average++)
		{
			int* arr1 = new int[n];
			for (int i = 0; i < n; i++)
			{
				int rnd = rand() % 5000000;
				arr1[i] = rnd;
			}
			ArrayVector<int>* vec1 = new ArrayVector<int>(arr1, n);
			vec1->FastSort(true, 0, n-1, cmp);

			ArrayVector<int>* vec2 = new ArrayVector<int>(*vec1);

			ArrayVector<int>* vec3 = new ArrayVector<int>(*vec1);

			ArrayVector<int>* vec4 = new ArrayVector<int>(*vec1);

			ArrayVector<int>* vec5 = new ArrayVector<int>(*vec1);

			ListVector<int>* vec6 = new ListVector<int>(arr1,n);
			vec6->FastSort(true,0,n-1,cmp);

			ListVector<int>* vec7 = new ListVector<int>(*vec6);

			ListVector<int>* vec8 = new ListVector<int>(*vec6);

			ListVector<int>* vec9 = new ListVector<int>(*vec6);
			
			float before = (float)clock();
			//vec1->InsertSort(true, 0, n - 1,cmp);
			tm1 += (float)clock() - before;
			//outf << tm1 << "        ";

			before = (float)clock();
			vec2->FastSort(true, 0, n - 1, cmp);
			tm2 += (float)clock() - before;
			//outf << tm2 << "        ";

			before = (float)clock();
			vec3->ShellSort(true, 0, n - 1, cmp);
			tm3 += (float)clock() - before;
			//outf << tm3 << "        ";

			before = (float)clock();
			vec4->MergeSort(true, 0, n - 1, cmp);
			tm4 += (float)clock() - before;
			//outf << tm4 << "  | Array<-||" << n << "|||->List |  ";

			before = (float)clock();
			vec5->HeapSort(true, 0, n - 1, cmp);
			tm5 += (float)clock() - before;
			//outf << tm5 << "        ";

			before = (float)clock();
			vec6->InsertSort(true, 0, n - 1, cmp);
			tm6 += (float)clock() - before;
			//outf << tm6 << "        ";

			before = (float)clock();
			vec7->FastSort(true, 0, n - 1, cmp);
			tm7 += (float)clock() - before;
			//outf << tm7 << "        ";

			before = (float)clock();
			//vec8->ShellSort(true, 0, n - 1, cmp);
			tm8 += (float)clock() - before;

			before = (float)clock();
			vec9->MergeSort(true, 0, n - 1, cmp);
			tm9 += (float)clock() - before;


			vec1->~ArrayVector();
			vec2->~ArrayVector();
			vec3->~ArrayVector();
			vec4->~ArrayVector();
			vec5->~ArrayVector();
			vec6->~ListVector();
			vec7->~ListVector();
			vec8->~ListVector();
			vec9->~ListVector();
			delete[] arr1;
		}
		
		outf << tm1 / 5 << "        ";
		outf << tm2 / 5 << "        ";
		outf << tm3 / 5 << "        ";
		outf << tm4 / 5 << "        ";
		outf << tm5 / 5 << "  | Array<-|insert-fast-shell-merge-heap|" << n << "|insert-fast-shell-merge|->List |  ";
		outf << tm6 / 5 << "        ";
		outf << tm7 / 5 << "        ";
		outf << tm8 / 5 << "        ";
		outf << tm9 / 5 << "\n";
		n += 10000;
		
	}

	return;
}

void SortTimeSortedReverse()
{

	std::ofstream outf("SortTimeSortedReverse.txt");
	int n = 10000;
	float tm1, tm2, tm3, tm4, tm5, tm6, tm7, tm8, tm9;
	srand(time(NULL));
	for (int k = 0; k < 10; k++)
	{
		std::cout << k << std::endl;
		tm1 = 0; tm2 = 0; tm3 = 0; tm4 = 0; tm5 = 0; tm6 = 0; tm7 = 0; tm8 = 0; tm9 = 0;
		for (int average = 0; average < 5; average++)
		{
			int* arr1 = new int[n];
			for (int i = 0; i < n; i++)
			{
				int rnd = rand() % 5000000;
				arr1[i] = rnd;
			}
			ArrayVector<int>* vec1 = new ArrayVector<int>(arr1, n);
			vec1->FastSort(false, 0, n-1, cmp);

			ArrayVector<int>* vec2 = new ArrayVector<int>(*vec1);

			ArrayVector<int>* vec3 = new ArrayVector<int>(*vec1);

			ArrayVector<int>* vec4 = new ArrayVector<int>(*vec1);

			ArrayVector<int>* vec5 = new ArrayVector<int>(*vec1);

			ListVector<int>* vec6 = new ListVector<int>(arr1, n);
			vec6->FastSort(false, 0, n-1, cmp);

			ListVector<int>* vec7 = new ListVector<int>(*vec6);

			ListVector<int>* vec8 = new ListVector<int>(*vec6);

			ListVector<int>* vec9 = new ListVector<int>(*vec6);

			float before = (float)clock();
			//vec1->InsertSort(true, 0, n - 1,cmp);
			tm1 += (float)clock() - before;
			//outf << tm1 << "        ";

			before = (float)clock();
			vec2->FastSort(true, 0, n - 1, cmp);
			tm2 += (float)clock() - before;
			//outf << tm2 << "        ";

			before = (float)clock();
			vec3->ShellSort(true, 0, n - 1, cmp);
			tm3 += (float)clock() - before;
			//outf << tm3 << "        ";

			before = (float)clock();
			vec4->MergeSort(true, 0, n - 1, cmp);
			tm4 += (float)clock() - before;
			//outf << tm4 << "  | Array<-||" << n << "|||->List |  ";

			before = (float)clock();
			vec5->HeapSort(true, 0, n - 1, cmp);
			tm5 += (float)clock() - before;
			//outf << tm5 << "        ";

			before = (float)clock();
			vec6->InsertSort(true, 0, n - 1, cmp);
			tm6 += (float)clock() - before;
			//outf << tm6 << "        ";

			before = (float)clock();
			vec7->FastSort(true, 0, n - 1, cmp);
			tm7 += (float)clock() - before;
			//outf << tm7 << "        ";

			before = (float)clock();
			//vec8->ShellSort(true, 0, n - 1, cmp);
			tm8 += (float)clock() - before;

			before = (float)clock();
			vec9->MergeSort(true, 0, n - 1, cmp);
			tm9 += (float)clock() - before;


			vec1->~ArrayVector();
			vec2->~ArrayVector();
			vec3->~ArrayVector();
			vec4->~ArrayVector();
			vec5->~ArrayVector();
			vec6->~ListVector();
			vec7->~ListVector();
			vec8->~ListVector();
			vec9->~ListVector();
			delete[] arr1;
		}

		outf << tm1 / 5 << "        ";
		outf << tm2 / 5 << "        ";
		outf << tm3 / 5 << "        ";
		outf << tm4 / 5 << "        ";
		outf << tm5 / 5 << "  | Array<-|insert-fast-shell-merge-heap|" << n << "|insert-fast-shell-merge|->List |  ";
		outf << tm6 / 5 << "        ";
		outf << tm7 / 5 << "        ";
		outf << tm8 / 5 << "        ";
		outf << tm9 / 5 << "\n";
		n += 10000;

	}

	return;

}