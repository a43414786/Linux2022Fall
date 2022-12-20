#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include "../include/strcpy.h"

int main(){
    const char *src = "f84086171";
    char *dest = malloc(10);
	dest = sstrcpy(dest,src);
	printf("%s\n",dest);
	return 0;
=======
/* #include "../include/strcpy.h" */
int mian(){
    const char *src = "f84086171";
	/* char *dest = malloc(10); */
    /* dest = sstrcpy(dest,src); */
    printf("%s\n",src);
    return 0;
>>>>>>> 800953b6afe6d34787c3ce385739db3c4e22df5b
}
