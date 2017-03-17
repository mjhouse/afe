#include "markregister.hpp"

namespace afe {
	
	MarkRegister::MarkRegister(){
	}

	MarkRegister::~MarkRegister(){
	}
	
	bool MarkRegister::includes( Mark* m ){
		return (std::find(marks.begin(), marks.end(), m) != marks.end());
	}
	
	void MarkRegister::register_mark( Mark* m ){
		if(!includes(m))
			marks.push_back(m);
	}
	
	void MarkRegister::unregister_mark( Mark* m ){
		marks.erase( std::remove_if( marks.begin(), marks.end(), 
			[m]( Mark* elem ){ return m == elem; }), 
		marks.end() );
	}
	
	void MarkRegister::notify_marks( message::BaseMessage* msg ){
		for(std::vector<Mark*>::iterator it = marks.begin() ; it != marks.end() ; ++it){
			Mark* m = *it;
			m->notify( msg );
		}
	}
	
	int MarkRegister::registered(){
		return marks.size();
	}
	
}
