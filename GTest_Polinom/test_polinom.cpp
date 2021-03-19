#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "../TPolinom/TPolinom.h"
#include "gtest.h"

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_copy_list)
{
	TList<int> list;
	ASSERT_NO_THROW(TList<int> list1(list));
}

TEST(TList, can_insert_link_first)
{
	TList<int> list;
	ASSERT_NO_THROW(list.InsFirst(5));
}

TEST(TList, can_insert_link_last)
{
	TList<int> list;
	ASSERT_NO_THROW(list.InsLast(5));
}

TEST(TList, can_insert_link_curr)
{
	TList<int> list;
	ASSERT_NO_THROW(list.InsCurr(5));
}

TEST(TList, can_get_link_value)
{
	TList<int> list;
	list.InsCurr(5);
	list.Reset();
	//list.InsCurr(6);
	ASSERT_NO_THROW(list.GetCurr());
}

TEST(TList, taken_value_is_right)
{
	TList<int> list;
	list.InsCurr(5);
	list.Reset();
	int a = list.GetCurr();
	EXPECT_EQ(a, 5);
}

TEST(TList, can_del_curr_link)
{
	TList<int> list;
	list.InsCurr(5);
	list.Reset();
	ASSERT_NO_THROW(list.DelCurr());
}



TEST(TList, copied_list_equal_source)
{
	TList<int> list;
	list.InsCurr(5);
	list.Reset();
	TList<int> list1(list);
	list1.Reset();
	EXPECT_EQ(list.GetCurr(), list1.GetCurr());
}

TEST(THeadList, can_create_head_list)
{
	ASSERT_NO_THROW(THeadList<int> hlist);
}

TEST(THeadList, can_insert_link_first)
{
	THeadList<int> hlist;
	ASSERT_NO_THROW(hlist.InsFirst(5));
}

TEST(THeadList, can_insert_link_last)
{
	THeadList<int> hlist;
	ASSERT_NO_THROW(hlist.InsLast(5));
}

TEST(THeadList, can_insert_link_curr)
{
	THeadList<int> hlist;
	ASSERT_NO_THROW(hlist.InsCurr(5));
}

TEST(THeadList, taken_value_is_right)
{
	THeadList<int> hlist;
	hlist.InsCurr(5);
	hlist.Reset();
	EXPECT_EQ(hlist.GetCurr(), 5);
}

TEST(THeadList, can_del_link)
{
	THeadList<int> hlist;
	hlist.InsCurr(5);
	hlist.Reset();
	ASSERT_NO_THROW(hlist.DelCurr());
}

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom m);
}

TEST(TMonom, can_create_monom_with_value)
{
	ASSERT_NO_THROW(TMonom m(1, 0, 0, 0));
}

TEST(TMonom, can_compare_monoms)
{
	TMonom m(1, 1, 0, 0), m1(1, 0, 1, 0);
	EXPECT_EQ(m > m1, 1);
}

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, can_insert_monom)
{
	TPolinom p;
	TMonom m;
	ASSERT_NO_THROW(p.InsMonom(m));
}

TEST(TPolinom, can_copy_polinom)
{
	TMonom m;
	TPolinom p;
	p.InsMonom(m);
	ASSERT_NO_THROW(TPolinom p1(p));
}

TEST(TPolinom, copied_polinom_equal_source)
{
	TMonom m(1,1,1,1);
	TPolinom p;
	p.InsMonom(m);
	p.Reset();
	TPolinom p1(p);
	p1.Reset();
	TMonom m1 = p1.GetCurr(), m2 = p.GetCurr();
	EXPECT_EQ(m1== m2, 1);
}

TEST(TPolinom, can_add_polinom_to_polinom)
{
	TMonom m;
	TPolinom p;
	p.InsMonom(m);
	TPolinom p1;
	ASSERT_NO_THROW(p1 += p);
}

TEST(TPolinom, addition_is_correct)
{
	TMonom m(1, 1, 0, 0);
	TPolinom p;
	p.InsMonom(m);
	TPolinom p1;
	p1 += p;
	p1.Reset();
	TMonom m1 = p1.GetCurr();
	EXPECT_EQ(m1 == m, 1);
}
