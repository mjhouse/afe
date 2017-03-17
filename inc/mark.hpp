#ifndef _MARK_HPP_
#define _MARK_HPP_

// local includes
#include "line.hpp"
#include "message.hpp"

// for testing
#include <string>
#include <stdexcept>

namespace message { class BaseMessage; }

namespace afe {

	class Line;

	class Mark {
		protected:
			signed int pos;
			Line* line;
			
		private:
			void unregister_self();
			void register_self();
			void jump_to( Line* l, unsigned int i=0 );
			
		public:
			Mark( Line* l, int i=0 );
			Mark( const Mark& m );
			Mark( Mark* m );
			~Mark();
			
			
			int get_position();
			Line* get_line();
			
			void move( signed int i );
			void notify( message::BaseMessage* msg );
			
			/*
			void operator++();
			void operator++(int);
			
			void operator--();
			void operator--(int);
			*/
	};
	
}

#endif

