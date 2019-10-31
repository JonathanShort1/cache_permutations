#include <iostream>
#include <random>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void initialise_arr(uint32_t *arr, uint32_t n) {
    for (uint32_t i = 0; i < n; ++i) {
        arr[i] = i;
    }
}

void generate(uint32_t *arr, uint32_t n) {
    /* Seed */
    std::random_device rd;
    /* Random number generator */
    std::default_random_engine generator(rd());
    /* Distribution on which to apply the generator */
    std::uniform_int_distribution<uint64_t> distribution(0, n);

    uint32_t tmp;
    uint64_t r;
    for (uint32_t i = n - 1; i > 0; i--) {
        r = distribution(generator) % (i + 1);
        tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
    }
}

void write_out(const char *out_file, uint32_t *arr, uint32_t n) {
    FILE *fp;
    fp = fopen(out_file, "ab");
    fwrite(arr, sizeof(int), n, fp);
    fclose(fp);
}

int main(int argc, char *argv[])
{
    int n;
    if (argc == 3) {
        n = atoi(argv[1]);
        uint32_t *arr = (uint32_t *) calloc(n, sizeof(uint32_t));
        initialise_arr(arr, n);
        generate(arr, n);
        write_out(argv[2], arr, n);
        free(arr);
    }
    return 0;
}