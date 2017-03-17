#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_

#include <string>

#include "line.hpp"
#include "mark.hpp"

namespace afe { 
	class Line; 
	class Mark; 
}

namespace message {

	class BaseMessage {
		public:
			virtual ~BaseMessage(){};
		
			// ---------------------------------------------------------
			// used to execute the message against the given line
			virtual void execute( afe::Line* line ) = 0;

			// ---------------------------------------------------------
			// used to execute the message against a mark
			virtual void execute( afe::Mark* mark ) = 0;

			// ---------------------------------------------------------
			// all messages sent by marks must identify themselves
			// (messages not sent by marks can be nullptr)
			virtual afe::Mark* sender() = 0;
			
	};

	class DeleteCharacter : public BaseMessage {
		private:
			afe::Mark* creator;
			int location;
		
		public:
			DeleteCharacter( int i );
			~DeleteCharacter(){};

			// ---------------------------------------------------------
			// Unique functions
			void set_sender( afe::Mark* m );
			
			// ---------------------------------------------------------
			// Mandatory functions
			void execute( afe::Line* line );
			void execute( afe::Mark* mark );
			afe::Mark* sender();
	};
	
	class DeleteSubstring : public BaseMessage {
		private:
			afe::Mark* creator;
			int left_location;
			int right_location;
		
		public:
			DeleteSubstring( int i, int j );
			~DeleteSubstring(){};
			// ---------------------------------------------------------
			// Unique functions
			void set_sender( afe::Mark* m );

			// ---------------------------------------------------------
			// Mandatory functions
			void execute( afe::Line* line );
			void execute( afe::Mark* mark );
			afe::Mark* sender();
	};
	
	class InsertCharacter : public BaseMessage {
		private:
			afe::Mark* creator;
			int location;
			int character;
		
		public:
			InsertCharacter( int i, char c );
			~InsertCharacter(){};
			// ---------------------------------------------------------
			// Unique functions
			void set_sender( afe::Mark* m );
			
			// ---------------------------------------------------------
			// Mandatory functions	
			void execute( afe::Line* line );
			void execute( afe::Mark* mark );
			afe::Mark* sender();
	};
	
	class InsertSubstring : public BaseMessage {
		private:
			afe::Mark* creator;
			int location;
			std::string substring;
		
		public:
			InsertSubstring( int i, std::string s );
			~InsertSubstring(){};
			
			// ---------------------------------------------------------
			// Unique functions
			void set_sender( afe::Mark* m );

			// ---------------------------------------------------------
			// Mandatory functions
			void execute( afe::Line* line );
			void execute( afe::Mark* mark );
			afe::Mark* sender();
	};
	
}

#endif

