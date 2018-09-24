/*----------------------------------------
 * Actividad de Programacion: Algoritmos de Ordenamiento
 * Fecha: 23 de Septiembre 2018
 * Autor: Alberto Castañeda Arana
 ----------------------------------------*/

#ifndef SORTS_H_
#define SORTS_H_

#include "exception.h"
#include <vector>
#include <list>

template <class T>
class Sorts
{
  private:
	void swap(std::vector<T> &, int, int);
	void copyArray(std::vector<T> &, std::vector<T> &, int, int);
	void mergeArray(std::vector<T> &, std::vector<T> &, int, int, int);
	void mergeSplit(std::vector<T> &, std::vector<T> &, int, int);

  public:
	std::vector<T> bubbleSort(const std::vector<T> &);
	std::vector<T> selectionSort(const std::vector<T> &);
	std::vector<T> insertionSort(const std::vector<T> &);
	std::vector<T> shellSort(const std::vector<T> &);
	std::vector<T> mergeSort(const std::vector<T> &);
	std::vector<T> bucketSort(const std::vector<T> &);

	std::list<T> mergeList(const std::list<T> &, const std::list<T> &);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j)
{
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}
template <class T>
std::vector<T> Sorts<T>::bucketSort(const std::vector<T> &source)
{
	std::vector<T> v(source);

	std::list<T> listas[10];

	for (int i = 0; i < v.size(); i++)
	{
		int pos = v[i] / 10;
		listas[pos].push_back(v[i]);
	}

	std::vector<T> f;
	for (int i = 0; i < 10; i++)
	{
		listas[i].sort();
		f.insert(f.end(),listas[i].begin(),listas[i].end());
	}

	return f;
}
template <class T>
std::vector<T> Sorts<T>::bubbleSort(const std::vector<T> &source)
{
	std::vector<T> v(source);

	for (int i = v.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] > v[j + 1])
			{
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

template <class T>
std::vector<T> Sorts<T>::selectionSort(const std::vector<T> &source)
{
	std::vector<T> v(source);
	int pos;

	for (int i = v.size() - 1; i > 0; i--)
	{
		pos = 0;
		for (int j = 1; j <= i; j++)
		{
			if (v[j] > v[pos])
			{
				pos = j;
			}
		}

		if (pos != i)
		{
			swap(v, i, pos);
		}
	}
	return v;
}

template <class T>
std::vector<T> Sorts<T>::insertionSort(const std::vector<T> &source)
{
	std::vector<T> v(source);

	for (int i = 1; i < v.size(); i++)
	{
		for (int j = i; j > 0 && v[j] < v[j - 1]; j--)
		{
			swap(v, j, j - 1);
		}
	}
	return v;
}

template <class T>
std::vector<T> Sorts<T>::shellSort(const std::vector<T> &source)
{
	std::vector<T> v(source);
	int gap = v.size() / 2;

	while (gap > 0)
	{
		for (int i = gap; i < v.size(); i++)
		{
			for (int j = i; j >= gap && v[j] < v[j - gap]; j -= gap)
			{
				swap(v, j, j - gap);
			}
		}
		gap /= 2;
	}
	return v;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high)
{
	for (int i = low; i <= high; i++)
	{
		A[i] = B[i];
	}
}
template <class T>
std::list<T> Sorts<T>::mergeList(const std::list<T> &lst1, const std::list<T> &lst2)
{	
	std::list<T> copylist1 = lst1;
	std::list<T> copylist2 = lst2;
	int size1 = copylist1.size();
	int size2 = copylist2.size();
	std::list<T> flist;
	while(size1 != 0 && size2 != 0)
	{
		if(copylist1.front() < copylist2.front())
		{
		flist.push_back(copylist1.front());
		copylist1.pop_front();
		size1--;
		}else if(copylist1.front() > copylist2.front())
		{
		flist.push_back(copylist2.front());
		copylist2.pop_front();
		size2--;
		//Elementos igual se elimina de primera lista
		}else if(copylist1.front() == copylist2.front()){
		flist.push_back(copylist1.front());
		copylist1.pop_front();
		size1--;
		}
	}
	if(size1 > 0)
	{
		while(size1 != 0)
		{
		flist.push_back(copylist1.front());
		copylist1.pop_front();
		size1--;
		}
	}else if(size2 > 0)
	{
		while(size2 != 0)
		{
		flist.push_back(copylist2.front());
		copylist2.pop_front();
		size2--;
		}
	}	
	return flist;
}
template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high)
{
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j <= high)
	{
		if (A[i] < A[j])
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		for (; j <= high; j++)
		{
			B[k++] = A[j];
		}
	}
	else
	{
		for (; i <= mid; i++)
		{
			B[k++] = A[i];
		}
	}
}

#endif /* SORTS_H_ */
