// **Configuration**
#define ROUNDS 100
#define D_GETTIME 1
// **Configuration**
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

double GETTIME();

int main(int argc, char** argv)
{
    double measure_gettime = 0;
    uint64_t fib[50] = {0};
#if D_GETTIME
    double t1 = GETTIME();
#endif
    for (int r = 0; r < ROUNDS; r++) {
        fib[0] = 1;
        fib[1] = 1;
        for(int i = 2 ; i < 50 ; i++){
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
#if D_GETTIME
    double time_s = GETTIME()-t1;
    measure_gettime += time_s;
#endif    
    for(int i = 0; i < 50; i++) {
        printf("%lu ", fib[i]);
    }
    printf("\n");
    printf(" %.9lf | ", (double)measure_gettime/ROUNDS);
    printf("\n");
    return 0;
}
double GETTIME() {
    struct timespec ts;
    double sec;
    clock_gettime(CLOCK_REALTIME,&ts);
    sec = ts.tv_nsec;
    sec /= 1e9;
    sec += ts.tv_sec;
    return sec;
}

