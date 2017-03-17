// system includes
#include <iostream>	// for ostream
#include <iomanip> 	// for setw

// local includes
#include "../../markregister.hpp"

//#include "../../DEP.hpp"
// DEPENDENCIES:
#include "../../line.hpp"
#include "../../mark.hpp"
#include "../../message.hpp"

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
		try{
			afe::MarkRegister* tmp1 = new afe::MarkRegister();
			delete tmp1;
		}
		catch(...){
			report("test_initialization exception",BAD);
			return;
		}
		
		try{
			afe::MarkRegister tmp2();
		}
		catch(...){
			report("test_initialization exception",BAD);
			return;
		}
		
		afe::MarkRegister* tmp1 = new afe::MarkRegister();
		afe::MarkRegister tmp2;
		
		if(tmp1->registered() == 0 && tmp2.registered() == 0 ){
			report("test_initialization",GOOD);
		}
		else {
			report("test_initialization",BAD);
		}
		
		delete tmp1;
	}
	
	void test_includes(){
		afe::Line* l = new afe::Line();
		afe::MarkRegister* tmp1 = new afe::MarkRegister();
		afe::Mark* mark = new afe::Mark(l);
		
		tmp1->register_mark(mark);
		
		if(tmp1->includes(mark) && tmp1->registered() == 1){
			report("test_includes",GOOD);
		}
		else {
			report("test_includes",BAD);
		}
		
		delete l;
		delete mark;
		delete tmp1;
	}
	
	void test_register_mark(){
		afe::Line* l = new afe::Line();
		afe::Mark* mark = new afe::Mark(l);
		afe::Mark* mark2 = new afe::Mark(l);
		
		bool ISGOOD = true;
		
		afe::MarkRegister* tmp1 = new afe::MarkRegister();
		
		// -------------------------------------------------------------
		// Register one test
		tmp1->register_mark(mark);
		
		if( !( tmp1->includes(mark) ) || tmp1->registered() != 1)
			ISGOOD = false;

		// -------------------------------------------------------------
		// Register SAME test
		tmp1->register_mark(mark);
		
		if( tmp1->registered() != 1 )
			ISGOOD = false;

		// -------------------------------------------------------------
		// Register second test
		tmp1->register_mark(mark2);
		
		if( !( tmp1->includes(mark2) ) || tmp1->registered() != 2)
			ISGOOD = false;

		// -------------------------------------------------------------
		// Report
		if(ISGOOD)
			report("test_register_mark",GOOD);
		else
			report("test_register_mark",BAD);
		
		delete l;
		delete mark;
		delete mark2;
		delete tmp1;
	}
	
	void test_unregister_mark(){
		afe::Line* l = new afe::Line();
		afe::Mark* mark = new afe::Mark(l);
		afe::Mark* mark2 = new afe::Mark(l);
		
		bool ISGOOD = true;
		
		afe::MarkRegister* tmp1 = new afe::MarkRegister();
		
		// -------------------------------------------------------------
		// Unregister one test
		tmp1->register_mark(mark);
		tmp1->unregister_mark(mark);
		
		if( tmp1->includes(mark) || tmp1->registered() != 0)
			ISGOOD = false;

		// -------------------------------------------------------------
		// Unregister two test
		tmp1->register_mark(mark);
		tmp1->register_mark(mark2);
		
		tmp1->unregister_mark(mark);
		
		if( tmp1->includes(mark) || tmp1->registered() != 1)
			ISGOOD = false;

		tmp1->unregister_mark(mark2);

		if( tmp1->includes(mark2) || tmp1->registered() != 0)
			ISGOOD = false;
			
		// -------------------------------------------------------------
		// Report
		if(ISGOOD)
			report("test_unregister_mark",GOOD);
		else
			report("test_unregister_mark",BAD);
		
		delete l;
		delete mark;
		delete mark2;
	}
	
	void test_notify_marks(){
		std::string s = "TEST";
		afe::Line* l = new afe::Line(s);
		afe::Mark* mark1 = new afe::Mark(l,1);
		afe::Mark* mark2 = new afe::Mark(l,2);
		
		message::InsertCharacter* msg1 = new message::InsertCharacter(0,'X');
		
		bool ISGOOD = true;
		
		afe::MarkRegister* tmp1 = new afe::MarkRegister();
		
		tmp1->register_mark(mark1);
		tmp1->register_mark(mark2);
		
		tmp1->notify_marks(msg1);
		
		if( mark1->get_position() != 2 || mark2->get_position() != 3 )
			ISGOOD = false;

		// -------------------------------------------------------------
		// Report
		if(ISGOOD)
			report("test_notify_marks",GOOD);
		else
			report("test_notify_marks",BAD);
		
		delete msg1;
		delete l;
		delete mark1;
		delete mark2;
	}
	
}

int main( int argc, char* argv[] ){
	// title line
	std::cout << "running all MARKREGISTER tests:" << std::endl;
	
	// begin tests
	// -----------------------------------------------------------------
	
	test::test_initialization();
	test::test_includes();
	test::test_register_mark();
	test::test_unregister_mark();
	test::test_notify_marks();

	// -----------------------------------------------------------------
	// end tests
	std::cout << "MARKREGISTER tests complete!" << std::endl;
	
	
	// conclusion
	test::report("ALL",test::RESULT);
	return test::RESULT;
}



