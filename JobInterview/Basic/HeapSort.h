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

#include <cassert>
#include <iterator>

namespace basic
{
template <typename _TIterator>
void MakeHeap(_TIterator begin, _TIterator end)
{
	const size_t size = std::distance(begin, end);
	for (size_t i = 1; i < size; ++i)
	{
		for (size_t child = i, parent = (child - 1) / 2; child > 0 && begin[child] > begin[parent]; child = parent, parent = (child - 1) / 2)
			std::swap(begin[child], begin[parent]);
	}
}

template <typename _TIterator>
bool IsHeap(_TIterator begin, _TIterator end)
{
	const size_t size = std::distance(begin, end);
	for (size_t i = 1; i < size; ++i)
	{
		const size_t j = (i - 1) / 2;
		if (begin[i] > begin[j])
			return false;
	}
	return true;
}

template <typename _TIterator>
void HeapSort(_TIterator begin, _TIterator end)
{
	assert(IsHeap(begin, end));
	if (begin < end)
	{
		const size_t size = std::distance(begin, end);
		for (size_t i = std::distance(begin, end) - 1; i; --i)
		{
			std::swap(begin[0], begin[i]);
			for (size_t parent = 0, child1; child1 = 2 * parent + 1, child1 < i;)
			{
				const size_t child2 = 2 * parent + 2;
				if (child2 < i && begin[child2] > begin[child1])
				{
					if (begin[child2] > begin[parent])
						std::swap(begin[child2], begin[parent]);
					else
						break;
					parent = child2;
				}
				else
				{
					if (begin[child1] > begin[parent])
						std::swap(begin[child1], begin[parent]);
					else
						break;
					parent = child1;
				}
			}
			assert(IsHeap(begin, begin + i));
		}
	}
}
}
