#include <iostream>
#include "hw3_BigNUMv2_ANS.h"
using namespace std;

BigNUM::BigNUM(long long int a,int b) {
	if (b <= 0) {
		m = new int[1];
		a = 1;
		size = 1;
		m[0] = 1;
	}
	else if (b == 1) {
		long long int x = a, y = a;
		if (a == 0) {
			m = new int[1];
			size = 1;
			m[0] = 0;
		}
		else {
			size = 0;
			while (x > 0) {
			++size;
			x /= 1000;
			}
			m = new int[size+1];
			for (int i = 1; i <= size;++i) {
				m[i] = y % 1000;
				y /= 1000;
			}
		}
	}
	else{
		double c;
		int y;
		c = log10(a)*b;
		int x = c;
		if (x % 3)
			size = x / 3 + 2;
		else
			size = x / 3 + 1;
		m = new int[size];
		if (a < 0) {
			y = -a;
			if (b % 2) {
				t = false;
			}
		}
		else
		{
			y = a;
		}
		for (int i=0; i < b-1; ++i) {
			for (int j = 1; j <= size; ++j) {
				if (m[j] != NULL) {
					m[j] *= y;
				}
				else {
					break;
				}
			}
			for (int j = 1; j <= size; ++j) {
				if (m[j] != NULL) {
					if (m[j] > 1000) {
						int k = m[j]/1000;
						m[j] = m[j] % 1000;
						m[j+1] = m[j+1] + k;
					}
				}
				else {
					break;
				}
			}
		}
	}
}
BigNUM::~BigNUM() {
	delete[] m;
}
BigNUM::BigNUM(const BigNUM &x) {
	size = x.size;
	memset(m, 0, sizeof(m));
	for (int i = 0; i < x.size; i++) {
		m[i] = x.m[i];
	}
}
bool BigNUM::operator<(const BigNUM& rhs) const {
	if (size < rhs.size) return true;
	else if (size == rhs.size) {
		for (int i = size - 1; i >= 0; --i) {
			if (m[i] < rhs.m[i]) return true;
			else if (m[i] > rhs.m[i]) return false;
		}
		return false;
	}
	else {
		return false;
	}
}
bool BigNUM::operator>(const BigNUM& rhs) const {
	if (size > rhs.size) return true; 
	else if (size == rhs.size) {
		for (int i = size - 1; i >= 0; --i) {
			if (m[i] > rhs.m[i]) return true;
			else if (m[i] < rhs.m[i]) return false;
		}
		return false;
	}
	else {
		return false;
	}
}
bool BigNUM::operator<=(const BigNUM& rhs) const {
	if ((*this) > rhs) return false;
	else return true;
}
bool BigNUM::operator>=(const BigNUM& rhs) const {
	if ((*this) < rhs) return false;
	else return true;
}
ostream& operator<<(ostream& out,const BigNUM& x) {
	cout << x.m[x.size - 1];
	for (int i = x.size - 2; i >= 0; --i) {
		cout << ",";
		cout.width(3);
		cout.fill('0');
		cout << x.m[i];
	}
	return out;
}
BigNUM &BigNUM::operator=(const BigNUM &x) {
	size = x.size;
	memset(m, 0, sizeof(m));
	for (int i = 0; i < x.size; i++) {
		m[i] = x.m[i];
	}
	return *this;
}
BigNUM BigNUM::operator+(const BigNUM& rhs)const {
	BigNUM x(*this);
	int max,min;
	if (x.size > rhs.size) { 
		max = x.size; 
		min = rhs.size;
	}
	else { 
		max = rhs.size;
		min = x.size;
	}
	if (t==rhs.t) {
		for (int i = 0; i < min; ++i) {
			x.m[i] += rhs.m[i];
			if (x.m[i] >= 1000) {
				x.m[i] = x.m[i] % 1000;
				x.m[i + 1]++;
			}
		}
		if (x.m[max] > 0) {
			x.size = max + 1;
		}
		else {
			x.size = max;
		}
	}
	else {
		if (x > rhs) {
			for (int i = 0; i < min; ++i) {
				x.m[i] -= rhs.m[i];
				if (x.m[i] < 0) {
					--x.m[i + 1];
					m[i] = 1000 - m[i];
				}
			}
		}
		else {
			BigNUM y(*this);
			x = rhs;
			x.t = rhs.t;
			for (int i = 0; i < min; ++i) {
				x.m[i] -= y.m[i];
				if (x.m[i] < 0) {
					--x.m[i + 1];
					m[i] = 1000 - m[i];
				}
			}
		}
		if (x.m[max] == 0) {
			x.size = max - 1;
		}
		else {
			x.size = max;
		}
	}
	return x;
}
BigNUM BigNUM::operator-(const BigNUM& rhs)const {
	BigNUM x(*this);
	int max, min;
	if (x.size > rhs.size) {
		max = x.size;
		min = rhs.size;
	}
	else {
		max = rhs.size;
		min = x.size;
	}
	if (t != rhs.t) {
		for (int i = 0; i < min; ++i) {
			x.m[i] += rhs.m[i];
			if (x.m[i] >= 1000) {
				x.m[i] = x.m[i] % 1000;
				x.m[i + 1]++;
			}
		}
		if (x.m[max] > 0) {
			x.size = max + 1;
		}
		else {
			x.size = max;
		}
	}
	else {
		if (x > rhs) {
			for (int i = 0; i < min; ++i) {
				x.m[i] -= rhs.m[i];
				if (x.m[i] < 0) {
					--x.m[i + 1];
					m[i] = 1000 - m[i];
				}
			}
		}
		else {
			BigNUM y(*this);
			x = rhs;
			x.t = rhs.t;
			for (int i = 0; i < min; ++i) {
				x.m[i] -= y.m[i];
				if (x.m[i] < 0) {
					--x.m[i + 1];
					m[i] = 1000 - m[i];
				}
			}
		}
		if (x.m[max] == 0) {
			x.size = max - 1;
		}
		else {
			x.size = max;
		}
	}
	return x;
}
BigNUM &BigNUM::operator-() {
	if (t)
		t = false;
	else
		t = true;
	return *this;
}
BigNUM BigNUM::operator*(const BigNUM& rhs)const {
	BigNUM x(*this);
	BigNUM y;
	y.size = x.size + rhs.size;
	y.m = new int[y.size];
	for (int i = 0; i < rhs.size; ++i) {
		for (int j = 0; j < x.size; ++j) {
			y.m[i + j] = rhs.m[i] * x.m[j] + y.m[i + j];
			if (y.m[i + j] >= 1000) {
				int a = y.m[i + j] / 1000;
				y.m[i + j] = y.m[i + j] % 1000;
				y.m[i + j + 1] = y.m[i + j + 1] + a;
			}
		}
	}
	return y;
}
