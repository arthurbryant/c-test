#include <stdio.h>
#include <stdlib.h>

void pr_buffer(char * name, FILE* fp)
{
    printf("name = %s", name);
    if(fp->_IO_file_flags & _IO_UNBUFFERED)
    {
        printf(", unbuffered.");
    }
    else if(fp->_IO_file_flags & _IO_LINE_BUF)
    {
        printf(", line buffered.");
    }
    else
    {
        printf(", fully buffered");
    }
    printf(", buf size = %d\n", fp->_IO_buf_end - fp->_IO_buf_base); 
}
int main()
{
    fputs("I like this game", stdout);
    if(getchar() == EOF)
    {
        perror("getchar error");
        exit(-1);
    }
    fputs("one input line error\n", stderr);
    pr_buffer("stdin", stdin);
    pr_buffer("stdout", stdout);
    pr_buffer("stderr", stderr);
    

    return 0;
}
