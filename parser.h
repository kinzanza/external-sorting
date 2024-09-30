#ifndef SORT_1_PARSER_H
#define SORT_1_PARSER_H
#include "parser.h"

class parser final{
    public:
    std::vector<int> parse(int max, std::string filename);
    void writeVectorToFile(const std::vector<int>& vec, const std::string& filename);
    static int count_chars_in_file(const std::string& filename);

};


#endif 
