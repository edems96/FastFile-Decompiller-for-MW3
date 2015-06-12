#include "decompiller.h"

Decompiller::Decompiller(const char* filename) {
	f = fopen(filename, "rb");
}

Decompiller::~Decompiller() {
	if( f != NULL )
		fclose(f);
}
		
bool Decompiller::read() {
	if( f == NULL )
		return false;
	
	if( !readBytes(ff_magic, 8) )
		return false;
	
	printf("Magic: %s\n", ff_magic);
	
	if( !readInt(&ff_version) )
		return false;
	
	printf("Version: %d\n", ff_version);
	
	if( !readBool(&ff_allowOnlineUpdate) )
		return false;
	
	printf("Allow online update: %d\n", ff_allowOnlineUpdate);
	
	/*if( !readInt(&ff_hightDateTime) )
		return false;
	
	printf("Hight date time: %d\n", ff_hightDateTime);
	
	if( !readInt(&ff_lowDateTime) )
		return false;
	
	printf("Low date time: %d\n", ff_lowDateTime);*/
	
	fread(&ff_fileCreationTime, sizeof(uint64), 1, f);
	
	printf("File creation time: %d\n", ff_fileCreationTime);
	
	if( !readInt(&ff_language) )
		return false;
	
	printf("Language: %d\n", ff_language);
	
	if( !readInt(&ff_padding) )
		return false;
	
	printf("Padding: %d\n", ff_padding);
	
	if( ff_padding > 0 ) {
		fseek(f, ff_padding * 0xC, SEEK_CUR);
	}
	
	if( !readInt(&ff_unusedSize) )
		return false;
	
	printf("Unused size: %d\n", ff_unusedSize);
	
	if( !readInt(&ff_usedSize) )
		return false;
	
	printf("Used size: %d\n", ff_usedSize);
	
	
	return true;
}

bool Decompiller::readInt(int* var) {
	return fread(var, sizeof(int), 1, f) == 1;
}

bool Decompiller::readBool(bool* var) {
	return fread(var, sizeof(bool), 1, f) == 1;
}

bool Decompiller::readBytes(char* var, unsigned int length) {
	return fread(var, 1, length, f) == length;
}