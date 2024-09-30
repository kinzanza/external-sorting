
#ifndef SORT_1_SORT_H
#define SORT_1_SORT_H
#include <vector>
#include <iostream>

class sort final {
    const std::string file = "file";
    void merge_sorted_files(const std::vector<std::string>& filenames, const std::string& output_filename);
    static int count_chars_in_file(const std::string& filename);
    public:
    void sorted(const std::string& input, const std::string& output, int max);
};


#endif 
