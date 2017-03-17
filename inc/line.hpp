#ifndef _LINE_HPP_
#define _LINE_HPP_

// system includes
#include <string>

// local includes
#include "message.hpp"
#include "markregister.hpp"

namespace message { class BaseMessage; }

namespace afe {

	class MarkRegister;

	class Line {
		public:
			std::string content;
			MarkRegister* registry;
			Line* prev;
			Line* next;
			
		public:
			Line();
			Line( std::string s );
			~Line();
			
			void insert( int i, char c );
			void insert( int i, std::string s );
			
			void remove( int i );
			void remove( int i, int j );

			void request( message::BaseMessage* msg );
			
			size_t length();
			std::string str();
			
			friend std::ostream& operator<<( std::ostream& output, const Line& l );
			friend std::ostream& operator<<( std::ostream& output, const Line* l );
			//friend link( Line* l, Line* r );
	};
	
}

#endif
