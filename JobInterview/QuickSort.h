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

#pragma once

#include <iterator>

template <typename _TIterator>
void QuickSort(_TIterator begin, _TIterator end)
{
	if (begin < end)
	{
		typename std::iterator_traits<_TIterator>::value_type key = *begin;
		_TIterator i = begin, j = end - 1;
		while (i < j)
		{
			while (i < j && *i < key)
				++i;
			while (i < j && *j > key)
				--j;
			std::swap(*i, *j);
		}
		assert(i == j);
		assert(*i == key);
		QuickSort(begin, i);
		QuickSort(++j, end);
	}
}
