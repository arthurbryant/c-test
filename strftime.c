#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv[])
{
    time_t t1;
    if((t1 = time(NULL)) == -1)
    {
  	perror("time error");      
	exit(-1);
    }
    printf("%d\n", t1);
    const struct tm *t2;
    t2 = gmtime(&t1);
    char buf[BUFSIZ];
#define TZ EST5EDT
    if(strftime(buf, BUFSIZ, "%c", t2) == 0)
    {
	
	printf("strftime error");
	exit(-1);
    }
    printf("%s\n", buf);
#undef TZ
#define TZ UTC 
    if(strftime(buf, BUFSIZ, "%c", t2) == 0)
    {
	
	printf("strftime error");
	exit(-1);
    }
    printf("%s\n", buf);
    return 0;
}
