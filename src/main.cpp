#include <cstdlib>

#include "decompiller.h"

int main(int argc, char** args) {
	
	Decompiller dec("ui_mp.ff");
	
	if( dec.read() ) 
		printf("Read ok");
	else
		printf("Read fail!");
	
	
	return 1;
}