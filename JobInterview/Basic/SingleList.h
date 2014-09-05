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

namespace basic
{
template <typename _T, typename _TAllocator = std::allocator<_T> >
class SingleList
{
public:
	typedef _T T;
	typedef _TAllocator TAllocator;
    typedef TAllocator allocator_type;
	typedef typename TAllocator::value_type value_type;
    typedef typename TAllocator::pointer pointer;
    typedef typename TAllocator::const_pointer const_pointer;
    typedef typename TAllocator::reference reference;
    typedef typename TAllocator::const_reference const_reference;

protected:
	struct _Node
	{
		T value_;
		_Node *next_;
	};
    typedef typename TAllocator::template rebind<_Node>::other _TNodeAllocator;

public:
    class ConstIterator;

	class Iterator
	{
	public:
		Iterator(void);
		Iterator(_Node *pointer);
		~Iterator(void);
		T &operator *(void) const;
		T &operator ++(void);
		bool operator ==(Iterator iterator) const;
		bool operator !=(Iterator iterator) const;

	private:
		_Node *pointer_;

		friend class SingleList<T, TAllocator>::ConstIterator;
	};

	class ConstIterator
	{
	public:
		ConstIterator(void);
		ConstIterator(Iterator iterator);
		ConstIterator(const _Node *pointer);
		~ConstIterator(void);
		const T &operator *(void) const;
		const T &operator ++(void);
		bool operator ==(ConstIterator iterator) const;
		bool operator !=(ConstIterator iterator) const;

	private:
		const _Node *pointer_;
	};

    typedef Iterator iterator;
    typedef ConstIterator const_iterator;

	SingleList(void);
	SingleList(const SingleList &list);
	explicit SingleList(const TAllocator &allocator);
	explicit SingleList(size_t size, const T &value);
	~SingleList(void);
	size_t Size(void) const;
	const T &Front(void) const;
	void PushFront(const T &value);
	Iterator Begin(void);
	Iterator End(void);
	ConstIterator Begin(void) const;
	ConstIterator End(void) const;

private:
	_Node head_;
	_TNodeAllocator nodeAllocator_;
};

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::SingleList(void)
{
	head_.next_ = 0;
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::SingleList(const SingleList &list)
{
	_Node *p = &head_;
	for (ConstIterator i = list.Begin(); i != list.End(); ++i)
	{
		p->next_ = nodeAllocator_.allocate(1);
		p = p->next_;
		p->value_ = *i;
	}
	p->next_ = 0;
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::SingleList(const TAllocator &allocator)
	: nodeAllocator_(allocator)
{
	head_.next_ = 0;
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::SingleList(size_t size, const T &value)
{
	_Node *p = &head_;
	while (size)
	{
		p->next_ = nodeAllocator_.allocate(1);
		p = p->next_;
		p->value_ = value;
		--size;
	}
	p->next_ = 0;
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::~SingleList(void)
{
}

template <typename _T, typename _TAllocator>
size_t SingleList<_T, _TAllocator>::Size(void) const
{
	size_t size = -1;
	for (const _Node *p = &head_; p; p = p->next_)
		++size;
	return size;
}

template <typename _T, typename _TAllocator>
const _T &SingleList<_T, _TAllocator>::Front(void) const
{
	return head_.next_->value_;
}

template <typename _T, typename _TAllocator>
void SingleList<_T, _TAllocator>::PushFront(const T &value)
{
	_Node *node = nodeAllocator_.allocate(1);
	node->value_ = value;
	node->next_ = head_.next_;
	head_.next_ = node;
}

template <typename _T, typename _TAllocator>
typename SingleList<_T, _TAllocator>::Iterator SingleList<_T, _TAllocator>::Begin(void)
{
	return Iterator(head_.next_);
}

template <typename _T, typename _TAllocator>
typename SingleList<_T, _TAllocator>::Iterator SingleList<_T, _TAllocator>::End(void)
{
	return Iterator(0);
}

template <typename _T, typename _TAllocator>
typename SingleList<_T, _TAllocator>::ConstIterator SingleList<_T, _TAllocator>::Begin(void) const
{
	return ConstIterator(head_.next_);
}

template <typename _T, typename _TAllocator>
typename SingleList<_T, _TAllocator>::ConstIterator SingleList<_T, _TAllocator>::End(void) const
{
	return ConstIterator(0);
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::Iterator::Iterator(void)
#ifndef NDEBUG
	: pointer_(0)
#endif
{
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::Iterator::Iterator(_Node *pointer)
	: pointer_(pointer)
{
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::Iterator::~Iterator(void)
{
}

template <typename _T, typename _TAllocator>
_T &SingleList<_T, _TAllocator>::Iterator::operator *(void) const
{
	return pointer_->value_;
}

template <typename _T, typename _TAllocator>
_T &SingleList<_T, _TAllocator>::Iterator::operator ++(void)
{
	pointer_ = pointer_->next_;
	return pointer_->value_;
}

template <typename _T, typename _TAllocator>
bool SingleList<_T, _TAllocator>::Iterator::operator ==(Iterator iterator) const
{
	return pointer_ == iterator.pointer_;
}

template <typename _T, typename _TAllocator>
bool SingleList<_T, _TAllocator>::Iterator::operator !=(Iterator iterator) const
{
	return pointer_ != iterator.pointer_;
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::ConstIterator::ConstIterator(void)
#ifndef NDEBUG
	: pointer_(0)
#endif
{
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::ConstIterator::ConstIterator(Iterator iterator)
	: pointer_(iterator.pointer_)
{
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::ConstIterator::ConstIterator(const _Node *pointer)
	: pointer_(pointer)
{
}

template <typename _T, typename _TAllocator>
SingleList<_T, _TAllocator>::ConstIterator::~ConstIterator(void)
{
}

template <typename _T, typename _TAllocator>
const _T &SingleList<_T, _TAllocator>::ConstIterator::operator *(void) const
{
	return pointer_->value_;
}

template <typename _T, typename _TAllocator>
const _T &SingleList<_T, _TAllocator>::ConstIterator::operator ++(void)
{
	pointer_ = pointer_->next_;
	return pointer_->value_;
}

template <typename _T, typename _TAllocator>
bool SingleList<_T, _TAllocator>::ConstIterator::operator ==(ConstIterator iterator) const
{
	return pointer_ == iterator.pointer_;
}

template <typename _T, typename _TAllocator>
bool SingleList<_T, _TAllocator>::ConstIterator::operator !=(ConstIterator iterator) const
{
	return pointer_ != iterator.pointer_;
}
}
