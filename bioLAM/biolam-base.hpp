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
    
    AnnotationIndexer() {}
    AnnotationIndexer(std::string annotation_file, int ref, int pos, bool verbose = false);
    ~AnnotationIndexer() {};
    
    struct StartEndPositions {
        int64_t start_position;
        int64_t end_position;
    };
    
    
    
private:
    std::string annotation_file_;
    int pos_;
    int ref_;
    
    bool verbose_;
    
};

#endif /* biolam_base_hpp */
