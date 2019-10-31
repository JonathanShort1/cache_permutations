#include <fstream>
#include <vector>
#include <istream>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

uint32_t read_file(uint32_t **arr, const char *filename)
{
    ifstream file(filename, ios::binary);
    // Stop eating new lines in binary mode!!!
    file.unsetf(ios::skipws);
    file.seekg(0, ios::end);
    uint32_t fileSize = file.tellg();
    file.seekg(0, ios::beg);

    uint32_t length = fileSize / sizeof(uint32_t);
    uint32_t *buf = (uint32_t *) malloc(fileSize);

    uint32_t a;
    uint32_t i = 0;
    while (i < length) {
        file.read(reinterpret_cast<char *>(&a), sizeof(uint32_t));
        buf[i] = a;
        ++i;
    }

    *arr = buf;

    file.close();
    return length;
}

void write_out(const char *out_file, uint32_t *arr, uint32_t n) {
    FILE *fp;
    fp = fopen(out_file, "wb");
    fwrite(arr, sizeof(int), n, fp);
    fclose(fp);
}

int main(int argc, char* argv[])
{
    if (argc != 3) return -1;

    uint32_t *x = NULL, *y = NULL;

    uint32_t length, check;

    length = read_file(&x, argv[1]);
    check = read_file(&y, argv[2]);

    if (length != check) {
        cout << "Files not same size";
        return -1;
    }

    cout << length << endl;

    uint32_t *z = (uint32_t *) calloc(length, sizeof(uint32_t));

    for (uint32_t i = 0; i < length; ++i) {
        z[i] = y[x[i]];
    }

    write_out("out.bin", z, length);
    
    return 0;
}