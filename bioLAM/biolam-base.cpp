//
//  biolam-base.cpp
//  bioLAM
//
//  Created by Jonny on 3/10/17.
//  Copyright © 2017 Mazumder Lab. All rights reserved.
//


#include <fstream>
#include <sstream>
#include <map>

#include "biolam-base.hpp"

AnnotationIndexer::AnnotationIndexer(std::string annotation_file, int ref, int pos, bool verbose) : annotation_file_(annotation_file), ref_(ref), pos_(pos), verbose_(verbose) {

    if (verbose) {
        std::cout << "Called AnnotationIndexer" << std::endl;
        std::cout << "First level of annotation beginning." << std::endl;
    }
    
    std::cout << " In AnnotationIndexer " << std::endl;
    
    //
    // Need to first determine a list of references
    //
    std::string header;
    std::ifstream _annotation;
    _annotation.open(annotation_file_);
    std::map <std::string, int64_t> _reference_ids;
    
    // Assume header, remove and save
    std::getline(_annotation, header);
    if (!header.size()) {
        std::cerr << "ERROR: No file size for " << annotation_file_ <<". Aborting." << std::endl;
        return;
    }
    std::string row;

    char splitter = ',';
    // Can make it TSV here
    
    // The following while loop retrieves a list of all of the references
    // and puts them in _reference_ids
    auto line_beginning = _annotation.tellg();
    while ( std::getline(_annotation, row) ) {
        std::stringstream _rowElements(row);
        std::string _element;
        auto i = 0;
        while ( std::getline(_rowElements, _element, splitter) ) {
            if ( i == ref ) {
                //std::map <std::string, bool>::iterator it;
                auto it = _reference_ids.find(_element);
                if ( it == _reference_ids.end() ) {
                    // New element for this file
                    std::cout << "New element: " << _element << " at position: " << line_beginning << std::endl;
                    
                    
                    //StartEndPositions _s;
                    //_s.start_position = line_beginning;
                    
                    
                    _reference_ids[_element] = line_beginning;
                    //TODO: Need to somehow get the end position in the file when a new reference is found
                }
                // If already updated referenceIDs for this _element, ignore and move to next row
                // Break out of loop and move to next row
                break;
            }
            i++;
        }
        line_beginning = _annotation.tellg();
    }
    //std::map< foo, bar > testing = { /*...blah...*/ };
    
    // Index annotation file here
    std::cout << "Index annotation file here." << std::endl;
    std::ifstream is(annotation_file_);
    //std::string ref_target;
    for (auto& reference : _reference_ids) {
        //ref_target = reference.first;
        //std::cout << kv.first << " has value " << kv.second << std::endl;
        
        // Create output file name here
        std::string _op = "./__" + reference.first + "__.dat";
        std::ofstream op(_op);
        std::cout << "Created output file: " << _op << std::endl;
        
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
        
        
    }
    // Assume we're interested in chr 1 for debug
    // Iterate through MAP here
    //std::string ref_target = "chr1";
    
    
    
//    while (std::getline(is, line)) {
//        std::cout << "Line" << std::endl;
//        std::stringstream rows(line);
//        std::string column;
//        auto i = 0;
//        
//        int64_t _pos = 0;
//        bool found_chr = false;
//        bool found_pos = false;
//        
//        while (getline(rows,column, ',')) {
//            if (i == ref) {
//                // This is the correct column for chromosome
//                if (column == ref_target) {
//                    // This is the correct chromosome
//                    found_chr = true;
//                }
//                // This is the chromosome column
//            } else if (i == pos) {
//                // This is the position column
//                _pos = stoi(column);
//                found_pos = true;
//            }
//            i++;
//        }
//        if (found_pos && found_chr) {
//            // Write information
//            op << _pos << ',' << position << '\n';
//            std::cout << "pos: " << _pos << "\t" << "pos: " << position << std::endl;
//        }
//        position = is.tellg();
//    }
    //is.seekg(0, is.beg);
    is.clear();
    is.seekg(25, std::ios::beg);
    std::string l;
    getline(is, l);
    std::cout << "line fetch: " << l << std::endl;
    
    is.close();
    //op.close();
}
