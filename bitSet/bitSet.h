
#include <stdlib.h>
#include <string.h>

class bitSet{
	unsigned bitSize; // Round to 8 at construct func
	unsigned byteSize;
	char* dataPtr;

public:
	static const unsigned char* bitMask;

	bitSet(unsigned initSize);

	bool test(unsigned bitIdx);

	void set(unsigned bitIdx);

	void set(unsigned byteIdx, char byte);

	void reset(unsigned bitIdx);

	void reset();
	void set();

	~bitSet();
};