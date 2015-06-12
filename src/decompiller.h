#ifndef DECOMPILLER_H
#define DECOMPILLER_H

#include <cstdio>

typedef unsigned int uint;
typedef unsigned long long int uint64;

class Decompiller {
	
	private:
		char ff_magic[8];
		int ff_version, 
			//ff_hightDateTime, 
			//ff_lowDateTime, 
			ff_language, 
			ff_padding, 
			ff_unusedSize, 
			ff_usedSize;
		bool ff_allowOnlineUpdate;
		
		uint64 ff_fileCreationTime;
		
		FILE* f;
		
		bool readInt(int* var);
		bool readBool(bool* var);
		bool readBytes(char* var, unsigned int length);
	public:
		
		Decompiller(const char* filename);
		~Decompiller();
		
		bool read();
};

#endif