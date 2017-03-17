#include "message.hpp"

namespace message {

	// -----------------------------------------------------------------
	// DeleteCharacter
	DeleteCharacter::DeleteCharacter( int i ){
		creator = nullptr;
		if( i >= 0 ) 
			location = i;
		else
			location = 0;
	}

	void DeleteCharacter::set_sender( afe::Mark* m ){
		creator = m;
	}

	void DeleteCharacter::execute( afe::Line* line ){
		if( (unsigned)location > line->length() ){
			location = line->length();
		}
		line->remove(location);
	}

	void DeleteCharacter::execute( afe::Mark* mark ){
		if(location < mark->get_position()){
			mark->move(-1);
		}
	}

	afe::Mark* DeleteCharacter::sender(){
		return creator;
	}

	// -----------------------------------------------------------------
	// DeleteSubstring
	DeleteSubstring::DeleteSubstring( int i, int j ){
		creator = nullptr;
		if(i >= 0){
			left_location = i;
		}
		else {
			left_location = 0;
		}
		right_location = j; 
	}
	
	void DeleteSubstring::set_sender( afe::Mark* m ){
		creator = m;
	}
	
	void DeleteSubstring::execute( afe::Line* line ){
		if( (unsigned)right_location > line->length() ){
			right_location = line->length();
		}
		line->remove(left_location,right_location);
	}

	void DeleteSubstring::execute( afe::Mark* mark ){
		// if entire deleted string is to left, shift by length
		if(right_location < mark->get_position()){
			mark->move( -(right_location-left_location) );
			return;
		}
		
		// if deleted string runs over mark position, go just right of left_location
		if( (left_location < mark->get_position()) && (right_location >= mark->get_position()) ){
			mark->move( -(mark->get_position()-left_location) );
		}
	}
	
	afe::Mark* DeleteSubstring::sender(){
		return creator;
	}

	// -----------------------------------------------------------------
	// InsertCharacter
	InsertCharacter::InsertCharacter( int i, char c ){
		creator = nullptr;
		if( i >= 0 ) 
			location = i;
		else
			location = 0;
		character = c; 
	}
	
	void InsertCharacter::set_sender( afe::Mark* m ){
		creator = m;
	}
	
	void InsertCharacter::execute( afe::Line* line ){
		if( (unsigned)location > line->length() ){
			location = line->length();
		}
		line->insert(location,character);
	}

	void InsertCharacter::execute( afe::Mark* mark ){
		if( location <= mark->get_position() ){
			mark->move( 1 );
		}
	}

	afe::Mark* InsertCharacter::sender(){
		return creator;
	}

	// -----------------------------------------------------------------
	// InsertSubstring
	InsertSubstring::InsertSubstring( int i, std::string s ){
		creator = nullptr;
		if( i >= 0 ) 
			location = i;
		else
			location = 0;
		substring = s;
	}
	
	void InsertSubstring::set_sender( afe::Mark* m ){
		creator = m;
	}
	
	void InsertSubstring::execute( afe::Line* line ){
		if( (unsigned)location > line->length() ){
			location = line->length();
		}
		line->insert(location,substring);
	}

	void InsertSubstring::execute( afe::Mark* mark ){
		if( location <= mark->get_position() ){
			mark->move( substring.length() );
		}
	}

	afe::Mark* InsertSubstring::sender(){
		return creator;
	}
	
}
