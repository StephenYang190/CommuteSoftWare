//
// Created by Tongda Yang
//
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
    int sccss = open(argv[0], O_RDONLY);
    if(sccss == -1)
    {
        printf("Don;t have this file.\n");
        return -1;
    }

    mode_t mode = 0777;
    int wrsccss = open(argv[1], O_TRUNC|O_CREAT|O_APPEND, mode);

    int i = 0;
    int offset = i * sizeof(char);
    while(1)
    {
        char buf;
        int rdsccss = read(sccss, &buf, sizeof(char));
        if(rdsccss != sizeof(char))
        {
            break;
        }
        if(rdsccss == '\r')
        {
            continue;
        }
        write(wrsccss, buf, sizeof(char));

    }

    return 0;
}