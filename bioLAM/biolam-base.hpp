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
    AnnotationIndexer(std::string annotation_file, int ref, int pos);
    ~AnnotationIndexer() {};
    
    
    
private:
    std::string annotation_file_;
    int pos_;
    int ref_;
    
};

#endif /* biolam_base_hpp */
