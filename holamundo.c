#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
int main()
{   
    int i=1;
    DIR *dir;
    struct dirent *dp;
    const char *path="./Juegos"; 
    FILE *file;
    dir = opendir(path);
    while(dp=readdir(dir)){
        dp->d_name;
        print("%d",i);
        i++;
    }
    return 0;
}
