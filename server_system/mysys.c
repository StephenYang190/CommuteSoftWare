//
// Created by yang on 2021/4/24.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


void mysys(char *command)
{
    pid_t pid;
    pid = fork();

    if(pid == 0)
    {
        int lenstr = strlen(command);
        int star = 0;
        char  * argv[50];
        int k = 0;

        for(int i = 0; i <= lenstr; i++)
        {
            if(i == lenstr || command[i] == ' ')
            {
                char * newchar = (char *) malloc(sizeof (char) * 256);
                strncpy(*newchar, command + star, i - star);
                argv[k] = newchar;
                k++;
                if(i == lenstr) break;
                while(i < lenstr && command[i] == ' ') i++;
                star = i;
            }
            else
            {
                continue;
            }
        }

        argv[k] = NULL;
        int error = execv(*argv[0], argv);
    }
}

int main()
{
    printf("--------------------------------------------------\n");
    mysys("echo HELLO WORLD");
    printf("--------------------------------------------------\n");
    mysys("ls /");
    printf("--------------------------------------------------\n");
    return 0;
}

//int main()
//{
//    char * command = "echo hollow world";
//
//    int lenstr = strlen(command);
//    int star = 0;
//    char  * argv[50];
//    int k = 0;
//
//    for(int i = 0; i <= lenstr; i++)
//    {
//        if(i == lenstr || command[i] == ' ')
//        {
//            char * newchar = (char *) malloc(sizeof (char) * (i - star));
//            strncpy(newchar, command + star, i - star);
//            argv[k] = newchar;
//            k++;
//            if(i == lenstr) break;
//            while(i < lenstr && command[i] == ' ') i++;
//            star = i;
//        }
//        else
//        {
//            continue;
//        }
//    }
//
//    argv[k] = NULL;
//
//    return 0;
//}