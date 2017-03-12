//
//  biolam-base.cpp
//  bioLAM
//
//  Created by Jonny on 3/10/17.
//  Copyright © 2017 Mazumder Lab. All rights reserved.
//


#include <fstream>
#include <sstream>

#include "biolam-base.hpp"

AnnotationIndexer::AnnotationIndexer(std::string annotation_file, int ref, int pos) : annotation_file_(annotation_file), ref_(ref), pos_(pos) {

    std::cout << "Made it into function" << std::endl;
    
    // Assume we're interested in chr 1 for debug
    std::string ref_target = "chr1";
    
    // Index annotation file here
    std::ifstream is(annotation_file_);
    std::ofstream op("/Users/Jonny/Desktop/test_out.txt");
    
    is.seekg(0, is.beg);
    std::string line;
    
    auto p1 = is.tellg();
    std::cout << "before header: " << p1 << std::endl;
    
    // Get header
    getline(is, line);
    auto p2 = is.tellg();
    std::cout << "after header: " << p2 << std::endl;
    
    std::cout << "l: " << line << std::endl;
    long long int position = is.tellg();
    std::cout << "POS: " << position << std::endl;
    
    while (std::getline(is, line)) {
        std::cout << "Line" << std::endl;
        std::stringstream rows(line);
        std::string column;
        auto i = 0;
        
        int64_t _pos = 0;
        bool found_chr = false;
        bool found_pos = false;
        
        while (getline(rows,column, ',')) {
            if (i == ref) {
                // This is the correct column for chromosome
                if (column == ref_target) {
                    // This is the correct chromosome
                    found_chr = true;
                }
                // This is the chromosome column
            } else if (i == pos) {
                // This is the position column
                _pos = stoi(column);
                found_pos = true;
            }
            i++;
        }
        if (found_pos && found_chr) {
            // Write information
            op << _pos << ',' << position << '\n';
            std::cout << "pos: " << _pos << "\t" << "pos: " << position << std::endl;
        }
        position = is.tellg();
    }
    //is.seekg(0, is.beg);
    is.clear();
    is.seekg(25, std::ios::beg);
    std::string l;
    getline(is, l);
    std::cout << "line fetch: " << l << std::endl;
    
    is.close();
    op.close();
}
