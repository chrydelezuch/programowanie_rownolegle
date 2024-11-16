   #include <stdio.h>
   #include <fcntl.h>
   #include <unistd.h>
   #include <string.h>
   #include <stdlib.h>


int main(int argc, char* argv[]) {

    int charNumber = atoi(argv[2]);
    
    if(argc==3 && (charNumber>0 || !strcmp(argv[2], "0"))){
        int file1 = open(argv[1], O_RDWR);
        char * file2name =(char *) malloc(sizeof(argv[1])+1);
        memcpy(file2name, argv[1], sizeof(argv[1])-4);
        memcpy(file2name+sizeof(argv[1])-4, "3.txt", 5);

        int file2 = open(file2name, O_RDWR|O_CREAT, 0664);

        free(file2name);
        
        if(file1!=-1 && file2!=-1){
            
            char * buff = (char *) malloc(charNumber);

            if(read(file1, buff, charNumber)!=-1 && write(file2, buff, charNumber)!=-1 &&
               read(file1, buff, charNumber)!=-1 && write(file2, buff, charNumber)!=-1 &&
               read(file1, buff, charNumber)!=-1 && write(file2, buff, charNumber)!=-1){
                printf("operacja zakonczona sukcesem");
            }
            else{
                perror(NULL);
            } 

            free(buff);
        }
        else perror(NULL);

        close(file1);
        close(file2);
    }
    else printf("Program uruchomiony z nieprawidlowymi parametrami. Poadaj dwa parametry: pliku wjsciowegi oraz liczbe bajtow do przekopiowania");
  
  return 0;
} 
