#pragma once
#include <iostream>
#include "Sequance.h"
#include <fstream>

#include "Sequance.cpp"
#include "LinkedList.cpp"
#include "DynamicArray.cpp"
#include "ISorter.cpp"


//array
void Test_Sum_Arr() {
	ArrayVector<float>* vec1 = new ArrayVector<float>;
	ArrayVector<float>* vec2 = new ArrayVector<float>;
	ArrayVector<float>* vec3 = new ArrayVector<float>;

	std::ifstream file;
	file.open("Sum.txt");
	float data;
	for (int i = 0; i < 4; i++) {
		file >> data;
		vec1->Append(data);
	}
	for (int i = 0; i < 4; i++) {
		file >> data;
		vec2->Append(data);
	}

	for (int i = 0; i < 4; i++) {
		file >> data;
		vec3->Append(data);
	}

	vec1->Sum(vec2);
	
	for (int i = 0; i < 4; i++) {
		if (vec1->Get(i) != vec3->Get(i)) {
			std::cout << vec1->Get(i) << " " << vec3->Get(i) << std::endl;
			std::cout << "Error in ArrSum\n";
			file.close();
			return;
		}
	}
	file.close();
}
void Test_MultOnScal_Arr() {
	ArrayVector<float> vec1;
	ArrayVector<float> vec2;

	std::ifstream file;
	file.open("MultOnScal.txt");
	float data;
	for (int i = 0; i < 4; i++) {
		file >> data;
		vec1.Append(data);
	}
	
	int scal;
	file >> scal;

	for (int i = 0; i < 4; i++) {
		file >> data;
		vec2.Append(data);
	}
	

	vec1.MultOnScal(scal);
	
	for (int i = 0; i < 4; i++) {
		if (vec1.Get(i) != vec2.Get(i)) {
			std::cout << "Error in ArrMultOnScal\n";
			file.close();
			return;
		}
	}
	file.close();
}
void Test_Norm_Arr() {
	ArrayVector<float> vec1;
	

	std::ifstream file;
	file.open("Norm.txt");
	float data;
	for (int i = 0; i < 4; i++) {
		file >> data;
		vec1.Append(data);
	}
	
	
	float norm;
	file >> norm;

	if (norm != vec1.Norm()) {
		std::cout << "Error in ArrNorm\n";
	}
	file.close();
	
}
void Test_ScalMult_Arr() {
	ArrayVector<float> vec1;
	ArrayVector<float> vec2;
	
	
	std::ifstream file;
	file.open("ScalMult.txt");
	float data;
	for (int i = 0; i < 4; i++) {
		file >> data;
		vec1.Append(data);
	}
	for (int i = 0; i < 4; i++) {
		file >> data;
		vec2.Append(data);
	}
	
	float scalMult;
	file >> scalMult;

	if (vec1.ScalMult(&vec2) != scalMult) {
		std::cout << "Error in ArrScalMult\n";
	}
	
	file.close();
}

void Test_Concat_Arr() {
	ArrayVector<float> vec1;
	ArrayVector<float> vec2;
	ArrayVector<float> vec12;

	std::ifstream file;
	file.open("Concat.txt");

	float data;
	for (int i = 0; i < 4; i++) {
		file >> data;
		vec1.Append(data);
	}
	for (int i = 0; i < 4; i++) {
		file >> data;
		vec2.Append(data);
	}
	for (int i = 0; i < 8; i++) {
		file >> data;
		vec12.Append(data);
	}
	ArrayVector<float>* vec3 = new ArrayVector<float>;
	vec3 = vec1.Concat(&vec2);
	
	
	for (int i = 0; i < 8; i++) {
		if (vec3->Get(i) != vec12.Get(i)) {
			std::cout << "Error in ArrConcat\n";
			file.close();
			return;
		}
	}
	

	file.close();
}
void Test_GetSubVec_Arr() {
	ArrayVector<float> vec12;
	ArrayVector<float> subVec;

	std::ifstream file;
	file.open("GetSubVec.txt");

	float data;

	for (int i = 0; i < 8; i++) {
		file >> data;
		vec12.Append(data);
	}
	for (int i = 0; i < 5; i++) {
		file >> data;
		subVec.Append(data);
	}

	ArrayVector<float>* vec4 = new ArrayVector<float>;
	vec4 = vec12.GetSubVector(1, 5);

	for (int i = 0; i < 5; i++) {
		if (vec4->Get(i) != subVec.Get(i)) {
			std::cout << "Error in ArrGetSubVec\n";
			file.close();
			return;
		}
	}

}

