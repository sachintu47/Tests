#include <stdio.h>
#include <stdlib.h>

#define FILE_SIZE 5L * 1024 * 1024 * 1024 // 3 GB
#define CHUNK_SIZE 1024 * 1024           // 1 MB

int main() {
    FILE *fp = fopen("3GB_file.bin", "wb"); // Open a binary file for writing
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Allocate a chunk of 1 MB
    char *buffer = (char *)malloc(CHUNK_SIZE);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        fclose(fp);
        return 1;
    }

    // Fill the buffer with some data (e.g., zeros)
    for (size_t i = 0; i < CHUNK_SIZE; i++) {
        buffer[i] = 0;
    }

    // Write the data in chunks until the file reaches 3 GB
    long long bytes_written = 0;
    while (bytes_written < FILE_SIZE) {
        size_t written = fwrite(buffer, 1, CHUNK_SIZE, fp);
        if (written != CHUNK_SIZE) {
            perror("Error writing to file");
            free(buffer);
            fclose(fp);
            return 1;
        }
        bytes_written += written;
    }

    printf("3 GB file created successfully: 3GB_file.bin\n");

    // Cleanup
    free(buffer);
    fclose(fp);

    return 0;
}

