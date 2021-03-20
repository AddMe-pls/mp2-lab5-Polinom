#pragma once
#include <iostream>
#include "Header.h"

template <class T>
class TList
{
protected:
	TLink<T>* pFirst;
	TLink<T>* pLast;
	TLink<T>* pCurr;
	TLink<T>* pPrev;
	TLink<T>* pStop;
	int size;
	int pos;
public:
	TList()
	{
		pStop = NULL;
		pFirst = pStop;
		pLast = pFirst;
		pCurr = pStop;
		pPrev = pStop;
		size = 0;
		pos = 0;
	}
	~TList()
	{
		TLink<T>* tmp;
		while (pFirst != pStop)
		{
			tmp = pFirst->pNext;
			delete pFirst;
			pFirst = tmp;
		}
		pLast = pFirst;
		size = 0;
	}
	TList(const TList<T>& l)
	{
		if (l.pFirst == l.pStop)
		{
			pStop = NULL;
			pFirst = pStop;
			pLast = pFirst;
			size = 0;
		}
		else
		{
			pStop = NULL;
			size = l.size;
			TLink<T>* tmp = new TLink<T>;
			tmp->val = l.pFirst->val;
			pFirst = tmp;
			TLink<T>* tmp1 = l.pFirst;
			while (tmp1 != l.pStop)
			{
				tmp1 = tmp1->pNext;
				TLink<T>* tmp2 = new TLink<T>;
				tmp2->pNext = pStop;
				tmp2->val = tmp1->val;
				tmp->pNext = tmp2;
				tmp = tmp2;
			}
			pLast = tmp;
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const TList<T> l)
	{
		TLink<T>* t = l.pFirst;
		while (t != l.pStop)
		{
			out << t->val << ' ';
			t = t->pNext;
		}
		return out;
	}
	void InsFirst(T elem)
	{
		if (size == 0)
		{
			pFirst = new TLink<T>;
			pFirst->val = elem;
			pFirst->pNext = pStop;
			pLast = pFirst;
		}
		else
		{
			TLink<T>* t = new TLink<T>;
			t->pNext = pFirst;
			t->val = elem;
			pFirst = t;
		}
		size++;
	}
	void InsLast(T elem)
	{
		if (size == 0)
			InsFirst(elem);
		else
		{
			TLink<T>* t = new TLink<T>;
			t->pNext = pStop;
			t->val = elem;
			pLast->pNext = t;
			pLast = t;
			size++;
		}
	}
	void DelFirst()
	{
		if (size == 0)
			throw 0;
		else
		{
			TLink<T>* t = pFirst;
			pFirst = pFirst->pNext;
			delete t;
		}
		size--;
	}
	void DelCurr()
	{
		if (pCurr == pStop || size == 0)
			throw 0;
		if (pCurr == pFirst)
			DelFirst();
		else
		{
			TLink<T>* t = pCurr;
			pPrev->pNext = pCurr->pNext;
			delete t;
			pCurr = pPrev->pNext;
			size--;
		}
	}
	void InsCurr(T elem)
	{
		if (size == 0)
			InsLast(elem);
		else
			if (pCurr == pFirst)
				InsFirst(elem);
			else
			{
				TLink<T>* t = new TLink<T>;
				t->val = elem;
				t->pNext = pCurr;
				pPrev = t;
				size++;
			}
	}
	T GetCurr()
	{
		return pCurr->val;
	}
	void SetCurr(T elem)
	{
		pCurr->val = elem;
	}
	void Reset()
	{
		pCurr = pFirst;
		//pPrev = pCurr;
		//pCurr = pCurr->pNext;
	}
	bool IsEnd()
	{
		if (pCurr->pNext == pStop)
			return true;
		else return false;
	}
	void GoNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}
};
