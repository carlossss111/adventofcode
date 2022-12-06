#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

#define exit_err(str, code) fprintf(stderr, str); exit(code)

extern void read_file_into_memory(char** buffer, const char* file_path);