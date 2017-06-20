#include <stdio.h>
#include <stdlib.h>
#include "skob.h" 

int main()
{
    FILE *f = open_file("data.txt");
    if (f == NULL) 
    { 
        perror ("Error opening file"); 
        getchar(); 
        exit(1); 
    }
    
    if (check(f) == 1)
        printf("Scopes are balanced \n");
    else
        printf("Scopes are not balanced \n");

#ifdef _WIN32
    system("PAUSE");
#endif
}
