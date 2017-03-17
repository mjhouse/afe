// system includes
#include <iostream>	// for ostream
#include <iomanip>

// local includes
#include "../../line.hpp"
#include "../../mark.hpp"

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

	int test_initialization(){
		std::string s = "TEST";
		afe::Line* tmp_l = new afe::Line(s);
		afe::Mark tmp_m(tmp_l,1);
		
		// -------------------------------------------------------------
		// Test init w/ (line,pos)
		if( tmp_m.get_position() == 1 && tmp_m.get_line() == tmp_l )
			report("test_initialization",GOOD);
		else
			report("test_initialization",BAD);

		// -------------------------------------------------------------
		// Test copy constructor with reference
		afe::Mark* tmp_m1 = new afe::Mark(tmp_m);
			
		if( tmp_m1->get_position() == 1 && tmp_m1->get_line() == tmp_l )
			report("test_initialization (copy const)",GOOD);
		else
			report("test_initialization (copy const)",BAD);
			
		// -------------------------------------------------------------
		// Test copy constructor with pointer
		afe::Mark tmp_m2(tmp_m1);
			
		if( tmp_m2.get_position() == 1 && tmp_m2.get_line() == tmp_l )
			report("test_initialization (copy ptr)",GOOD);
		else
			report("test_initialization (copy ptr)",BAD);
		
		delete tmp_l;
		delete tmp_m1;
	}
	
	int test_move_inside_line(){
		std::string s = "TEST";
		afe::Line* tmp_l = new afe::Line(s);
		afe::Mark tmp_m(tmp_l);
		
		// GOOD FLAG
		bool ISGOOD = true;

		// -------------------------------------------------------------
		// Test move right
		tmp_m.move(1);
		if( tmp_m.get_position() != 1 )
			ISGOOD = false;
			
		// -------------------------------------------------------------
		// Test move left
		tmp_m.move(-1);
		if( tmp_m.get_position() != 0 )
			ISGOOD = false;
		
		// -------------------------------------------------------------
		// Test bump left boundary
		tmp_m.move(-1);
		if( tmp_m.get_position() != 0 )
			ISGOOD = false;
		
		// -------------------------------------------------------------
		// Test bump right boundary
		tmp_m.move(4);
		if( tmp_m.get_position() != 3 )
			ISGOOD = false;

		if(ISGOOD)
			report("test_move_inside_line",GOOD);
		else
			report("test_move_inside_line",BAD);

		delete tmp_l;
	}
	
	int test_move_outside_line(){
		std::string left = "ABCDE";
		std::string right = "FGHIJ";
		
		afe::Line* tmp_l = new afe::Line(left);
		afe::Line* tmp_r = new afe::Line(right);
		tmp_l->next = tmp_r;
		tmp_r->prev = tmp_l;
		
		afe::Mark tmp_m(tmp_l);
		
		// GOOD FLAG
		bool ISGOOD = true;

		// -------------------------------------------------------------
		// Test move to end
		tmp_m.move(4);
		if( tmp_m.get_position() != 4 && tmp_m.get_line() != tmp_l )
			ISGOOD = false;
			
		// -------------------------------------------------------------
		// Test move across boundary to right
		tmp_m.move(1);
		
		if( tmp_m.get_position() != 0 && tmp_m.get_line() != tmp_r )
			ISGOOD = false;
		
		// -------------------------------------------------------------
		// Test move across boundary to left
		tmp_m.move(-1);
		if( tmp_m.get_position() != 4 && tmp_m.get_line() != tmp_l )
			ISGOOD = false;

		if(ISGOOD)
			report("test_move_outside_line",GOOD);
		else
			report("test_move_outside_line",BAD);

		delete tmp_l;
		delete tmp_r;
	}

	int test_notify(){
		std::string left = "ABCDE";
		afe::Line* tmp_l = new afe::Line(left);
		afe::Mark tmp_m(tmp_l);
		
		// GOOD FLAG
		bool ISGOOD = true;

		// -------------------------------------------------------------
		// Test delete single character
		message::DeleteCharacter* msg = new message::DeleteCharacter(0);
		tmp_l->request(msg);
		
		if( tmp_m.get_position() != 0 ){
			ISGOOD = false;
		}

		// -------------------------------------------------------------
		// Test insert single character
		message::InsertCharacter* msg1 = new message::InsertCharacter(0,'A');
		tmp_l->request(msg1);

		if( tmp_m.get_position() != 1 ){
			ISGOOD = false;
		}

		// -------------------------------------------------------------
		// Test insert substring
		message::InsertSubstring* msg2 = new message::InsertSubstring(1,"TEST");
		tmp_l->request(msg2);

		if( tmp_m.get_position() != 5 ){
			ISGOOD = false;
		}

		// -------------------------------------------------------------
		// Test delete substring
		message::DeleteSubstring* msg3 = new message::DeleteSubstring(1,3);
		tmp_l->request(msg3);

		if( tmp_m.get_position() != 3 ){
			ISGOOD = false;
		}

		// -------------------------------------------------------------
		// Test delete substring
		message::DeleteSubstring* msg4 = new message::DeleteSubstring(1,4);
		tmp_l->request(msg4);

		if( tmp_m.get_position() != 1 ){
			ISGOOD = false;
		}

		if(ISGOOD)
			report("test_notify",GOOD);
		else
			report("test_notify",BAD);

		delete tmp_l;
		delete msg;
		delete msg1;
		delete msg2;
	}

}

int main( int argc, char* argv[] ){
	// title line
	std::cout << "running all MARK tests:" << std::endl;
	
	// begin tests
	// -----------------------------------------------------------------
	
	test::test_initialization();
	test::test_move_inside_line();
	test::test_move_outside_line();
	test::test_notify();

	// -----------------------------------------------------------------
	// end tests
	std::cout << "MARK tests complete!" << std::endl;
	
	
	// conclusion
	test::report("ALL",test::RESULT);
	return test::RESULT;
}



