#include "general_functions.h"
#include <string.h>

void read_file_into_memory(char** buffer, const char* file_path) {
    FILE* fp;
    if (!(fp = fopen(file_path,"r"))) {
       exit_err("Error opening input file...\n", 1);
    }

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (!(*buffer = (char*) malloc(fsize + 1))) {
        exit_err("Out of memory, input file to large...\n", 1);
    }
    fread(*buffer, fsize, 1, fp);
    fclose(fp);
}