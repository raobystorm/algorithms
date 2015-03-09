// POJ_1001.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>

using namespace std;

class BigNum{
public:
	string Num;
	int dotPos;				// the exp of 10 of the last char in Num, eg. dotPos = -3 for 0.125

	BigNum(){ Num = ""; dotPos = 0; }
	BigNum(const string& s);
	BigNum operator*(const BigNum&) const;
	BigNum exp(int x);
	void print();
};

BigNum::BigNum(const string& s){

	int pos = s.find('.');
	if (pos != -1 && pos != s.length()-1){

		Num = s.substr(0 ,s.find_last_not_of('0')+1);
		dotPos = pos - Num.length() + 1;
		Num = Num.substr(0, pos) + Num.substr(pos+1);
	}
	else{

		dotPos = 0;
		Num = s;
		if (pos != -1) Num = Num.substr(0, Num.find_last_not_of("."));
	}
}

inline void BigNum::print(){
	
	if (abs(dotPos) > Num.length()){
	
		printf(".");
		for (int i = dotPos + Num.length(); i < 0; i++)
			printf("0");

		printf("%s\n", Num.c_str());
	}
	else if (dotPos < 0){

		printf("%s.%s\n", Num.substr(0, dotPos + Num.length()).c_str(), Num.substr(dotPos + Num.length()).c_str());
	}
	else{
	
		printf("%s\n", Num.c_str());
	}
}

BigNum BigNum::exp(int x){

	if (x == 1) return *this;

	BigNum n1 = *this;
	for (int i = 1; i < x; i++){
	
		n1 = n1 * *this;
	}

	return n1;
}

BigNum BigNum::operator*(const BigNum& n2) const{

	BigNum res;
	res.Num = Num + n2.Num;

	for (int i = 0; i < res.Num.length(); i++) res.Num[i] = '0';

	int a, b, c = 0;

	for (int i = Num.length()-1; i >= 0; i--){
	
		a = Num[i] - '0';
		for (int j = n2.Num.length()-1; j >= 0; j--){
		
			b = n2.Num[j] - '0';
			c += a*b;
			c += res.Num[i+j+1]-'0';
			res.Num[i+j+1] = (c % 10) + '0';
			c /= 10;
		}
		while (c != 0){
			res.Num[i] += c % 10;
			c /= 10;
		}
	}

	res.dotPos = dotPos + n2.dotPos;
	res.Num = res.Num.substr(res.Num.find_first_not_of('0'));
	return res;
}

int main()
{
	string a;
	int e;

	while (cin>>a>>e){
	
		BigNum res = BigNum(a).exp(e);
		res.print();
	}
	
	return 0;
}

