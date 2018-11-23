#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#include <iostream>
#include <assert.h>
#include <string>
#include <algorithm>
using namespace std;
namespace Cbx
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend()  const
		{
			return _finish;
		}
		size_t Size()  const
		{
			return _finish - _start;
		}
		size_t Capacity() const
		{
			return _endOfStorage - _start;
		}
		T& operator[](size_t i)
		{
			assert(i < Size());
			return _start[i];
		}
		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		Vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--)
				PushBack(value);
		}
		template<class InputIterator>   //可以支持别的迭代器
		Vector(InputIterator begin, InputIterator end)   //应将这些指针初始化，否则是随机值
            :_start(nullptr)                          
            , _finish(nullptr)
            , _endOfStorage(nullptr)
		{
			Reserve(end - begin);
			while (begin != end)
			{
				PushBack(*begin);
				begin++;
			}
		}
		Vector(const Vector<T>& v)    //拷贝构造
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(v.Capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}
		Vector<T>& operator=(Vector<T> v)
		{
			Swap(v);
			return *this;
		}
		~Vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
		void Reserve(size_t newcapacity)   //扩容
        {
			size_t sz = Size();
			if (newcapacity > Capacity())
			{
				T* tmp = new T[newcapacity];
				if (_start)
				{
                    for(size_t i=0;i<sz;i++)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endOfStorage = _start + newcapacity;
			}
		}
		void Resize(size_t sz, const T& value = T())
		{
			if (sz <= Size())
			{
				_finish = _start + sz;
                return;
			}
			if (sz > Capacity())
			{
				Reserve(sz);
			}
			iterator it = _finish;
			_finish = _start + sz;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
		void PushBack(const T& x)
		{
			Insert(_finish, x);
		}
		void PopBack()
		{
			Erase(_finish - 1);
		}
		iterator Insert(iterator pos, const T& value)
		{
			assert(pos <= _finish);
			if (_finish == _endOfStorage)
			{
				size_t sz = pos - _start;
				size_t newcapacity = ((Capacity() == 0 )? 2 : Capacity() * 2);  //首次为2，其余2倍
				Reserve(newcapacity);
				pos = _start + sz;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = value;
			++_finish;
			return pos;
		}
		iterator Erase(iterator pos)
		{
			assert(pos < _finish);
			iterator first = pos + 1;
			while (first != _finish)
			{
				*(first - 1) = *first;
				first++;
			}
			--_finish;
			return pos;
		}
		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStorage;
	};
}
#endif
