#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;
    const char *filePath = argv[1];

    // Call stat on the given file path
    if (stat(filePath, &fileStat) == -1) {
        perror("stat");
        return 1;
    }

    // Print st_mode in octal and hexadecimal
    printf("File: %s\n", filePath);
    printf("st_mode (octal): %o\n", fileStat.st_mode);
    printf("st_mode (hex): 0x%x\n", fileStat.st_mode);

    return 0;
}

