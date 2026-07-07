#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>
#include <fcntl.h>
#include <errno.h>


#define ARRAY_SIZE 30

    void *ptr;
    if (posix_memalign(&ptr, pagesize, ARRAY_SIZE * sizeof(double)) != 0) {
        perror("Alignment failed");
        return NULL;
    return ptr;
}

void initialize_array(double *arr) {
    double init_vals[ARRAY_SIZE] = {
        12.5, 23.7, 45.2, 67.8, 89.1,
        34.6, 56.3, 78.9, 91.2, 15.4,
        27.9, 48.5, 73.1, 84.6, 95.3,
        19.2, 38.7, 62.4, 77.5, 88.0,
        42.1, 53.8, 69.3, 81.7, 94.2,
        5.9, 31.6, 59.4, 71.8, 86.5
    };

for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = init_vals[i];
    }
}

void print_memory_info(double *arr, size_t pagesize) {
    printf("\nthe array holds values ranging from 0.0-100.0\n");
    printf("Size of double: %zu bytes (%zu bits)\n", sizeof(double), sizeof(double) * 8);
    printf("Size of array: %zu bytes\n", ARRAY_SIZE * sizeof(double));
    printf("Virtual base Address: %p\n", (void *)arr);
    printf("Page Size: %ld bytes\n", pagesize);
}

uint64_t get_page_info(uint64_t vaddr, size_t pagesize) {
    uint64_t page_info;
    uint64_t pgnum = (vaddr / pagesize) * sizeof(uint64_t);

    FILE *pagemap = fopen("/proc/self/pagemap", "rb");
    if (!pagemap) {
        perror("Run with sudo! Could not open pagemap");
        return 0;
    }
    
    fseek(pagemap, pgnum, SEEK_SET);
    fread(&page_info, sizeof(uint64_t), 1, pagemap);
    fclose(pagemap);

    return page_info;
}



