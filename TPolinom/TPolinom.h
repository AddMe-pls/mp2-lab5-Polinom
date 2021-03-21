#pragma once
#include"THeadList.h"
class TPolinom : public THeadList<TMonom>
{
	TMonom mon;
public:
	TPolinom() :THeadList<TMonom>()
	{
		mon.z = -1;
		pHead->val = mon;
	}
	void InsMonom(TMonom& m)
	{
		Reset();
		while(true)
		{
			if (pCurr == pStop)
			{
				InsLast(m);
				break;
			}
			if (m > pCurr->val)
			{
				InsCurr(m);
				break;
			}
			else
			{
				if (m == pCurr->val) 
				{
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
				GoNext();
			}
		}
		/*for (Reset(); !IsEnd(); GoNext())
		{
			if (m > pCurr->val)
			{
				InsCurr(m);
				break;
			}
			else {
				if (m == pCurr->val)
				{
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
				if (pCurr == pStop)
					InsLast(m);
			}
		}
		/*if (pCurr == pStop)
			InsLast(m);*/
	}
	/*TPolinom& operator += (TPolinom& p)
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			InsMonom(p.pCurr->val);
			return *this;
		}
	}*/
	TPolinom& operator += (const TPolinom& p)
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
					}
						curr = curr->pNext;
					
				}
				else GoNext();
			}
		}
		return *this;
	}
	TPolinom& operator *= (TPolinom& p)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			TLink<TMonom>* curr = p.pFirst;
			TPolinom tmp;
			while (curr != p.pStop)
			{
				TMonom tmp1;
				tmp1.coeff = pCurr->val.coeff * curr->val.coeff;
				tmp1.x = pCurr->val.x * curr->val.x;
				tmp1.y = pCurr->val.y * curr->val.y;
				tmp1.z = pCurr->val.z * curr->val.z;
				tmp.InsLast(tmp1);
				curr = curr->pNext;
			}
			*this += tmp;
		}
		return *this;
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
	void print()
	{
		TLink<TMonom> *t = pFirst;
		while (t->pNext != pHead)
		{
			if (t->val.coeff != 0) {
				std::cout << t->val << " ";
				t = t->pNext;
			}
		}
		std::cout<<std::endl;
	}
};
