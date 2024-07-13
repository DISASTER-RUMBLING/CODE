#pragma once

namespace dis{
	class String {
		typedef char* iterator;

	public:

		String(const char* str = ""){
			_size = strlen(str);
			_str = new char[_size + 1];
			strcpy(_str, str);
			_capacity = _size;
		}

		String(const String& h) {
			_str = new char[h._size + 1];
			this->_size = h._size;
			this->_capacity = h._capacity;
			strcpy(_str, h._str);
		}

		~String()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		size_t size() const {
			return _size;
		}

		size_t capacity() const {
			return _capacity;
		}

		iterator begin() const {
			return _str;
		}

		iterator end() const {
			return _str + _size;
		}

		iterator c_str() {
			return _str;
		}

		void clear(){
			if (_capacity > 0) {
				char* tmp = new char[_capacity+1];
				tmp[0] = '\0';
				delete[] _str;
				_str = tmp;
				_size = 0;
			}
		}

		bool empty() const {
			return _size == 0;
		}

		void reserve(const size_t n=0){
			assert(n >= 0);
			if (_capacity < n) {
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
			else if (_capacity > n) {
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				_capacity = _size = n;
				delete[] _str;
				_str = tmp;
			}
			_capacity = n;
			return;
		}

		void insert(const char p,const size_t pos) {
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			for (int i = _size; i >=(int)pos; i--) {
				_str[i+1] = _str[i];
			}
			_str[pos] = p;
			_size++;
			return;
		}

		void push_back(const char p) {
			return insert(p, _size);
		}

		void append(const char* p) {
			size_t len = strlen(p);
			if (_size + len > _capacity) {
				reserve(_capacity == 0 ? len : _capacity + len);
			}
			strcpy(_str + _size, p);
			_size += len;
			return;
		}

		void insert(const char* p, const size_t pos){
			assert(pos >= 0);
			size_t len = strlen(p);
			if (_size == _capacity) {
				reserve(_capacity == 0 ? len : _capacity + len);
			}
			if (len > 0) {
				for (int i = _size; i >= pos; i++) {
					_str[i] = _str[i + len];
				}
				strcpy(_str + pos, p);
				_size += len;
			}
			return;
		}

		void erase(const size_t pos, const size_t len = 1) {
			assert((pos + len < _size) && len > 0);
			for (int i = pos + len; i <= _size; i++) {
				_str[i - len] = _str[i];
			}
			_size -= len;
			return;
		}

		void resize(size_t num,const char p='\0') {
			if (num > _size) {
				if (num > _capacity) {
					reserve(num);
					_capacity = num;
				}
				for (int i = _size; i <= num; i++) {
					_str[i] = p;
				}
			}
			else if (num < _size) {
				reserve(num);
			}
			_size = num;
			return;
		}

		iterator find(const char p, const size_t pos = 0) {
			for (int i = pos; i <= _size; i++) {
				if (_str[i] == p) {
					return _str + i;
				}
			}
			return end();
		}

		char back() const {
			assert(_size == 0);
			return _str[_size];
		}

		char& front() const {
			assert(_size == 0);
			return _str[0];
		}

		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const{
			assert(pos < _size);
			return _str[pos];
		}

		String& operator=(const String& h) {
			if (this != &h) {
				String tmp(h);
				std::swap(_str, tmp._str);
				_size = tmp._size;
				_capacity = tmp._capacity;
			}
			return *this;
		}

		bool operator==(const String& h) const {
			return strcmp(h._str, _str);
		}

		bool operator<(const String& h) {
			return strcmp(h._str, _str);
		}
		
		void operator+=(char p) {
			push_back(p);
			return;
		}
		
		//不能使用引用返回，因为h是一个临时变量，在函数结束时会被析构
		String substr(size_t pos, int len = npos) const {
			String h;  
			size_t tar = len == npos ? _size : len;
			for (int i = pos; i < +pos + tar; i++) {
				h += _str[i];
			}
			return h;
		}

		void swap(String& h) {
			std::swap(h._str, _str);
			std::swap(h._size, _size);
			std::swap(h._capacity, _capacity);

			return;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static int npos = -1;
	};

	ostream& operator<<(ostream& out,const String& h) {
		size_t len = h.size();
		for (int i = 0; i < len; i++) {
			out << h[i];
		}
		return out;
	}

	istream& operator>>(istream& in, String& h) {
		h.clear();
		char p = getchar();
		while (p != '\n' && p != ' ') {
			h += p;
			p = getchar();
		}
		p += '\0';
		return in;
	}

}