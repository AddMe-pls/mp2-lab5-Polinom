#pragma once
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
};

bool TMonom::operator < (const TMonom& m)
{
	int s = x + y + z;
	int s1 = m.x + m.y + m.z;
	return (s < s1) ? true : false;
}

template <class T>
class TList
{
protected:
	TLink<T>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	int size, pos;
public:
	TList()
	{
		pStop = nullptr;
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
			pStop = nullptr;
			pFirst = pStop;
			pLast = pFirst;
			size = 0;
		}
		else
		{
			pStop = nullptr;
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
				InsFirs(elem);
			else
			{
				TLink<T>* t = new TLink<T>;
				t->val = elem;
				t->pNext = pCurr;
				pPrev = t;
				size++;
			}
	}
};

