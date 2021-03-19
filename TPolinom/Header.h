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
	int operator < (const TMonom& m);
	int operator > (const TMonom& m);
	int operator == (const TMonom& m);
	TMonom& operator = (const TMonom& m);
	TMonom();
	TMonom(int _coeff, int x, int y, int z);
	friend std::ostream& operator<<(std::ostream& out, const TMonom& m);
	friend std::istream& operator>>(std::istream& in, TMonom& m);
};

int TMonom::operator < (const TMonom& m)
{
	int s = x*100 + y*10 + z;
	int s1 = m.x*100 + m.y*10 + m.z;
	return ((s < s1) ? 1 : 0);
}

int TMonom::operator > (const TMonom& m)
{
	int s = x*100+ y*10 + z;
	int s1 = m.x*100 + m.y*10 + m.z;
	return ((s > s1) ? 1 : 0);
}

int TMonom::operator == (const TMonom& m)
{
	int s = x*100 + y*10 + z;
	int s1 = m.x*100 + m.y*10 + m.z;
	return ((s == s1) ? 1 : 0);
}

TMonom& TMonom :: operator = (const TMonom& m)
{
	x = m.x;
	y = m.y;
	z = m.z;
	coeff = m.coeff;
	return *this;
}

TMonom::TMonom()
{
	x = 0;
	y = 0;
	z = 0;
	coeff = 0;
}

TMonom::TMonom(int _coeff, int _x, int _y, int _z)
{
	x = _x;
	y = _y;
	z = _z;
	coeff = _coeff;
}

std::ostream& operator<<(std::ostream& out, const TMonom& m)
{
	out << m.coeff << "x^" << m.x << "y^" << m.y << "z^" << m.z;
	return out;
}

std::istream& operator >> (std::istream& in, TMonom& m)
{
	in >> m.coeff;
	in >> m.x;
	in >> m.y;
	in>> m.z;
	return in;
}