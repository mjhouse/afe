#ifndef _MARKREGISTER_HPP_
#define _MARKREGISTER_HPP_

// system includes
#include <algorithm>

// local includes
#include "mark.hpp"
#include "message.hpp"

// for testing
#include <vector>

namespace message { class BaseMessage; }

namespace afe {

	class Mark;

	class MarkRegister {
		private:
			std::vector<Mark*> marks;
			
		public:
			MarkRegister();
			~MarkRegister();

			bool includes( Mark* m );
			void register_mark( Mark* m );
			void unregister_mark( Mark* m );
			void notify_marks( message::BaseMessage* msg );
			
			int registered();

	};
	
}

#endif

