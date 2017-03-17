// system includes
#include <iostream>	// for ostream
#include <iomanip>
#include <sstream>

// local includes
#include "../../line.hpp"
#include "../../basicbuffer.hpp"

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
			std::cout << "	" << std::setw(50) << std::left << s << "~FAILED!" << std::endl; 
		}
	}

	int test_initialization(){
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		
		// test initialization
		if(tmp->linecount() == 0)
			report("test_initialization",GOOD);
		else
			report("test_initialization",BAD);
		
		delete tmp;
	}

	void test_append_line_line_empty(){
		std::string test_str = "This is a test string";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		afe::Line* tmp_l = new afe::Line(test_str);
		
		// test append line (Line*)
		tmp->append_line(tmp_l);
		
		if(tmp->get_line(0) == test_str)
			report("test_append_line_line_empty",GOOD);
		else
			report("test_append_line_line_empty",BAD);
		
		delete tmp;
	}

	void test_append_line_line_nonempty(){
		std::string test_str0 = "This is a test string";
		std::string test_str1 = "TWO";
		std::string test_str2 = "THREE";
		
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		afe::Line* tmp_l0 = new afe::Line(test_str0);
		afe::Line* tmp_l1 = new afe::Line(test_str1);
		afe::Line* tmp_l2 = new afe::Line(test_str2);
		
		// test append line (Line*)
		tmp->append_line(tmp_l0);
		tmp->append_line(tmp_l1);
		tmp->append_line(tmp_l2);
		
		if(tmp->get_line(0) == test_str0 && tmp->get_line(1) == test_str1 && tmp->get_line(2) == test_str2 )
			report("test_append_line_line_nonempty",GOOD);
		else
			report("test_append_line_line_nonempty",BAD);
		
		delete tmp;
	}

	void test_append_line_string_empty(){
		std::string test_str = "This is a test string";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		
		tmp->append_line(test_str);
		
		if(tmp->get_line(0) == test_str)
			report("test_append_line_string_empty",GOOD);
		else
			report("test_append_line_string_empty",BAD);
		
		delete tmp;
	}

	void test_append_line_string_nonempty(){
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "INSERT";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		tmp->append_line(test_str3);

		if(tmp->get_line(0) == test_str1 && tmp->get_line(1) == test_str2 && tmp->get_line(2) == test_str3 )
			report("test_append_line_string_nonempty",GOOD);
		else
			report("test_append_line_string_nonempty",BAD);
		
		delete tmp;
	}

	void test_insert_line_line_empty(){
		std::string test_str = "This is a test string";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		afe::Line* tmp_l = new afe::Line(test_str);
		
		// test append line (Line*)
		tmp->insert_line(0, tmp_l);
		
		if(tmp->get_line(0) == test_str)
			report("test_insert_line_line_empty",GOOD);
		else
			report("test_insert_line_line_empty",BAD);
		
		delete tmp;
	}

	void test_insert_line_line_empty_left(){
		std::string test_str = "This is a test string";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		afe::Line* tmp_l = new afe::Line(test_str);
		
		// test append line (Line*)
		tmp->insert_line(-2, tmp_l);
		
		if(tmp->get_line(0) == test_str)
			report("test_insert_line_line_empty_left",GOOD);
		else
			report("test_insert_line_line_empty_left",BAD);
		
		delete tmp;
	}

	void test_insert_line_line_empty_right(){
		std::string test_str = "This is a test string";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		afe::Line* tmp_l = new afe::Line(test_str);
		
		// test append line (Line*)
		tmp->insert_line(2, tmp_l);
		
		if(tmp->get_line(0) == test_str)
			report("test_insert_line_line_empty_right",GOOD);
		else
			report("test_insert_line_line_empty_right",BAD);
		
		delete tmp;
	}

	void test_insert_line_string_empty(){
		std::string test_str = "This is a test string";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		
		tmp->insert_line(0,test_str);
		
		if(tmp->get_line(0) == test_str)
			report("test_insert_line_string_empty",GOOD);
		else
			report("test_insert_line_string_empty",BAD);
		
		delete tmp;
	}

	void test_insert_line_string_empty_left(){
		std::string test_str = "This is a test string";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		
		tmp->insert_line(-2,test_str);
		
		if(tmp->get_line(0) == test_str)
			report("test_insert_line_string_empty_left",GOOD);
		else
			report("test_insert_line_string_empty_left",BAD);
		
		delete tmp;
	}
	
	void test_insert_line_string_empty_right(){
		std::string test_str = "This is a test string";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		
		tmp->insert_line(2,test_str);
		
		if(tmp->get_line(0) == test_str)
			report("test_insert_line_string_empty_right",GOOD);
		else
			report("test_insert_line_string_empty_right",BAD);
		
		delete tmp;
	}

	void test_insert_line_line_nonempty(){
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "INSERT";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		afe::Line* tmp_line = new afe::Line(test_str3);
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		
		// test append line (Line*)
		tmp->insert_line(1, tmp_line);
		
		if(tmp->get_line(1) == test_str3)
			report("test_insert_line_line_nonempty",GOOD);
		else
			report("test_insert_line_line_nonempty",BAD);
		
		delete tmp;
	}
	
	void test_insert_line_line_nonempty_left(){
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "INSERT";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		afe::Line* tmp_line = new afe::Line(test_str3);
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		
		// negative indices push_back
		tmp->insert_line(-4,tmp_line);
		
		if(tmp->get_line(2) == test_str3)
			report("test_insert_line_line_nonempty_left",GOOD);
		else
			report("test_insert_line_line_nonempty_left",BAD);
		
		delete tmp;
	}

	void test_insert_line_line_nonempty_right(){
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "INSERT";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		afe::Line* tmp_line = new afe::Line(test_str3);
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		
		tmp->insert_line(4,tmp_line);
		
		if(tmp->get_line(2) == test_str3)
			report("test_insert_line_line_nonempty_right",GOOD);
		else
			report("test_insert_line_line_nonempty_right",BAD);
		
		delete tmp;
	}
	
	void test_insert_line_string_nonempty(){
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "INSERT";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		
		tmp->insert_line(1,test_str3);
		
		if(tmp->get_line(1) == test_str3)
			report("test_insert_line_string_nonempty",GOOD);
		else
			report("test_insert_line_string_nonempty",BAD);
		
		delete tmp;
	}
	
	void test_insert_line_string_nonempty_left(){
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "INSERT";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		
		// negative indices push_back
		tmp->insert_line(-4,test_str3);
		
		if(tmp->get_line(2) == test_str3)
			report("test_insert_line_string_nonempty_left",GOOD);
		else
			report("test_insert_line_string_nonempty_left",BAD);
		
		delete tmp;
	}
	
	void test_insert_line_string_nonempty_right(){
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "INSERT";
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		
		tmp->insert_line(4,test_str3);
		
		if(tmp->get_line(2) == test_str3)
			report("test_insert_line_string_nonempty_right",GOOD);
		else
			report("test_insert_line_string_nonempty_right",BAD);
		
		delete tmp;
	}
	// GET_LINE
	void test_get_line_empty(){
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		std::string s = tmp->get_line(0);
		
		if(s.empty())
			report("test_get_line_empty",GOOD);
		else
			report("test_get_line_empty",BAD);
		
		delete tmp;
	}
	
	void test_get_line_empty_left(){
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		std::string s = tmp->get_line(-2);
		
		if(s.empty())
			report("test_get_line_empty_left",GOOD);
		else
			report("test_get_line_empty_left",BAD);
		
		delete tmp;
	}
	
	void test_get_line_empty_right(){
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		std::string s = tmp->get_line(2);
		
		if(s.empty())
			report("test_get_line_empty_right",GOOD);
		else
			report("test_get_line_empty_right",BAD);
		
		delete tmp;
	}
	
	void test_get_line_nonempty(){
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "THIRD";
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		tmp->append_line(test_str3);
		
		std::string s = tmp->get_line(1);
		
		if(s == test_str2)
			report("test_get_line_nonempty",GOOD);
		else
			report("test_get_line_nonempty",BAD);
		
		delete tmp;
	}
	
	void test_get_line_nonempty_left(){
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "THIRD";
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		tmp->append_line(test_str3);
		
		std::string s = tmp->get_line(-1);
		
		if(s.empty())
			report("test_get_line_nonempty_left",GOOD);
		else
			report("test_get_line_nonempty_left",BAD);
		
		delete tmp;
	}
	
	void test_get_line_nonempty_right(){
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "THIRD";
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		tmp->append_line(test_str3);
		
		std::string s = tmp->get_line(3);
		
		if(s.empty())
			report("test_get_line_nonempty_right",GOOD);
		else
			report("test_get_line_nonempty_right",BAD);
		
		delete tmp;
	}
	
	void test_linecount(){
		afe::BasicBuffer* tmp = new afe::BasicBuffer();
		std::string test_str1 = "FIRST";
		std::string test_str2 = "SECOND";
		std::string test_str3 = "THIRD";
		tmp->append_line(test_str1);
		tmp->append_line(test_str2);
		tmp->append_line(test_str3);
		
		int lc = tmp->linecount();
		
		if(lc = 2)
			report("test_linecount",GOOD);
		else
			report("test_linecount",BAD);
		
		delete tmp;
	}

}

