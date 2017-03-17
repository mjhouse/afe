#ifndef _CURSOR_HPP_
#define _CURSOR_HPP_

// local includes
#include "line.hpp"
#include "message.hpp"

// for testing
#include <string>

namespace afe {

	class Line;

	class Cursor: public Mark {
		private:
			
		public:
			Cursor( Line* l, int i=0 ) : Mark(l,i){};
			~Cursor(){};
			
			void write( char c );
			void write( std::string s );
			void erase_back();
			void erase_forward();
			
			//void operator++();
			//void operator++( int );
	};
	
}

#endif

