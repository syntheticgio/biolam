#include "biolam-base.hpp"

//int argc, char ** argv

int main () {

	std::string annotation_file = "";
	int ref = 1;
	int start = 2;
	int end = 3;
    AnnotationIndexer g(annotation_file, ref, start, end, true);

    return 0;

}
