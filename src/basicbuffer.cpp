#include "basicbuffer.hpp"


namespace afe {

	// -----------------------------------------------------------------
	// Constructor/Destructors
	BasicBuffer::BasicBuffer(){
		start = NULL;
		end = NULL;
		line_count = 0;
	}

	BasicBuffer::BasicBuffer( std::string fn ){
		start = NULL;
		end = NULL;
		line_count = 0;
		load( fn );
	}

	BasicBuffer::~BasicBuffer(){
		while(start){
			Line* tmp = start;
			start = start->next;
			delete tmp;
		}		
	}
	
	// -----------------------------------------------------------------
	// Private Functions
	int BasicBuffer::link( Line* l, Line* r){
		if(l && r){
			l->next = r;
			r->prev = l;
			return 1;
		}
		else {
			return 0;
		}
	}
	
	Line* BasicBuffer::forward_find_line( int i ){
		Line* tmp = start;
		while(tmp){
			if(i==0)
				return tmp;
			tmp = tmp->next; --i;
		}
		return NULL;
	}
	
	Line* BasicBuffer::backward_find_line( int i ){
		Line* tmp = end;
		i = (line_count - i);
		while(tmp){
			if(i==0)
				return tmp;
			tmp = tmp->prev; --i;
		}
		return NULL;
	}
	
	Line* BasicBuffer::find_line( unsigned int i ){
		if( i > ( line_count / 2 )){
			return backward_find_line(i);
		}
		else {
			return forward_find_line(i);
		}
	}
	
	int BasicBuffer::push_back( Line* l ){
		if(start && end){
			link(end,l);
			end = l;
			++line_count;
			return 1;
		}
		else {
			start = l;
			end = start;
			return 1;
		}
	}
	
	int BasicBuffer::push_front( Line* l ){
		if(start && end){
			link(l,start);
			start = l;
			++line_count;
			return 1;
		}
		else {
			start = l;
			end = start;
			return 1;
		}
	}

	void BasicBuffer::append_line( Line* l ){
		push_back(l);
	}

	void BasicBuffer::append_line( std::string s ){
		Line* new_line = new Line(s);
		push_back(new_line);
	}

	void BasicBuffer::insert_line( int i, Line* l ){
		Line* tmp_right = find_line(i);
		if(tmp_right){
			if(tmp_right!=start){
				Line* tmp_left = tmp_right->prev;
				link(tmp_left,l);	// link tmp_left on left
				link(l,tmp_right);	// link tmp_right on right
				++line_count;
			}
			else {
				push_front(l);
			}
		}
		else {
			push_back(l);
		}
	}
	
	void BasicBuffer::insert_line( int i, std::string s ){
		Line* tmp = new Line(s);
		insert_line(i,tmp);
	}
	
	std::string BasicBuffer::get_str( int i ){
		Line* tmp = find_line(i);
		std::string s;
		if(tmp)
			return tmp->content;
		else
			return s;
	}

	Line* BasicBuffer::get_line( int i ){
		return find_line(i);
	}
	
	void BasicBuffer::remove_line( int i ){
		Line* tmp = find_line(i);
		link(tmp->prev,tmp->next);
		--line_count;
		delete tmp;
	}

	size_t BasicBuffer::linecount(){
		return line_count;
	}

	// -----------------------------------------------------------------
	// Public Functions
	bool BasicBuffer::load( std::string fn ){
		std::ifstream fh( fn, std::ios::in );
		if( fh.is_open() ){
			file_name = fn;
			
			std::string line;
			while( std::getline(fh,line) ){
				this->append_line(line);
			}
			fh.close();
			return true;
		
		} else { return false; }
	}
	
	bool BasicBuffer::save(){
		if( !file_name.empty() ){
			
			std::ofstream fh( file_name, std::ios::out );
			if( fh.is_open() ){
				fh << *this;
				fh.close();
				return true;
			
			} else { return false; }
		} else { return false; }
	}

	bool BasicBuffer::save_as( std::string fn ){
		file_name = fn;
		return save();
	}

	Cursor* BasicBuffer::get_cursor(){
		Cursor* cur = new Cursor( start );
		return cur;
	}
	
	// -----------------------------------------------------------------
	// Friend Functions
	std::ostream& operator<<( std::ostream& output, const BasicBuffer& b ){
		Line* tmp = b.start;
		while(tmp){
			output << tmp << std::endl;
			tmp = tmp->next;
		}
		return output;
	}

}
