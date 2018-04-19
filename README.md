# bigdata_testdata_generator
a very fast test data generator for bigdata

# build
gcc -Wall -o testdata testdata.c

# usage
./testdata NUM_OF_LINES > OUTPUT.json

for sample:

```
[root@instance-1 ~]# ./testdata 1000000 > data.json
[root@instance-1 ~]# ls -lha data.json
-rw-r--r--. 1 root root 76M Apr 19 08:53 data.json
```

# performance

100x faster than perl, or generating data from /dev/urandom
