#include "../include/strcpy.h"

char *sstrcpy(char *dest,const char *src){
	int count = 0;
	while(src[count] != '\0'){
		dest[count] = src[count];
		count++;
	}
	return dest;
}
