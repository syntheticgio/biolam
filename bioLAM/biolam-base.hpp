//
//  biolam-base.hpp
//  bioLAM
//
//  Created by Jonny on 3/10/17.
//  Copyright © 2017 Mazumder Lab. All rights reserved.
//

#ifndef biolam_base_hpp
#define biolam_base_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

class AnnotationIndexer {

public:

	enum AnnotationError {
		kNoError = 0,
		kOpenFile = 1

	};
    
    AnnotationIndexer() : ref_(-1), pos_(-1), verbose_(true) {}
    AnnotationIndexer(std::string annotation_file, int ref, int pos, bool verbose = false);
    AnnotationIndexer(std::string annotation_file, bool verbos = false);
    ~AnnotationIndexer() {};
    
    struct StartEndPositions {
        int64_t start_position;
        int64_t end_position;
    };
    
    
private:
    AnnotationError CreateIndex(std::string annotation_file, int ref, int pos, bool verbose = false);
    std::string annotation_file_;
    int pos_;
    int ref_;
    
    bool verbose_;
    
};

#endif /* biolam_base_hpp */
