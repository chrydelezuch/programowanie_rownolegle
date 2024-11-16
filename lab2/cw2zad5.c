   #include <stdio.h>
   #include <stdlib.h>
   #include <sys/types.h>
   #include <unistd.h>
   #include <sys/wait.h>

int main() {
 
   
   int pid[4];
   for(int i=0; i<4; i++)
   {
        int pidd=fork();
        if(pidd==0){
            exit(0);
        }else if(pidd>0){
            pid[i]=pidd;
        }else{
           perror(NULL); 
           return 1;
        } 
   }
   sleep(30);
   waitpid(pid[0], NULL, 0);
   waitpid(pid[1], NULL, 0);
   waitpid(pid[2], NULL, 0);
   waitpid(pid[3], NULL, 0);


  
  return 0;
} 