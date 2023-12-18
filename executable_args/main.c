// Copyright 2023 <Nitro Sniper>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
void search_path(char *path) {
  pid_t process_id = fork();
  if (!process_id) {
    if (execlp("find", "find", path, "-type", "f", "-executable", NULL) < 0) { 
        // this command is used to find file executables within the directory recursively using the child process
      perror("find command failed. Please check if find is installed "
             "on your system");
    }
  } else {
    int status;
    if (waitpid(process_id, &status, 0) < 0) {
      perror("Child Won't Finish");
    }
  }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        search_path("."); // just search current directory if no args are passed
    } else {
        for (int i = 1; i < argc; i++) {
            char *sv_pointer;
            char *token;
            char delimiter = ':';
            for (token = strtok_r(argv[i], &delimiter, &sv_pointer); token != NULL;
                    token = strtok_r(NULL, &delimiter, &sv_pointer)) {
                search_path(token);
            }
        } 
    }
    return EXIT_SUCCESS;
}
