#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

struct timeval starting_time, ending_time;

int main() {
char str[100];
char *delim;
char buf[100];

    printf("time <command> ");
	fgets(str, 100, stdin);
    str[strlen(str)-1]='\0';
   
   char *ar[] = { "/bin/", NULL };
   strcat(strcpy(buf, ar[0]), str);
    char *args[] = {buf, NULL };
    
    printf("%s\n", buf);

    int status;
    pid_t pid; 

    pid =fork(); 
    
    if (pid==-1){ 
    printf("Error al crear el p Hijo");
    exit(0); 
    }
    if (pid) { //Proceso padre 
       // printf("Soy P, PID Hijo %d\n", pid);
       gettimeofday(&starting_time, NULL);
        gettimeofday(&ending_time, NULL);
        int timeH = ((ending_time.tv_sec * 1000000 + ending_time.tv_usec)-(starting_time.tv_sec *  1000000 + starting_time.tv_usec));
        printf("tiempo : %d micro seconds\n", timeH);
        } else { //Proceso hijo
            wait(NULL); 
            printf("Voy a ejecutar pero ");
            status=execv(args[0], args);
            if(status<0){
            printf("Error! %s no se reconoce o no se pudo ejecutar", str);
            exit(0); 
        gettimeofday(&starting_time, NULL);
        gettimeofday(&ending_time, NULL);
        int timeH = ((ending_time.tv_sec * 1000000 + ending_time.tv_usec)-(starting_time.tv_sec * 1000000 + starting_time.tv_usec));
        printf("Tiempo : %d micro seconds\n", timeH);


        }

    }
}
