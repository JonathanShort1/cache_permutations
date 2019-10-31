#include <fstream>
#include <vector>
#include <istream>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;

    ifstream file(argv[1], ios::binary);

    // Stop eating new lines in binary mode!!!
    file.unsetf(ios::skipws);

    file.seekg(0, ios::end);
    uint32_t fileSize = file.tellg();
    file.seekg(0, ios::beg);

    uint32_t length = fileSize / sizeof(uint32_t);
    uint32_t *arr = (uint32_t *) malloc(fileSize);

    uint32_t a;
    uint32_t i = 0;
    while (i < length) {
        file.read(reinterpret_cast<char *>(&a), sizeof(uint32_t));
        arr[i] = a;
        ++i;
    }

    sort(arr, arr + length);

    uint32_t c = 0;
    for (uint32_t i = 0; i < length; ++i) {
        if (c != arr[i]) {
            cout << arr[i] << " " << c << " " << i << endl;
            cout << "Bad" << endl;
            break;
        }
        ++c;
    }

    free(arr);
    file.close();
    return 0;