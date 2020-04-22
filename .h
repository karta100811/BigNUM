#pragma once
#ifndef BigNUMv2_H
#define BigNUMv2_H
#include <iostream>
using namespace std;

class BigNUM {
	friend ostream& operator<<(ostream&, const BigNUM&);
public:
	BigNUM(long long int=0, int=1);
	~BigNUM();
	BigNUM(const BigNUM &);
	bool operator<(const BigNUM&)const;
	bool operator<=(const BigNUM&)const;
	bool operator>(const BigNUM&)const;
	bool operator>=(const BigNUM&)const;
	BigNUM operator+(const BigNUM&)const;
	BigNUM operator-(const BigNUM&)const;
	BigNUM operator*(const BigNUM&)const;
	BigNUM &operator=(const BigNUM&);
	BigNUM &operator-();
private:
	int* m;
	int size;
	bool t = true;
};

#endif // !BigNUMv2_H
