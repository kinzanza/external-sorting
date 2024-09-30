#include "sort.h"


int main() {
        sort sorter(false);
        try
        {
        sorter.sorted("data.txt", "output.txt", 5);
        return 0;
        }
        catch(std::runtime_error &e)
        {
            std::cout << e << std::endl;
            return 1;
        }
    }