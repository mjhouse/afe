#include "line.hpp"

namespace afe {
	
	Line::Line(){
		registry = new MarkRegister();
		prev = NULL;
		next = NULL;
	}
	
	Line::Line( std::string s ){
		content = s;
		registry = new MarkRegister();
		prev = NULL;
		next = NULL;
	}
	
	Line::~Line(){
		delete registry;
		prev = NULL;
		next = NULL;
	}
	
	void Line::insert( int i, char c ){
		content.insert(i,1,c);
	}
	
	void Line::insert( int i, std::string s ){
		content.insert(i,s);
	}
	
	void Line::remove( int i ){
		content.erase(i,1);
	}
	
	void Line::remove( int i, int j ){
		content.erase(i,j-i);
	}
	
	void Line::request( message::BaseMessage* msg ){
		msg->execute( this );
		
		registry->notify_marks(msg);
	}
	
	size_t Line::length(){
		return content.length();
	}

	std::string Line::str(){
		return content;
	}

	
	// -----------------------------------------------------------------
	// Friend Functions
	std::ostream& operator<<( std::ostream& output, const Line& l ){
		output << l.content;
		return output;
	}
	
	std::ostream& operator<<( std::ostream& output, const Line* l ){
		if(l) // not null
			output << l->content;
		return output;
	}

}
