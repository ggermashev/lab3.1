#pragma once
#include "Sequance.h"

template <class T>
class Sorter
{
public:
	static void QSort(Vector<T>* seq, int start, int end, bool (*cmp)(T el1, T el2));
	static void InsertSort(Vector<T>* seq, int start, int end, bool (*cmp)(T el1, T el2));
	static void ShellSort(Vector<T>* seq, int start, int end, bool (*cmp)(T el1, T el2)); //shell
	static void MergeSort(Vector<T>* seq, int first, int last, bool (*cmp)(T el1, T el2)); //слиянием
	static void Merge(Vector<T>* seq, int first, int last, bool (*cmp)(T el1, T el2));
	static void HeapSort(Vector<T>* seq, int first, int last, bool (*cmp)(T el1, T el2)); //куча 
	static void SiftDown(Vector<T>* seq, int ind, int length, bool (*cmp)(T el1, T el2));// построение кучи
};