#pragma once
#include <iostream>
template <class T>
struct TLink
{
	T val;
	TLink* pNext;
};

struct TMonom
{
	double coeff;
	int x, y, z;
	bool operator < (const TMonom& m);
	bool operator > (const TMonom& m);
	bool operator == (const TMonom& m);
	TMonom();
};

bool TMonom::operator < (const TMonom& m)
{
	int s = x + y + z;
	int s1 = m.x + m.y + m.z;
	return (s < s1) ? true : false;
}

bool TMonom::operator > (const TMonom& m)
{
	int s = x + y + z;
	int s1 = m.x + m.y + m.z;
	return (s > s1) ? true : false;
}

bool TMonom::operator == (const TMonom& m)
{
	int s = x + y + z;
	int s1 = m.x + m.y + m.z;
	return (s == s1) ? true : false;
}

TMonom::TMonom()
{
	x = 0;
	y = 0;
	z = 0;
	coeff = 0;
}

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
		//pCurr = pStop;
		//pPrev = pStop;
		size = 0;
		//pos = 0;
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
				tmp2->val = tmp1.val;
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
		if (pFirst == pStop)
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
		if (pFirst == pStop)
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
		if (pFirst == pStop)
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
		if (pCurr == pStop)
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
		if (pCurr == pStop)
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

//template <class T>
//class THeadList : public TList<T>
//{
//protected:
//	TLink<T>* pHead;
//public:
//	THeadList() :TList()
//	{
//		TLink<T>* t = new TLink<T>;
//		pHead = t;
//		pStop = pHead;
//		pHead->pNext = pHead;
//    }
//	void InsFirst(T elem)
//	{
//		TList::InsFirst(elem);
//		pHead->pNext = pFirst;
//	}
//	~THeadList()
//	{
//		TLink<T>* tmp;
//		while (pFirst != pStop)
//		{
//			tmp = pFirst->pNext;
//			delete pFirst;
//			pFirst = tmp;
//		}
//		pLast = pFirst;
//		size = 0;
//		delete pHead;
//	}
//};

//class TPolinom : public THeadList<TMonom>
//{
//	TMonom mon;
//public:
//	TPolinom() :THeadList()
//	{
//		mon.z = -1;
//		pHead->val = mon;
//	}
//	void InsMonom(TMonom& m)
//	{
//		for (Reset(); !IsEnd(); GoNext())
//		{
//			if (m > pCurr->val)
//			{
//				InsCurr(m);
//				break;
//			}
//			else
//			{
//				if (m == pCurr->val)
//					if (m.coeff + pCurr->val.coeff == 0)
//					{
//						DelCurr();
//						break;
//					}
//					else
//					{
//						pCurr->val.coeff += m.coeff;
//						break;
//					}
//			}
//		}
//		if (pCurr == pStop)
//			InsLast(m);
//	}
//	TPolinom& operator += (TPolinom& p)
//	{
//		for (p.Reset(); !p.IsEnd(); p.GoNext())
//		{
//			InsMonom(p.pCurr->val);
//			return *this;
//		}
//	}
//	void operator += (const TPolinom& p)
//	{
//		Reset();
//		TLink<TMonom>* curr = p.pFirst;
//		while (curr != p.pStop)
//		{
//			if (pCurr->val < curr->val)
//			{
//				InsCurr(curr->val);
//				curr = curr->pNext;
//			}
//			else
//			{
//				if (pCurr->val == curr->val)
//				{
//					double tmp = pCurr->val.coeff + curr->val.coeff;
//					pCurr->val.coeff = tmp;
//					if (tmp)
//					{
//						GoNext();
//					}
//					else
//					{
//						DelCurr();
//						curr = curr->pNext;
//					}
//				}
//				else GoNext();
//			}
//		}
//	}
//	TPolinom& operator = (TPolinom& p)
//	{
//		if (this == &p)
//			return *this;
//		while (pFirst != pStop)
//			DelFirst();
//		for (p.Reset(); !p.IsEnd(); p.GoNext())
//		{
//			InsLast(p.pCurr->val);
//			return *this;
//		}
//	}
//};
