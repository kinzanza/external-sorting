
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "sort.h"
#include "parser.h"

void sort :: sorted(std::string input, std::string output, int max) {
    parser p;
    int sim = count_chars_in_file(input);
    std::vector<std::string> naming;
    std::vector<int> chunk;
    for(int i = 0; i <= sim/max; i++) {
        std::string file_name = file + std::to_string(i+1);
        naming.push_back(file_name);
        chunk.clear();        chunk = p.parse(max, input);
        std::sort(chunk.begin(), chunk.end());
        p.writeVectorToFile(chunk, file_name);
    }
    merge_sorted_files(naming, output);
}
void sort :: merge_sorted_files(const std::vector<std::string>& filenames, const std::string& output_filename, bool r) {
    std::ofstream outputFile(output_filename);
    if (!outputFile.is_open()) 
    {
            throw std::runtime_error ("Open Error!" + filenames);
    }
    std::vector<int> temp;
    for (const auto& filename : filenames) {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
           if (!outputFile.is_open()) {
            throw std::runtime_error ("Open Error!" + filenames);
    }
        }
        int value;
        while (inputFile >> value) {
            temp.push_back(value);
        }
        inputFile.close();
    }
    if(r){
    std::sort(temp.begin(), temp.end());
    for (const auto& num : temp) {
        outputFile << num << "\n";
    }
    }
    else {std::sort(temp.begin(), temp.end(), std::greater<>());
    for (const auto& num : temp) {
        outputFile << num << "\n";
    }
    }
    outputFile.close();
}