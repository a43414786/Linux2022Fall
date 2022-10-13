#include "../include/strcpy.h"

char *sstrcpy(char *dest,const char *src){
	for(int i = 0 ; i < 10 ; i++){
		dest[i] = src[i];
	}
	return dest;
}
