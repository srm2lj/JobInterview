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
//aa
#include <boost/test/auto_unit_test.hpp>

BOOST_AUTO_TEST_CASE(TestTypeSize)
{
	BOOST_CHECK_EQUAL(sizeof(short), 2);
	BOOST_CHECK_EQUAL(sizeof(int), 4);
#ifdef _WIN32
	BOOST_CHECK_EQUAL(sizeof(long), 4);
#else
	BOOST_CHECK_EQUAL(sizeof(long), 8);
#endif
	BOOST_CHECK_EQUAL(sizeof(float), 4);
	BOOST_CHECK_EQUAL(sizeof(double), 8);
#ifdef _WIN32
	BOOST_CHECK_EQUAL(sizeof(long double), 12);
#else
	BOOST_CHECK_EQUAL(sizeof(long double), 16);
#endif
	BOOST_CHECK_EQUAL(sizeof(size_t), sizeof(void *));
}
