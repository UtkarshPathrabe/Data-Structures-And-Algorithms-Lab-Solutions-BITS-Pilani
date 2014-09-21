//ListOps.h

#include <stdio.h>
#include "List.h"

extern List sort(List list, long long int size);
extern void print(List list, long long int size, FILE *fp);
extern List doPartition(List list, Link p, Link q);
