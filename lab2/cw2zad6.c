   #include <stdio.h>
   #include <unistd.h>
  
   

int main() {
  if(execl("/bin/ps", "ps", NULL)==-1)perror(NULL);
  
  return 0;
} 