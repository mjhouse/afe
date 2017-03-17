#ifndef _BASICBUFFER_HPP_
#define _BASICBUFFER_HPP_

// system includes
#include <iostream>		// i/ostream objects
#include <fstream>		// file i/o

// local includes
#include "line.hpp"
#include "cursor.hpp"

namespace afe {

	class BasicBuffer {
		private:
			std::string file_name;
			Line* start;
			Line* end;
			size_t line_count;
			
			
			int link( Line* l, Line* r);
			Line* forward_find_line( int i );
			Line* backward_find_line( int i );
			Line* find_line( unsigned int i );
			int push_back( Line* l );
			int push_front( Line* l );

			// ---------------------------------------------------------
			void append_line( Line* l );
			void append_line( std::string s );
			
			void insert_line( int i, Line* l );
			void insert_line( int i, std::string s );
			
			std::string get_str( int i );
			Line* get_line( int i );
			
			void remove_line( int i );
			size_t linecount();

		public:
			BasicBuffer();
			BasicBuffer( std::string fn );
			~BasicBuffer();
			
			// ---------------------------------------------------------
			bool load( std::string fn );
			bool save();
			bool save_as( std::string fn );
			Cursor* get_cursor();
			
			friend std::ostream& operator<<( std::ostream& output, const BasicBuffer& b );
	};

}

#endif
