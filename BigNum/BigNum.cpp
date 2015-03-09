// BigNum.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <sstream>
#include "BigNum.h"

BigNum::BigNum() :sNum("0"), length(1), sign(zero), dotPos(0), isExact(false){}

BigNum::~BigNum(){

	if (length != 0 && &sNum != NULL){
	
		sNum.~basic_string();
	}
	length = 0;
	sign = zero;
	dotPos = 0; 
	isExact = false;
}


BigNum::BigNum(const double num){

	stringstream ss;
	ss << num;
	ss >> sNum;
	*this = BigNum(sNum);
}

BigNum::BigNum(const string& s){

	sNum = s;

	int pos = sNum.find('.');
	// see if it is a float or not
	if (pos != -1){
		if (sNum.find_last_not_of('0') == pos){
			sNum = sNum.substr(0, pos);
			pos = -1;
		}
	}

	if (sNum.find_first_not_of('0') == -1 ||
		sNum[sNum.find_last_not_of('0')] == '-'){
		// check 0
		sNum = "0";
		length = 1;
		sign = zero;
		dotPos = 0;
		return;
	}

	if (sNum[0] == '-'){

		// if it contains a minus sign, flag & get rid of it and treat it as a positve
		sNum = sNum.substr(1);
		sign = negative;
		pos = sNum.find('.');
	}

	if (pos != -1){
		// float
		sNum = sNum.substr(0, sNum.find_last_not_of('0') + 1);
		dotPos = pos - sNum.length() + 1;
		if (sNum.find_first_not_of('0') == pos){
			sNum = sNum.substr(pos + 1);
			sNum = sNum.substr(sNum.find_first_not_of('0'));
		}
		else {

			sNum = sNum.substr(sNum.find_first_not_of('0'), pos - sNum.find_first_not_of('0')) + sNum.substr(pos + 1);
		}
	}

	else{
		// integer
		sNum = sNum.substr(sNum.find_first_not_of('0'));
		dotPos = sNum.length() - sNum.find_last_not_of('0') - 1;
		sNum = sNum.substr(0, sNum.find_last_not_of('0') + 1);
	}
	if (s[0] == '0' && s.length() == 1) sign = zero;
	else if (sign != negative) sign = positive;

	length = sNum.length();
}

BigNum::BigNum(const long num){

	stringstream ss;
	ss << num;
	ss >> sNum;
	*this = BigNum(sNum);
}

BigNum::BigNum(BigNum& num){

	sNum = num.getString();
	length = num.getString().length();
	sign = num.getSign();
	dotPos = num.isAFloat();
}

bool BigNum::isAFloat(){

	return dotPos < 0 ? true : false;
}

BigNum::Sign BigNum::getSign(){

	return sign;
}

const string& BigNum::getString(){

	return sNum;
}

bool BigNum::inputNum(const string& s){

	try{

		if (s[0] != '-'){

			sNum = s;
			length = s.length();
			if (s[0] == '0' && s.length() == 1) sign = zero;
			else sign = positive;
			return true;
		}
		else{

			sNum = s.substr(1, s.length() - 1);
			length = sNum.length();
			sign = negative;
			return true;
		}
	}
	catch (exception e){
	
		printf("%s", e.what());
		return false;
	}
}

void BigNum::printNum(){

	if (this->getSign() >= 0){
		
		printf("%s\n", this->getString());
	}
	else{
	
		printf("-%s\n", this->getString());
	}
}