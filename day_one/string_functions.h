#pragma once

#include <stdio.h>
#include <stdlib.h>

#define exit_err(str, code) fprintf(stderr, str); exit(code)

extern void read_file_into_memory(char** buffer, const char* file_path);
extern long sum_of_delimited_sequence(char* sequence, const char delimiter);
extern void go_to_next_sequence(char** str_p, const char delimiter);