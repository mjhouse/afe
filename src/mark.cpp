#include "mark.hpp"

namespace afe {

	Mark::Mark( Line* l, int i ){
		line = nullptr;
		pos = 0;
		jump_to(l,i);
	}
	
	Mark::Mark(  const Mark& m ){
		line = nullptr;
		pos = 0;
		jump_to( m.line, m.pos );
	}

	Mark::Mark(  Mark* m ){
		line = nullptr;
		pos = 0;
		jump_to( m->line, m->pos );
	}

	Mark::~Mark(){
		line = nullptr;
		pos = 0;
	}

	// -----------------------------------------------------------------
	// Private Functions
	void Mark::jump_to( Line* l, unsigned int i ){
		if( i > l->length() ) { // out-of-bounds check
			throw std::out_of_range ("position doesn't exist");
		}
		unregister_self(); 	// unregister
		line = l; pos = i; 	// jumping to new line
		register_self();	// re-register
	}
	
	void Mark::unregister_self(){
		if(line){
			line->registry->unregister_mark(this);
		}
	}

	void Mark::register_self(){
		if(line){
			line->registry->register_mark(this);
		}
	}

	// -----------------------------------------------------------------
	// Public Functions
	int Mark::get_position(){
		return pos;
	}

	Line* Mark::get_line(){
		return line;
	}

	void Mark::move( signed int i ){
		if(i>0){
			// move right
			while(i>0){
				if( pos < ( (signed)line->length()-1 ) ){
					++pos;
				}
				else{
					if(line->next != NULL){
						jump_to(line->next,0);
					}
				}
				--i;
			}
		}
		else {
			// move left
			while(i<0){
				if(pos > 0) {
					--pos;
				}
				else {
					if(line->prev != NULL){
						jump_to(line->prev,line->prev->length()-1);
					}
				}
				++i;
			}
		}
	}
	
	void Mark::notify( message::BaseMessage* msg ){
		if(msg->sender() != this){ // not sent by this mark
			msg->execute( this );
		}
	}

}
