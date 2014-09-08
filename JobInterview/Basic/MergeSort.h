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

namespace basic
{
template <typename _TIterator>
void Merge(_TIterator begin, _TIterator site, _TIterator end)
{
	typedef typename std::iterator_traits<_TIterator>::value_type _T;
	const size_t size = std::distance(begin, end);
	_T *temp = new _T[size];
	_TIterator i = begin, j = site;
	for (size_t k = 0; k < size; ++k)
	{
		if (i < site && (j == end || *i <= *j))
		{
			temp[k] = *i;
			++i;
		}
		else
		{
			temp[k] = *j;
			++j;
		}
	}
	std::copy(temp, temp + size, begin);
	delete [] temp;
}

template <typename _TIterator>
void MergeSort(_TIterator begin, _TIterator end)
{
	const size_t size = std::distance(begin, end);
	if (size > 1)
	{
		_TIterator site = begin + size / 2;
		MergeSort(begin, site);
		MergeSort(site, end);
		Merge(begin, site, end);
	}
}
}
