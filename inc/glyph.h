#include <GL/freeglut.h>

#ifndef _GLYPH_H
#define _GLYPH_H
/*
struct Glyph {
	Glubyte* buffer;
	Uint width;
	Uint height;
};

Glyph* GetGlyph(const unsigned char ch)
{
	if(FT_Load_Char(mFace, ch, FT_LOAD_RENDER))
		cout << "OUCH" << endl;
	
	FT_Glyph glyph;
	
	if(FT_Get_Glyph( mFace->glyph, &glyph ))
		cout << "OUCH" << endl;
	
	FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;
	
	Glyph* thisGlyph = new Glyph;
	thisGlyph->buffer = bitmap_glyph->bitmap.buffer;
	thisGlyph->width = bitmap_glyph->bitmap.width;
	thisGlyph->height = bitmap_glyph->bitmap.rows;
	return thisGlyph;
}
*/
#endif