int main( int argc, char* argv[] ){
	// title line
	std::cout << "running all BASICBUFFER tests:" << std::endl;
	
	// begin tests
	// -----------------------------------------------------------------
	
	test::test_initialization();
	
	// append line
	test::test_append_line_line_empty();
	test::test_append_line_line_nonempty();
	
	// append string
	test::test_append_line_string_empty();
	test::test_append_line_string_nonempty();
	
	// insert
	test::test_insert_line_line_empty();
	test::test_insert_line_line_empty_left();
	test::test_insert_line_line_empty_right();
	
	test::test_insert_line_string_empty();
	test::test_insert_line_string_empty_left();
	test::test_insert_line_string_empty_right();
	
	test::test_insert_line_line_nonempty();
	test::test_insert_line_line_nonempty_left();
	test::test_insert_line_line_nonempty_right();
	
	test::test_insert_line_string_nonempty();
	test::test_insert_line_string_nonempty_left();
	test::test_insert_line_string_nonempty_right();
	
	test::test_get_line_empty();
	test::test_get_line_empty_left();
	test::test_get_line_empty_right();
	
	test::test_get_line_nonempty();
	test::test_get_line_nonempty_left();
	test::test_get_line_nonempty_right();
	
	test::test_linecount();
	
	// -----------------------------------------------------------------
	// end tests
	std::cout << "BASICBUFFER tests complete!" << std::endl;
	
	
	// conclusion
	test::report("ALL",test::RESULT);
	return test::RESULT;
}



