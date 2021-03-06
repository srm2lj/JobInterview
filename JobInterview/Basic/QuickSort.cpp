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

#include <string>
#include <boost/test/auto_unit_test.hpp>
#include "QuickSort.h"

BOOST_AUTO_TEST_CASE(TestQuickSort)
{
	std::string str;
	basic::QuickSort(str.begin(), str.end());
	BOOST_CHECK_EQUAL(str, "");
	for (size_t count = 10; count; --count)
	{
		str = "abcdefgh";
		std::random_shuffle(str.begin(), str.end());
		basic::QuickSort(str.begin(), str.end());
		BOOST_CHECK_EQUAL(str, "abcdefgh");
		str = "abcdefghi";
		std::random_shuffle(str.begin(), str.end());
		basic::QuickSort(str.begin(), str.end());
		BOOST_CHECK_EQUAL(str, "abcdefghi");
	}
}
