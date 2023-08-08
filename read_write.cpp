//
// Created by paul on 3/2/23.
//

#include "read_write.h"


std::string read_from() {
    std::fstream this_stream;
    this_stream.open("complete_genome.txt", std::ios::in);

    if(this_stream.is_open()) {
        std::string outstring;
        std::string readstring;
        while (this_stream.good()) {
            this_stream >> outstring;
            readstring= readstring + outstring;
        }
        this_stream.close();
        return readstring;
    }
}