#pragma once
#include "TList.h"
template <class T>
class THeadList : public TList<T>
{
protected:
	TLink<T>* pHead; //*pFirst, *pLast, *pStop;
	int size;
public:
	THeadList();
	void InsFirst(T elem);
	~THeadList();
};

template <class T>
THeadList<T>::THeadList() : TList<T>()
{
	TLink<T>* t = new TLink<T>;
	pHead = t;
	pStop = pHead;
	pHead->pNext = pHead;
}
template <class T>
void THeadList<T>::InsFirst(T elem)
{
	TList::InsFirst(elem);
	pHead->pNext = pFirst;
}
template <class T>
THeadList<T>::~THeadList()
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
	delete pHead;
}
