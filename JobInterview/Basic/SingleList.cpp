/*!
Copyright (C) 2014, 申瑞珉 (Ruimin Shen)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <list>
#include <boost/test/auto_unit_test.hpp>
#include "SingleList.h"

BOOST_AUTO_TEST_CASE(TestSingleList)
{
	typedef std::list<size_t> _TList;
	typedef basic::SingleList<size_t> _TSingleList;
	_TList list;
	_TSingleList slist;
	for (size_t i = 0; i < 5; ++i)
	{
		list.push_front(i);
		slist.PushFront(i);
	}
	BOOST_CHECK_EQUAL(slist.Size(), list.size());
	BOOST_CHECK_EQUAL(slist.Front(), list.front());
	{
		typename _TList::iterator i;
		typename _TSingleList::Iterator j;
		for (i = list.begin(), j = slist.Begin(); i != list.end(); ++i, ++j)
			BOOST_CHECK_EQUAL(*i, *j);
		BOOST_CHECK(j == slist.End());
	}
	{
		typename _TList::iterator i;
		typename _TSingleList::ConstIterator j;
		const _TSingleList _slist = slist;
		for (i = list.begin(), j = _slist.Begin(); i != list.end(); ++i, ++j)
			BOOST_CHECK_EQUAL(*i, *j);
		BOOST_CHECK(j == _slist.End());
	}
}

BOOST_AUTO_TEST_CASE(TestSingleListAllocator)
{
	typedef std::list<size_t> _TList;
	typedef basic::SingleList<size_t> _TSingleList;
	_TList list;
	std::allocator<size_t> allocator;
	_TSingleList slist(allocator);
	for (size_t i = 0; i < 5; ++i)
	{
		list.push_front(i);
		slist.PushFront(i);
	}
	BOOST_CHECK_EQUAL(slist.Size(), list.size());
}

BOOST_AUTO_TEST_CASE(TestSingleListInitializeFill)
{
	const size_t size = 5;
	const size_t value = 1;
	typedef std::list<size_t> _TList;
	typedef basic::SingleList<size_t> _TSingleList;
	_TList list(size, value);
	_TSingleList slist(size, value);
	BOOST_CHECK_EQUAL(slist.Size(), list.size());
	for (typename _TSingleList::ConstIterator i = slist.Begin(); i != slist.End(); ++i)
		BOOST_CHECK_EQUAL(*i, value);
}
