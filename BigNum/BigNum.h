
#include "string"

using namespace std;

class BigNum{
public:

	string sNum;								// because the sign is saved in "sign", we just leave absolute value in this string
	int length;

	enum Sign{ positive = 1,					// if this int is above 0 then it's a positive, below 0 it's a negative
		zero = 0,
		negative = -1 } sign;	

	int dotPos;									// we store the position of dot here. 0 for integer and -3 for 0.125, 50 for 1.e+50
	bool isExact;								// if we dont need exact float values, we only store 50 digits in sNum

	// constructors & destuctors here
	BigNum();
	~BigNum();
	BigNum(const string&);
	BigNum(BigNum&);
	BigNum(const long);
	BigNum(const double);
	
	Sign getSign();
	const string& getString();
	bool inputNum(const string&);
	void printNum();
	bool isAFloat();

	int operator[](int i);

	BigNum operator+(const BigNum&) const;
	BigNum operator-(const BigNum&) const;
	BigNum operator*(const BigNum&) const;
	BigNum operator/(const BigNum&) const;
};