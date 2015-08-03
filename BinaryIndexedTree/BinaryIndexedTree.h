/*Copyright by raoby, 2015*/


#include <vector>

template<typename T>
class BIT{
	std::vector<T> nums;
	T lowbit(T x);
public:
	BIT<T>(T n = 0);
	void setVal(T x, T val);
	T getVal(T x);
	void add(T x, T y);
	T sum(T x);
};