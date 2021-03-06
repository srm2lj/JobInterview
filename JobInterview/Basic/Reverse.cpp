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
#include "Reverse.h"

BOOST_AUTO_TEST_CASE(TestReverse)
{
	std::string str;
	basic::Reverse(str.begin(), str.end());
	BOOST_CHECK_EQUAL(str, "");
	str = "abcde";
	basic::Reverse(str.begin(), str.end());
	BOOST_CHECK_EQUAL(str, "edcba");
	str = "abcd";
	basic::Reverse(str.begin(), str.end());
	BOOST_CHECK_EQUAL(str, "dcba");
}
