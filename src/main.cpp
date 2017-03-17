// ---------------------------------------------------------------------
// System Includes
#include <iostream>
#include <map>
#include <stdexcept>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// freetype for fonts
#include <ft2build.h>
#include FT_FREETYPE_H

// ---------------------------------------------------------------------
// Local Includes
#include "basicbuffer.hpp"
#include "cursor.hpp"

// ---------------------------------------------------------------------
// Defines
int WINDOW_WIDTH = 600;
int WINDOW_HEIGHT = 600;

float CANVAS_WIDTH = 100.0f;
float CANVAS_HEIGHT = 100.0f;

FT_Library  FONT_LIBRARY;
FT_Face		FONT_FACE;
std::string FONT_PATH = "/usr/share/fonts/truetype/lato/Lato-Regular.ttf";
int 		FONT_SIZE = 48;

struct Character {
	unsigned int TextureID;
	int Size[2];
	int Bearing[2];
	unsigned int Advance;
};

std::map<GLchar,Character> characters;

// ---------------------------------------------------------------------
// Function Prototypes
void init( void );
void display( GLFWwindow* window );
static void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods );
void error_callback(int error, const char* description);

int main(/* int argc, char* argv[] */){
	if(glfwInit()){
		
		// -------------------------------------------------------------
		GLFWwindow* window = glfwCreateWindow(640,480, "afe", NULL, NULL);
		glfwMakeContextCurrent(window);
		
		if(window){
			GLenum err = glewInit();
			if(err != GLEW_OK){
				std::cout << "ERROR: GLEW: failed to initialize!" << std::endl;
				return -1;
			}
			
			
			// set callbacks
			glfwSetErrorCallback(error_callback);
			glfwSetKeyCallback(window, key_callback);
			
			// init
			init();
			
			glfwGetFramebufferSize(window, &WINDOW_WIDTH, &WINDOW_HEIGHT);
			glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
			
			while ( !glfwWindowShouldClose( window ) ){
				glfwPollEvents();
				display( window );

				glfwSwapBuffers(window);
			}
			
			// destroy the window
			glfwDestroyWindow( window );
		}
		// -------------------------------------------------------------
		
		// close out
		glfwTerminate();
		return 0;
	}
	return 1;
}

// ---------------------------------------------------------------------
// Functions
void init( void ){
	if (FT_Init_FreeType(&FONT_LIBRARY))
		throw std::runtime_error("ERROR: FREETYPE: couldn't init FreeType Font Library");

	if (FT_New_Face(FONT_LIBRARY, FONT_PATH.c_str(), 0, &FONT_FACE))
		throw std::runtime_error("ERROR: FREETYPE: couldn't init FreeType Font Face");
		
	FT_Set_Pixel_Sizes(FONT_FACE, 0, FONT_SIZE);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	// -----------------------------------------------------------------
	// create archive of character glyphs
	for(FT_ULong c = 0; c < 128 ; ++c){
		if( FT_Load_Char( FONT_FACE, c, FT_LOAD_RENDER ) ){
			std::cout << "ERROR: FREETYPE: Failed to load glyph: " << c << std::endl; 
			continue;
		}
		unsigned int texture;
		glGenTextures(1,&texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			FONT_FACE->glyph->bitmap.width,
			FONT_FACE->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			FONT_FACE->glyph->bitmap.buffer
		);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		Character ch;
		ch.TextureID = texture;
		ch.Size[1] = FONT_FACE->glyph->bitmap.width;
		ch.Size[2] = FONT_FACE->glyph->bitmap.rows;
		ch.Bearing[1] = FONT_FACE->glyph->bitmap_left;
		ch.Bearing[2] = FONT_FACE->glyph->bitmap_top;
		ch.Advance = FONT_FACE->glyph->advance.x;
		
		characters.insert(std::pair<GLchar, Character>(c, ch));
	}
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
}

void display( GLFWwindow* window ){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

static void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods ){
	//if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	//	glfwSetWindowShouldClose(window, 1);
	std::cout << "width:" << WINDOW_WIDTH << std::endl;
	std::cout << "height:" << WINDOW_HEIGHT << std::endl;
	
}

void error_callback(int error, const char* description){
    fprintf(stderr, "Error #%d: %s\n", error, description);
}
