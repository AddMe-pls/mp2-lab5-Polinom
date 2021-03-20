#pragma once
#include "ATList.h"
template <class T>
class THeadList : public TList<T>
{
protected:
	TLink<T>* pHead; //*pFirst, *pLast, *pStop;
	//int size;
public:
	THeadList();
	THeadList(const THeadList<T>& l);
	void InsFirst(T elem);
	void DelFirst();
	void InsLast(T elem);
	void InsCurr(T elem);
	void DelCurr();
	~THeadList();
};

template <class T>
THeadList<T>::THeadList() : TList<T>()
{
	TLink<T>* t = new TLink<T>;
	this->pHead = t;
	this->pStop = this->pHead;
	this->pHead->pNext = this->pStop;
	this->pFirst = this->pLast = this->pCurr = this->pPrev = this->pStop;
	//this->pStop = NULL;
}
template<class T>
THeadList<T>::THeadList(const THeadList<T>& l) : TList<T>()
{
	TLink<T>* t = new TLink<T>;
	this->pHead = t;
	this->pStop->pNext = this->pHead;
	if (this->pFirst != NULL)
		this->pHead->pNext = this->pFirst; // ???
	else
		this->pHead->pNext = this->pStop;
}
template <class T>
void THeadList<T>::InsFirst(T elem)
{
	TList<T>::InsFirst(elem);
	this->pHead->pNext = this->pFirst;
}
template <class T>
void THeadList<T>::DelFirst()
{
	TList<T>::DelFirst();
	pHead->pNext = this->pFirst;
}
template<class T>
void THeadList<T>::InsLast(T elem)
{
	TList<T>::InsLast(elem);
	pHead->pNext = this->pFirst;
}
template<class T>
void THeadList<T>::InsCurr(T elem)
{
	TList<T>::InsCurr(elem);
	pHead->pNext = this->pFirst;
}
template<class T>
void THeadList<T>::DelCurr()
{
	TList<T>::DelCurr();
	pHead->pNext = this->pFirst;
}
template <class T>
THeadList<T>::~THeadList()
{
	TLink<T>* tmp;
	while (this->pFirst != this->pStop)
	{
		tmp = this->pFirst->pNext;
		delete this->pFirst;
		this->pFirst = tmp;
	}
	this->pLast = this->pFirst;
	this->size = 0;
	delete this->pHead;
}
