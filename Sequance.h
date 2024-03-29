#ifndef SEQUANCE_H
#define SEQUANCE_H

#include "DynamicArray.h"
#include "LinkedList.h"

template <class T>
class Vector {
public:
	virtual T GetFirst() = 0;
	virtual T GetLast() = 0 ;
	virtual T Get(int i) = 0 ;
	
	virtual int GetLength() = 0 ;
	virtual int GetSize() = 0;
	//��������
	virtual void Append(T item) = 0;
	virtual void Prepend(T item) = 0 ;
	virtual void Set(T item, int i) = 0;
	virtual void InsertAt(T item, int i) = 0;
	virtual void Clear() = 0;
	//�����
	//virtual void Output() = 0 ;
	//virtual bool Comp(Vector<T>* arr1, Vector<T>* arr2) = 0;
};

template <class T>
class ArrayVector : virtual public Vector<T> {
private:
	DynamicArray<T>* items;
	int count;
public:
	//��������
	ArrayVector(T* item, int n);
	ArrayVector();
	ArrayVector(int n);
	ArrayVector(const ArrayVector<T>& arrVec);
	//~ArrayVector() { if (this )Clear(); return; }
	//������������
	T GetFirst() override;
	T GetLast() override;
	T Get(int i) override;
	
	ArrayVector<T>* GetSubVector(int i, int j);
	int GetLength() override;
	int GetSize() override;
	//��������
	void Append(T item) override;
	void Prepend(T item) override;
	void Set(T item, int i) override;
	void InsertAt(T item, int i) override;
	void PopBack();
	void Resize(int newzs);
	ArrayVector<T>* Concat(ArrayVector<T>* arrVec);
	void Clear() override;
	//��� ��������
	void Sum(ArrayVector<T>* vec);
	void MultOnScal(int k);
	T Norm();
	T ScalMult(ArrayVector<T>* vec);
	//�����
	void Output();
	void InsertSort(bool direct, int start, int end, bool (*cmp)(T el1, T el2) ); //���������
	void FastSort(bool direct, int start, int end, bool (*cmp)(T el1, T el2)); //������� 
	void ShellSort(bool direct, int start, int end, bool (*cmp)(T el1, T el2)); //shell
	void MergeSort(bool direct, int first, int last, bool (*cmp)(T el1, T el2)); //��������
	void Merge(bool direct, int first, int last, bool (*cmp)(T el1, T el2));
	void HeapSort(bool direct, int first, int last, bool (*cmp)(T el1, T el2)); //���� 
	void SiftDown(bool direct, int ind,int length, bool (*cmp)(T el1, T el2));// ���������� ����
};

template <class T>
class ListVector : virtual public Vector<T> {
private:
	LinkedList<T>* items;
public:
	//��������
	ListVector(T* item, int n);
	ListVector();
	ListVector(const ListVector<T>& listVec);
	//~ListVector() { Clear(); return; }
	//������������
	T GetFirst() override;
	T GetLast() override;
	T Get(int i) override;
	ListVector<T>* GetSubVector(int i, int j);
	int GetLength() override;
	int GetSize() override { return GetLength(); }
	//��������
	void Append(T item) override;
	void Prepend(T item) override;
	void InsertAt(T item, int i) override;
	void Remove(int i);
	void Set(T item, int i) override;
	ListVector<T>* Concat(ListVector<T>* arrVec);
	void Clear() override;
	//��� ��������
	void Sum(ListVector<T>* vec);
	void MultOnScal(int k);
	T Norm();
	T ScalMult(ListVector<T>* vec);
	//�����
	void Output();
	void InsertSort(bool direct, int start, int end, bool (*cmp)(T el1, T el2)); //���������
	void FastSort(bool direct, int start, int end, bool (*cmp)(T el1, T el2)); //�������
	void ShellSort(bool direct, int start, int end, bool (*cmp)(T el1, T el2)); //shell
	void MergeSort(bool direct, int start, int end, bool (*cmp)(T el1, T el2)); //��������
	void Merge(bool direct, int start, int end, bool (*cmp)(T el1, T el2));
	
};

//stek
template <class T>
class Stek {
public:

	virtual T GetLast() = 0;
	

	virtual int GetLength() = 0;
	//��������
	virtual void Append(T item) = 0;
	//virtual void Prepend(T item) = 0;
	virtual void Pop() = 0;

	//�����
	virtual void Output() = 0;
};

template <class T>
class ArrayStek : Stek<T> {
private:
	DynamicArray<T>* items;
	T Get(int i);
public:
	//��������
	ArrayStek(T* item, int n);
	ArrayStek();
	ArrayStek(const ArrayVector<T>& arrVec);
	//������������
	T GetLast();
	int GetLength();
	//��������
	void Append(T item);
	void Pop();
	void Output();
};

template <class T>
class ListStek : Stek<T> {
private:
	LinkedList<T>* items;
	T Get(int i);
public:
	//��������
	ListStek(T* item, int n);
	ListStek();
	ListStek(const ListVector<T>& listVec);
	//������������
	T GetLast();
	int GetLength();
	void Append(T item);
	void Pop();
	//�����
	void Output();
};
#endif // !SEQUANCE_H

