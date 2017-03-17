#include "cursor.hpp"

namespace afe {

	void Cursor::write( char c ){
		message::InsertCharacter* msg = new message::InsertCharacter(pos,c);
		line->request(msg);
		delete msg;
	}

	void Cursor::write( std::string s ){
		message::InsertSubstring* msg = new message::InsertSubstring(pos,s);
		line->request(msg);
		delete msg;
	}

	void Cursor::erase_back(){
		message::DeleteCharacter* msg = new message::DeleteCharacter(pos-1);
		msg->set_sender(this);
		line->request(msg);
		delete msg;
	}

	void Cursor::erase_forward(){
		message::DeleteCharacter* msg = new message::DeleteCharacter(pos);
		msg->set_sender(this);
		line->request(msg);
		delete msg;
	}

}
