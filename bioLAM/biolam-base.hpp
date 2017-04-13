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
    
    AnnotationIndexer() : reference_column_(-1), start_column_(-1), end_column_(-1), verbose_(true) {}
    AnnotationIndexer(std::string annotation_file, int reference_column, int start_column, int end_column, bool verbose = false);
    ~AnnotationIndexer() {};
    
    struct StartEndPositions {
        int64_t start_position;
        int64_t end_position;
    };
    
    
private:
    AnnotationError CreateIndex();
    std::string annotation_file_;
    int start_column_;
    int end_column_;
    int reference_column_;
    
    bool verbose_;
    
};

#endif /* biolam_base_hpp */
