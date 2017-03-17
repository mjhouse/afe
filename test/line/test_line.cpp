// system includes
#include <iostream>	// for ostream
#include <iomanip>
#include <sstream>

// local includes
#include "../../line.hpp"
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
		afe::Line* tmp = new afe::Line();
		
		// test initialization
		if( tmp->next == NULL || tmp->prev == NULL )
			report("initialization test",GOOD);
		else
			report("initialization test",BAD);
		
		delete tmp;
	}

	void test_string_initialization(){
		std::string s = "TEST";
		
		// test initialization w/ string
		afe::Line* tmp = new afe::Line(s);
		
		if(tmp->content == s)
			report("initialization string test",GOOD);
		else
			report("initialization string test",BAD);
		
		delete tmp;
	}

	void test_ostream_object(){
		std::string s = "TEST";
		
		afe::Line tmp1;
		tmp1.content = s;
		
		afe::Line* tmp2 = new afe::Line();
		tmp2->content = s;
		
		
		std::ostringstream os1;
		std::ostringstream os2;
		
		// test output-stream
		os1 << tmp1;
		os2 << tmp2;
		
		if(tmp2->content == os2.str() && tmp1.content == os1.str())
			report("ostream test",GOOD);
		else
			report("ostream test",BAD);
		
		delete tmp2;
	}

	void test_insert_char_empty(){
		afe::Line* tmp = new afe::Line();
		
		tmp->insert(0,'A');
		
		if( tmp->content.at(0) == 'A' )
			report("test_insert_char_empty",GOOD);
		else
			report("test_insert_char_empty",BAD);
		
		delete tmp;
	}
	
	void test_insert_char_empty_left(){
		afe::Line* tmp = new afe::Line();
		
		try {
			tmp->insert(-1,'A');
		}
		catch(const std::out_of_range&) {
			report("test_insert_char_empty_left",GOOD);
			delete tmp;
			return;
		}
		report("test_insert_char_empty",BAD);
		delete tmp;
	}

	void test_insert_char_empty_right(){
		afe::Line* tmp = new afe::Line();
		
		try {
			tmp->insert(1,'A');
		}
		catch(const std::out_of_range&) {
			report("test_insert_char_empty_right",GOOD);
			delete tmp;
			return;
		}
		report("test_insert_char_empty_right",BAD);
		delete tmp;
	}
	
	// -----------------------------------------------------------------
	// NONEMPTY
	void test_insert_char_nonempty(){
		std::string s = "THIS IS A TEST";
		afe::Line* tmp = new afe::Line(s);
		
		tmp->insert(0,'X');
		tmp->insert(6,'X');
		tmp->insert(16,'X');
		
		if( tmp->content.at(0) == 'X' && tmp->content.at(6) == 'X' && tmp->content.at(16) == 'X' )
			report("test_insert_char_nonempty",GOOD);
		else
			report("test_insert_char_nonempty",BAD);
		
		delete tmp;
	}
	
	void test_insert_char_nonempty_left(){
		std::string s = "THIS IS A TEST";
		afe::Line* tmp = new afe::Line(s);
		
		try {
			tmp->insert(-1,'A');
		}
		catch(const std::out_of_range&) {
			report("test_insert_char_nonempty_left",GOOD);
			delete tmp;
			return;
		}
		report("test_insert_char_nonempty_left",BAD);
		delete tmp;
	}

	void test_insert_char_nonempty_right(){
		std::string s = "THIS IS A TEST";
		afe::Line* tmp = new afe::Line(s);
		
		try {
			tmp->insert(15,'A');
		}
		catch(const std::out_of_range&) {
			report("test_insert_char_nonempty_right",GOOD);
			delete tmp;
			return;
		}
		report("test_insert_char_nonempty_right",BAD);
		delete tmp;
	}
	
	// -----------------------------------------------------------------
	// STRING INSERT
	void test_insert_string_empty(){
		std::string s = "TEST";
		afe::Line* tmp = new afe::Line();
		
		tmp->insert(0,s);
		
		if( tmp->content == s )
			report("test_insert_string_empty",GOOD);
		else
			report("test_insert_string_empty",BAD);
		
		delete tmp;
	}
	
	void test_insert_string_empty_left(){
		std::string s = "TEST";
		afe::Line* tmp = new afe::Line();
		
		try {
			tmp->insert(-1,s);
		}
		catch(const std::out_of_range&) {
			report("test_insert_string_empty_left",GOOD);
			delete tmp;
			return;
		}
		report("test_insert_string_empty",BAD);
		delete tmp;
	}

	void test_insert_string_empty_right(){
		std::string s = "TEST";
		afe::Line* tmp = new afe::Line();
		
		try {
			tmp->insert(1,s);
		}
		catch(const std::out_of_range&) {
			report("test_insert_string_empty_right",GOOD);
			delete tmp;
			return;
		}
		report("test_insert_string_empty_right",BAD);
		delete tmp;
	}
	
	// -----------------------------------------------------------------
	// NONEMPTY
	void test_insert_string_nonempty(){
		std::string s = "THIS IS A TEST";
		std::string test_s = "TEST";
		afe::Line* tmp = new afe::Line(s);
		
		tmp->insert(0,test_s);
		
		if(tmp->content.compare(0,3,test_s))
			report("test_insert_string_nonempty",GOOD);
		else
			report("test_insert_string_nonempty",BAD);
		
		delete tmp;
	}
	
	void test_insert_string_nonempty_left(){
		std::string s = "THIS IS A TEST";
		std::string test_s = "TEST";
		afe::Line* tmp = new afe::Line(s);
		
		try {
			tmp->insert(-1,test_s);
		}
		catch(const std::out_of_range&) {
			report("test_insert_string_nonempty_left",GOOD);
			delete tmp;
			return;
		}
		report("test_insert_string_nonempty_left",BAD);
		delete tmp;
	}

	void test_insert_string_nonempty_right(){
		std::string s = "THIS IS A TEST";
		std::string test_s = "TEST";
		afe::Line* tmp = new afe::Line(s);
		
		try {
			tmp->insert(15,test_s);
		}
		catch(const std::out_of_range&) {
			report("test_insert_string_nonempty_right",GOOD);
			delete tmp;
			return;
			
		}
		report("test_insert_string_nonempty_right",BAD);
		delete tmp;
	}

	// -----------------------------------------------------------------
	// REMOVE CHAR
	void test_remove_char_nonempty(){
		std::string s = "TEST";
		afe::Line* tmp = new afe::Line(s);
		
		tmp->remove(0);
		if(tmp->content.compare(1,2,s)){
			report("test_remove_char_nonempty",GOOD);
		}
		else {
			report("test_remove_char_nonempty",BAD);
		}
		delete tmp;
	}
	
	void test_remove_string_nonempty(){
		std::string s = "TEST";
		afe::Line* tmp = new afe::Line(s);
		
		tmp->remove(0,3);
		if(tmp->content == "T"){
			report("test_remove_string_nonempty",GOOD);
		}
		else {
			report("test_remove_string_nonempty",BAD);
		}
		delete tmp;
		
	}
	
	void test_str(){
		std::string s = "TEST";
		afe::Line* tmp = new afe::Line(s);
		
		if(tmp->str() == s){
			report("test_str",GOOD);
		}
		else {
			report("test_str",BAD);
		}
		delete tmp;
		
	}

	void test_request(){
		std::string s = "TEST";
		std::string sub = " AND ZEST ";
		
		std::string cmp = "X AND EST";
		afe::Line* tmp = new afe::Line(s);
		
		message::DeleteCharacter* msg = new message::DeleteCharacter(0);
		tmp->request(msg);

		message::InsertCharacter* msg1 = new message::InsertCharacter(0,'X');
		tmp->request(msg1);

		message::InsertSubstring* msg2 = new message::InsertSubstring(1,sub);
		tmp->request(msg2);

		message::DeleteSubstring* msg3 = new message::DeleteSubstring(5,10);
		tmp->request(msg3);

		if(tmp->str() == cmp){
			report("test_request",GOOD);
		}
		else {
			report("test_request",BAD);
		}
		delete tmp;
		delete msg;
	}
	

}

int main( int argc, char* argv[] ){
	// title line
	std::cout << "running all LINE tests:" << std::endl;
	
	// begin tests
	// -----------------------------------------------------------------
	
	test::test_initialization();
	test::test_string_initialization();
	test::test_ostream_object();
	
	test::test_insert_char_empty();
	test::test_insert_char_empty_left();
	test::test_insert_char_empty_right();

	test::test_insert_char_nonempty();
	test::test_insert_char_nonempty_left();
	test::test_insert_char_nonempty_right();	
	
	test::test_insert_string_empty();
	test::test_insert_string_empty_left();
	test::test_insert_string_empty_right();

	test::test_insert_string_nonempty();
	test::test_insert_string_nonempty_left();
	test::test_insert_string_nonempty_right();	
	
	test::test_remove_char_nonempty();
	test::test_remove_string_nonempty();
	
	test::test_str();
	test::test_request();
	// -----------------------------------------------------------------
	// end tests
	std::cout << "LINE tests complete!" << std::endl;
	
	
	// conclusion
	test::report("ALL",test::RESULT);
	return test::RESULT;
}



