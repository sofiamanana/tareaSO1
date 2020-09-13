
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    const int layer1 = 5;
    const int layer2 = 10;
    const int outfiles = 100;

    char buffer[100];
    for (int i = 0; i < layer1; ++i)
    {
        sprintf(buffer, "mkdir folder%d", i);
        system(buffer);
    }
    int i = 0;
    sprintf(buffer, "mv README folder%d",i);
    system(buffer);
    printf("holaaaaa");
    sprintf(buffer, "cd /home/ubuntu/Desktop/SO/tareaSO/folder0 && mv README ..");
    system(buffer);
    return EXIT_SUCCESS;
}
