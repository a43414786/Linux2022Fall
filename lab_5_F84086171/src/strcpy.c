#include "../include/strcpy.h"


char *sstrcpy(char *dest,const char *src){
<<<<<<< HEAD
	int count = 0;
	while(src[count] != '\0'){
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
=======
	dest = *src;
>>>>>>> 800953b6afe6d34787c3ce385739db3c4e22df5b
	return dest;
}