void Test_Pop_Arr()
{
	ArrayStek<int> stek1;
	ArrayStek<int> stek2;
	std::ifstream file("Pop.txt");
	int x;
	std::cout << "1\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << "*\n";
		file >> x;
		std::cout << "**\n";
		stek1.Append(x);
	}
	std::cout << "2\n";
	stek1.Pop();
	for (int i = 0; i < 3; i++)
	{
		file >> x;
		stek2.Append(x);
	}
	std::cout << "3\n";
	for (int i = 0; i < 3; i++)
	{
		if (stek1.GetLast() != stek2.GetLast())
		{
			std::cout << "Error in Pop_Arr\n";
			file.close();
			return;
		}
		stek1.Pop();
		stek2.Pop();
	}
	std::cout << "4\n";
	file.close();
	std::cout << "5\n";
	return;
}
namespace test {
	template <class T>
	bool cmp(T el1, T el2)
	{
		return el1 > el2;
	}
}
	void Test_Sort_Insert_Arr() {
		int arr[4];
		int x;
		std::ifstream cinf("Sort.txt");
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			arr[i] = x;
		}
		ArrayVector<int>* vec = new ArrayVector<int>(arr, 4);
		Sorter<int>::InsertSort(vec, 0, 3, test::cmp);
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			if (vec->Get(i) != x) {
				std::cout << "Error in Sort_Puz_Arr!\n";
				cinf.close();
				return;
			}
		}
		cinf.close();
		return;
	}
	void Test_Sort_Fast_Arr() {
		int arr[4];
		int x;
		std::ifstream cinf("Sort.txt");
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			arr[i] = x;
		}
		ArrayVector<int>* vec = new ArrayVector<int>(arr, 4);
		Sorter<int>::QSort(vec, 0, 3, test::cmp);
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			if (vec->Get(i) != x) {
				std::cout << "Error in Sort_Fast_Arr!\n";
				cinf.close();
				return;
			}
		}
		cinf.close();
		return;
	}

	void Test_Sort_Shell_Arr() {
		int arr[4];
		int x;
		std::ifstream cinf("Sort.txt");
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			arr[i] = x;
		}
		ArrayVector<int>* vec = new ArrayVector<int>(arr, 4);
		Sorter<int>::ShellSort(vec, 0, 3, test::cmp);
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			if (vec->Get(i) != x) {
				std::cout << "Error in Sort_Shell_Arr!\n";
				cinf.close();
				return;
			}
		}
		cinf.close();
		return;
	}

	void Test_Sort_Merge_Arr() {
		int arr[4];
		int x;
		std::ifstream cinf("Sort.txt");
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			arr[i] = x;
		}
		ArrayVector<int>* vec = new ArrayVector<int>(arr, 4);
		Sorter<int>::MergeSort(vec, 0, 3, test::cmp);
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			if (vec->Get(i) != x) {
				std::cout << "Error in Sort_Merge_Arr!\n";
				cinf.close();
				return;
			}
		}
		cinf.close();
		return;
	}

	void Test_Sort_Heap_Arr() {
		int arr[4];
		int x;
		std::ifstream cinf("Sort.txt");
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			arr[i] = x;
		}
		ArrayVector<int>* vec = new ArrayVector<int>(arr, 4);
		Sorter<int>::HeapSort(vec, 0, 3, test::cmp);
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			if (vec->Get(i) != x) {
				std::cout << "Error in Sort_Heap_Arr!\n";
				cinf.close();
				return;
			}
		}
		cinf.close();
		return;
	}

	//list-----------------------------------------------------------------------------------------------------------------------
	void Test_Sum_List() {
		ListVector<float> vec1;
		ListVector<float> vec2;
		ListVector<float> vec3;

		std::ifstream file;
		file.open("Sum.txt");
		float data;
		for (int i = 0; i < 4; i++) {
			file >> data;
			vec1.Append(data);
		}
		for (int i = 0; i < 4; i++) {
			file >> data;
			vec2.Append(data);
		}

		for (int i = 0; i < 4; i++) {
			file >> data;
			vec3.Append(data);
		}

		vec1.Sum(&vec2);

		for (int i = 0; i < 4; i++) {
			if (vec1.Get(i) != vec3.Get(i)) {
				std::cout << "Error in ListSum\n";
				file.close();
				return;
			}
		}
		file.close();
	}
	void Test_MultOnScal_List() {
		ListVector<float> vec1;
		ListVector<float> vec2;

		std::ifstream file;
		file.open("MultOnScal.txt");
		float data;
		for (int i = 0; i < 4; i++) {
			file >> data;
			vec1.Append(data);
		}

		int scal;
		file >> scal;

		for (int i = 0; i < 4; i++) {
			file >> data;
			vec2.Append(data);
		}


		vec1.MultOnScal(scal);

		for (int i = 0; i < 4; i++) {
			if (vec1.Get(i) != vec2.Get(i)) {
				std::cout << "Error in ListMultOnScal\n";
				file.close();
				return;
			}
		}
		file.close();
	}
	void Test_Norm_List() {
		ListVector<float> vec1;


		std::ifstream file;
		file.open("Norm.txt");
		float data;
		for (int i = 0; i < 4; i++) {
			file >> data;
			vec1.Append(data);
		}


		float norm;
		file >> norm;

		if (norm != vec1.Norm()) {
			std::cout << "Error in ListNorm\n";
		}

		file.close();
	}
	void Test_ScalMult_List() {
		ListVector<float> vec1;
		ListVector<float> vec2;


		std::ifstream file;
		file.open("ScalMult.txt");
		float data;
		for (int i = 0; i < 4; i++) {
			file >> data;
			vec1.Append(data);
		}
		for (int i = 0; i < 4; i++) {
			file >> data;
			vec2.Append(data);
		}

		float scalMult;
		file >> scalMult;

		if (vec1.ScalMult(&vec2) != scalMult) {
			std::cout << "Error in ListScalMult\n";
		}
		file.close();
	}

	void Test_Concat_List() {
		ListVector<float> vec1;
		ListVector<float> vec2;
		ListVector<float> vec12;

		std::ifstream file;
		file.open("Concat.txt");

		float data;
		for (int i = 0; i < 4; i++) {
			file >> data;
			vec1.Append(data);
		}
		for (int i = 0; i < 4; i++) {
			file >> data;
			vec2.Append(data);
		}
		for (int i = 0; i < 8; i++) {
			file >> data;
			vec12.Append(data);
		}
		ListVector<float>* vec3 = new ListVector<float>;
		vec3 = vec1.Concat(&vec2);


		for (int i = 0; i < 8; i++) {
			if (vec3->Get(i) != vec12.Get(i)) {
				std::cout << "Error in ListConcat\n";
				file.close();
				return;
			}
		}


		file.close();
	}
	void Test_GetSubVec_List() {
		ListVector<float> vec12;
		ListVector<float> subVec;

		std::ifstream file;
		file.open("GetSubVec.txt");

		float data;

		for (int i = 0; i < 8; i++) {
			file >> data;
			vec12.Append(data);
		}
		for (int i = 0; i < 5; i++) {
			file >> data;
			subVec.Append(data);
		}

		ListVector<float>* vec4 = new ListVector<float>;
		vec4 = vec12.GetSubVector(1, 5);

		for (int i = 0; i < 5; i++) {
			if (vec4->Get(i) != subVec.Get(i)) {
				std::cout << "Error in ListGetSubVec\n";
				file.close();
				return;
			}
		}
	}

	void Test_Pop_List()
	{
		ListStek<int> stek1;
		ListStek<int> stek2;
		std::ifstream file;
		file.open("Pop.txt");
		int x;
		for (int i = 0; i < 4; i++)

		{
			file >> x;
			stek1.Append(x);
		}
		stek1.Pop();
		for (int i = 0; i < 3; i++)
		{
			file >> x;
			stek2.Append(x);
		}

		for (int i = 0; i < 3; i++)
		{
			if (stek1.GetLast() != stek2.GetLast())
			{
				std::cout << "Error in Pop_List\n";
				file.close();
				return;
			}
			stek1.Pop();
			stek2.Pop();
		}
		file.close();
		return;
	}


	void Test_Sort_Insert_List() {
		int arr[4];
		int x;
		std::ifstream cinf("Sort.txt");
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			arr[i] = x;
		}
		ListVector<int>* vec = new ListVector<int>(arr, 4);
		Sorter<int>::InsertSort(vec, 0, 3, test::cmp);
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			if (vec->Get(i) != x) {
				std::cout << "Error in Sort_Puz_List!\n";
				cinf.close();
				return;
			}
		}
		cinf.close();
		return;
	}

	void Test_Sort_Fast_List() {
		int arr[4];
		int x;
		std::ifstream cinf("Sort.txt");
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			arr[i] = x;
		}
		ListVector<int>* vec = new ListVector<int>(arr, 4);
		Sorter<int>::QSort(vec, 0, 3, test::cmp);
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			if (vec->Get(i) != x) {
				std::cout << "Error in Sort_Fast_List!\n";
				cinf.close();
				return;
			}
		}
		cinf.close();
		return;
	}

	void Test_Sort_Shell_List() {
		int arr[4];
		int x;
		std::ifstream cinf("Sort.txt");
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			arr[i] = x;
		}
		ListVector<int>* vec = new ListVector<int>(arr, 4);
		Sorter<int>::ShellSort(vec, 0, 3, test::cmp);
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			if (vec->Get(i) != x) {
				std::cout << "Error in Sort_Shell_List!\n";
				cinf.close();
				return;
			}
		}
		cinf.close();
		return;
	}

	void Test_Sort_Merge_List() {
		int arr[4];
		int x;
		std::ifstream cinf("Sort.txt");
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			arr[i] = x;
		}
		ListVector<int>* vec = new ListVector<int>(arr, 4);
		Sorter<int>::MergeSort(vec, 0, 3, test::cmp);
		for (int i = 0; i < 4; i++)
		{
			cinf >> x;
			if (vec->Get(i) != x) {
				std::cout << "Error in Sort_Merge_List!\n";
				cinf.close();
				return;
			}
		}
		cinf.close();
		return;
	}
