// system includes
#include <iostream>	// for ostream
#include <iomanip> 	// for setw

// local includes
#include "../../TARGET.hpp"

//#include "../../DEP.hpp"
// DEPENDENCIES:

namespace test {

	static const int GOOD	= 1;
	static const int BAD	= 0;
	int RESULT = GOOD;

	void report( std::string s, int result ){
		if(result){
			std::cout << "	" << std::setw(50) << std::left << s << " PASSED!" << std::endl; 
		}
		else{
			RESULT = BAD;
			std::cout << "	" << std::setw(50) << std::left << s << " FAILED!" << std::endl; 
		}
	}

	void test_initialization(){

	}
	
}

int main( int argc, char* argv[] ){
	// title line
	std::cout << "running all TARGETCAP tests:" << std::endl;
	
	// begin tests
	// -----------------------------------------------------------------
	
	test::test_initialization();

	// -----------------------------------------------------------------
	// end tests
	std::cout << "TARGETCAP tests complete!" << std::endl;
	
	
	// conclusion
	test::report("ALL",test::RESULT);
	return test::RESULT;
}



