// bitSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bitSet.h"

static const unsigned char bitMaskInit[] = { 128, 64, 32, 16, 8, 4, 2, 1 };
const unsigned char* bitSet::bitMask = bitMaskInit;

	bitSet::bitSet(unsigned initSize){
		bitSize = (initSize % 8) ? (initSize / 8 + 1) * 8 : initSize;
		byteSize = bitSize / 8;
		dataPtr = (char*)malloc(sizeof(char) * byteSize);
		if (dataPtr == nullptr) throw;
	}

	bool bitSet::test(unsigned bitIdx){
		if (bitIdx >= bitSize) throw;
		return bitMask[bitIdx % 8] & dataPtr[bitIdx / 8];
	}

	void bitSet::set(unsigned bitIdx){
		if (bitIdx >= bitSize) throw;
		dataPtr[bitIdx / 8] |= bitMask[bitIdx % 8];
	}

	void bitSet::set(unsigned byteIdx, char byte){

		if (byteIdx > byteSize) throw;
		dataPtr[byteIdx] = byte;
	}

	void bitSet::reset(unsigned bitIdx){
		if (bitIdx >= bitSize) throw;
		dataPtr[bitIdx / 8] &= 255 ^ bitMask[bitIdx % 8];
	}

	void bitSet::reset(){
		memset(dataPtr, 0, sizeof(char) * byteSize);
	}

	void bitSet::set(){
		memset(dataPtr, 255, sizeof(char) * byteSize);
	}

	bitSet::~bitSet(){
		bitSize = 0;
		byteSize = 0;
		if (dataPtr != nullptr) free(dataPtr);
	}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

