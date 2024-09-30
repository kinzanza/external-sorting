#include v<iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "parser.h"
 int parser :: count_chars_in_file(const std::string& filename) {
    std::ifstream file(filename, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error ("Open Error!" + filenames);        return 0;
    }
    int size = 0;
    char c;
    while (file.get(c)) {
        ++size;
    }
    file.close();
    return size;
}
void parser :: writeVectorToFile(const std::vector<int>& vec, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error ("Open Error!" + filenames);      
          return;
    }
    for (const auto& element : vec) {
        file << element << "\n";
    }
    file.close();
}
std::vector<int> parser :: parse(int max, std::string filename) {
    std::ifstream inFile(filename);
    std::vector<int> chunk;
    if (!inFile.is_open()) {
         throw std::runtime_error ("Open Error!" + filenames);
        return chunk;
    }
    for(int x = 0; x < max && inFile >> chunk.back(); ++x) {
        if (inFile.fail()) {
            break;
        }
    }
    inFile.close();
    return chunk;
}
