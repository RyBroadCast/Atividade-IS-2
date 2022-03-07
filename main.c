#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
   int pipefds[2];
   int returnpipe;
   int pid_t;
   char writemessages[2][20]={"Mensagem 1", "Mensagem 2"};
   char readmessage[20];
   
   returnpipe = pipe(pipefds);

   if (returnpipe == -1) {
      printf("Error creating pipe!\n");
      return 1;
   }
   pid_t = fork();

   //processo filho
   if (pid_t == 0) {
      read(pipefds[0], readmessage, sizeof(readmessage));
      printf("Processo filho – Message 1 is %s\n", readmessage);
      read(pipefds[0], readmessage, sizeof(readmessage));
      printf("Processo filho – Message 2 is %s\n", readmessage);
   }
   //processo pai
   else {
      printf("Processo pai - Message 1 is %s\n", writemessages[0]);
      write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
      printf("Processo pai - Message 2 is %s\n", writemessages[1]);
      write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
   }

   return 0;
}
