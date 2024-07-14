#pragma once 

namespace dis {
	template<class T>
	class Vector {
		typedef T* iterator;
		typedef const T* const_iterator;

	public:

		Vector()
			:_start(nullptr)
			, _end(nullptr)
			, _end_of_storage(nullptr)
		{}

		Vector(const Vector& now) {
			size_t storage = (now._end_of_storage - now._start) / sizeof(T);
			size_t len = (now._end - now._start) / sizeof(T);
			_start = new T[storage];
			_end = _start + len;
			_end_of_storage = _start + storage;
			std::memcpy(_start, now._start, storage);
			return this;
		}

		~Vector()
		{
			delete[] _start;
			_start = _end = _end_of_storage = nullptr;
		}

		size_t size() const {
			return _start == 0 ? 0 : _end - _start;
		}

		size_t capacity() const {
			return _start == 0 ? 0 : _end_of_storage - _start;
		}

		const_iterator begin() const {
			assert(_start == nullptr);
			return _start;
		}

		const_iterator end() const {
			assert(_start == nullptr);
			return _end;
		}

		bool empty() const {
			return _start == nullptr ? true : (_end - _start == 0 ? true : false);
		}

		T& front() {
			assert(_start == nullptr);
			return *_start;
		}

		T& back() {
			assert(_start == nullptr);
			return *_end;
		}

		void clear() {
			assert(_start == nullptr);
			_end = _start;
			return;
		}

		void reserve(const size_t num) {
			assert(num >= 0);
			if ((_end_of_storage - _start)/sizeof(T) < num) {
				size_t len = (_end - _start) / sizeof(T);
				T* tmp = new T[sizeof(T) * (num)];
				std::memcpy(tmp, _start, _end - _start);
				delete[] _start;
				_start = tmp;
				_end = _start + len;
				_end_of_storage = _start + num;
			}
			else if (_end_of_storage - _start > num) {
				T* tmp = new T[sizeof(T) * num];
				std::memcpy(tmp, _start, sizeof(T) * num);
				delete[] _start;
				_start = tmp;
				_end = _start + num;
				_end = _start + num;
			}
			return;
		}

		void insert(T& nw, size_t pos) {
			assert(pos >= 0 && pos < ((_end - _start) / sizeof(T)));
			if (_end == _end_of_storage) {
				reserve(_start == nullptr ? 4 : capacity() * 2);
			}
			for (int i = _end; i >= _start + sizeof(T) * pos; i--) {
				_start[i] = _start[i - 1];
			}
			*_start[i] = nw;
			_end++;
			return;
		}

		void erase(iterator pos) {
			assert(pos >= begin() && pos <= end());
			for (iterator i = pos; i < _end;i++) {
				*i = *(i + 1);
			}
			_end--;
			return;
		}

		void erase(const_iterator first, const_iterator last) {
			assert(first >= begin() && first < end() && last >= begin() && last <= end());
			iterator now = first;
			for (iterator i = last + 1; i < _end; i++) {
				*(now++) = i;
			}
			_end -= (last - first) / sizeof(T);
			return;
		}

		void push_back(const T& nw) {
			if (_end == _end_of_storage) {
				reserve(_start == nullptr ? 4 : capacity() * 2);
			}
			*_end = nw;
			_end++;
			return;
		}

		void pop_back() {
			assert(_start == nullptr && _start != _end);
			_end--;
			return;
		}

		void swap(Vector& now) {

		}

		T& operator[](size_t pos) {
			assert(pos < size() && pos >= 0);
			return _start[pos];
		}

		Vector operator=(const Vector& now) {
			Vector tmp(now);
			std::swap(this->_start, tmp._start);
			std::swap(this->_end, tmp._end);
			std::swap(this->_end_of_storage, tmp._end_of_storage);
			return this;
		}

	private:
		iterator _start;
		iterator _end;
		iterator _end_of_storage;
	};
}