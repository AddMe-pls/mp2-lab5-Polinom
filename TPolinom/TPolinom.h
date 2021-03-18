#pragma once
#include"THeadList.h"
class TPolinom : public THeadList<TMonom>
{
	TMonom mon;
public:
	TPolinom() :THeadList()
	{
		mon.z = -1;
		pHead->val = mon;
	}
	void InsMonom(TMonom& m)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			if (m > pCurr->val)
			{
				InsCurr(m);
				break;
			}
			else
			{
				if (m == pCurr->val)
					if (m.coeff + pCurr->val.coeff == 0)
					{
						DelCurr();
						break;
					}
					else
					{
						pCurr->val.coeff += m.coeff;
						break;
					}
			}
		}
		if (pCurr == pStop)
			InsLast(m);
	}
	TPolinom& operator += (TPolinom& p)
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			InsMonom(p.pCurr->val);
			return *this;
		}
	}
	void operator += (const TPolinom& p)
	{
		Reset();
		TLink<TMonom>* curr = p.pFirst;
		while (curr != p.pStop)
		{
			if (pCurr->val < curr->val)
			{
				InsCurr(curr->val);
				curr = curr->pNext;
			}
			else
			{
				if (pCurr->val == curr->val)
				{
					double tmp = pCurr->val.coeff + curr->val.coeff;
					pCurr->val.coeff = tmp;
					if (tmp)
					{
						GoNext();
					}
					else
					{
						DelCurr();
						curr = curr->pNext;
					}
				}
				else GoNext();
			}
		}
	}
	TPolinom& operator = (TPolinom& p)
	{
		if (this == &p)
			return *this;
		while (pFirst != pStop)
			DelFirst();
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			InsLast(p.pCurr->val);
			return *this;
		}
	}
};
