#include <bits/types/FILE.h>
#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include "files.hpp"

/// Reads file to char*
/// Can return null
char *readToCString(char *path) {
    FILE *fptr = fopen(path, "r");

    if (fptr == NULL) {
	return nullptr;
    }

    size_t file_size = get_file_size(path);

    char *contents = (char*)malloc(file_size+1);
    fread(contents, 1, file_size, fptr);
    fclose(fptr);

    contents[file_size] = '\0';

    return contents;
}


size_t get_file_size(char *path) {
    FILE *fptr = fopen(path, "rb");
    if (fptr == NULL) {
	return -1;
    }

    fseek(fptr, 0, SEEK_END);
    size_t fileSize = ftell(fptr);
    fclose(fptr);
    return fileSize;
}
