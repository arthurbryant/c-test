#include <string.h> 
int main(int argc, char *argv[]) 
{ 
    char *ptr; ptr = (char*) malloc(10); 
    strcpy(ptr, "123456789"); 
    return 0; 
}
