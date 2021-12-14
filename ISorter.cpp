#pragma once
#include "ISorter.h"


template <class T>
void Sorter<T>::QSort(Vector<T>* seq, int start, int end, bool (*cmp)(T el1, T el2))
{
	if (!seq) return;
	if (start == end) return;
	int l = start;
	int r = end;
	int ind = (start + end) / 2;
	T comp = seq->Get(ind);

	while (l <= r)
	{

		while (cmp(comp, seq->Get(l)))
		{
			if (l == ind) break;
			l++;
		}

		while (cmp(seq->Get(r), comp))
		{
			if (r == ind) break;
			r--;
		}

		if (l <= r)
		{
			T save = seq->Get(l);
			seq->Set(seq->Get(r), l);
			seq->Set(save, r);
			l++;
			r--;
		}


	}

	if (l < end) QSort(seq, l, end, cmp);

	if (r > start) QSort(seq, start, r, cmp);
	return;
}

template <class T>
void Sorter<T>::InsertSort(Vector<T>* seq, int start, int end, bool (*cmp)(T el1, T el2))
{
	if (!seq) return;
	if (seq->GetLength() < 2) return;
	for (int i = 1; i < seq->GetLength(); i++)
	{
		int j = i;
		while ( cmp(seq->Get(j - 1), seq->Get(j)) && j > 0)
		{
			T swap = seq->Get(j - 1);
			seq->Set(seq->Get(j), j - 1);
			seq->Set(swap, j);
			j--;
		}
	}
	return;
}

template <class T>
void Sorter<T>::ShellSort(Vector<T>* seq, int start, int end, bool (*cmp)(T el1, T el2)) {
	if (!seq) return;
	int size = end - start + 1;
	int sr = size / 2;
	while (sr > 0)
	{
		for (int i = start; i < size - sr; i++)
		{
			int j = i;
			while ((j >= start) && (cmp(seq->Get(j), seq->Get(j + sr))))
			{
				T swap = seq->Get(j);
				seq->Set(seq->Get(j + sr), j);
				seq->Set(swap, j + sr);
				j--;
			}
		}
		sr = sr / 2;
	}
}

template <class T>
void Sorter<T>::Merge(Vector<T>* seq, int first, int last, bool (*cmp)(T el1, T el2))
{
	int middle, start;
	T* mas = new T[seq->GetLength()];
	middle = (first + last) / 2;
	start = first;
	int final = middle + 1;
	int ind = first;

	while ((start <= middle) && (final <= last))
	{
		if (cmp(seq->Get(final), seq->Get(start)))
		{
			mas[ind] = seq->Get(start);
			ind++;
			start++;
		}
		else
		{
			mas[ind] = seq->Get(final);
			ind++;
			final++;
		}
	}
	while (start <= middle)
	{
		mas[ind] = seq->Get(start);
		ind++;
		start++;
	}
	while (final <= last)
	{
		mas[ind] = seq->Get(final);
		ind++;
		final++;
	}
	for (int j = first; j <= last; j++)
	{
		seq->Set(mas[j], j);
	}

	delete[] mas;
	return;
}



template <class T>
void Sorter<T>::MergeSort(Vector<T>* seq, int first, int last, bool (*cmp)(T el1, T el2))
{

	if (!seq) return;
	if (first < last)
	{
		MergeSort(seq, first, (first + last) / 2, cmp);
		MergeSort(seq, (first + last) / 2 + 1, last, cmp);
		Merge(seq, first, last, cmp);
	}
	return;
}


template <class T>
void Sorter<T>::SiftDown(Vector<T>* seq, int ind, int length, bool (*cmp)(T el1, T el2))
{
	while ((2 * ind + 1) < length)
	{
		int left = 2 * ind + 1;
		int right = 2 * ind + 2;
		int j = left;
		if ((right < length) && (cmp(seq->Get(right), seq->Get(left))))
			j = right;
		if (cmp(seq->Get(ind), seq->Get(j)))
			return;
		else
		{
			T swap = seq->Get(ind);
			seq->Set(seq->Get(j), ind);
			seq->Set(swap, j);
			ind = j;
		}
	}
	return;
}


template <class T>
void Sorter<T>::HeapSort(Vector<T>* seq, int first, int last, bool (*cmp)(T el1, T el2))
{
	int length = last - first + 1;
	for (int i = length / 2 - 1; i >= first; i--)
	{
		SiftDown(seq, i, length, cmp);
	}
	for (int i = last; i >= first; i--)
	{
		T swap = seq->Get(first);
		seq->Set(seq->Get(i), first);
		seq->Set(swap, i);
		SiftDown(seq, first, i, cmp);
	}
	return;
}