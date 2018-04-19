#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char seed[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int nums = 100;

int rndnum(const int minv, const int maxv) {
    return rand() % (maxv + 1 - minv) + minv;
}

int main(int argc, char* argv[]) {
    const int seedlen = strlen(seed);
    int i,j,v,age;
    time_t ts;
    struct tm *tt;

    if (argc == 2 && argv[1] && strlen(argv[1])) {
        const char* input_num = argv[1];
        long tmp_nums = atol(input_num);
        if (tmp_nums > 0) {
            nums = tmp_nums;
        } else {
            fprintf(stderr,"usage: ./testdata NUM_OF_LINE\n");
            return 1;
        }
    }

    srand(time(NULL));

    for(i=0;i<nums;i++) {
        // generate random hash value
        char str[33]="";
        for(j=0;j<32;j++) {
            v = rndnum(1,seedlen);
            char cc[2]={seed[v],'\0'};
            strcat(str,cc);
        }

        age = rndnum(20,99);

        // generate random addtime value
        ts = time(NULL);
        ts -= rndnum(0, 86400 * 365 * 2);
        tt = localtime(&ts);
        char dt[20]="";
        sprintf(dt, "%04d-%02d-%02d %02d:%02d:%02d", tt->tm_year+1900,tt->tm_mon+1,tt->tm_mday,tt->tm_hour,tt->tm_min,tt->tm_sec);

        // output data
        fprintf(stdout, "{\"idfa\":\"%s\",\"age\":%d,\"dt\":\"%s\"}\n", str,age,dt);
    }
    return 0;
}
