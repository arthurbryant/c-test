#include <stdio.h>
#include <time.h>

void setbuf1(FILE * __restrict fp, char * __restrict buf)
{
    if(buf == NULL)
        setvbuf(fp, buf, _IONBF, 0);
    else
        setvbuf(fp, buf, _IOFBF, BUFSIZ);
}

int main(int argc, char * argv[])
{
    char str[] = "11111";
    char buf[BUFSIZ];
    char *p = str;
    FILE *fp;
    fp = fopen("data", "a+");
    //setbuf(fp, NULL);
    setbuf(fp, buf);
    char c;
    while((c = *p++) != '\0')
    {
        printf("%c\n", c);
        if(fputc(c, fp) == EOF)
            perror("fputc error");
        sleep(1);
    }

    return 0;
}
