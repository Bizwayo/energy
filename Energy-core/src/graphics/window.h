#pragma once

#include <GL/glew.h>
#include <glfw3.h>
#include <iostream>

namespace energy {
	namespace graphics {

		class Window
		{
		private:
			const char* my_Title;	//window title
			int my_Width, my_Height;	//width and height of our window 
			bool my_Closed;				//checks to see if window has been closed
			GLFWwindow* my_Window;		//The window

			bool init();
		public:
			Window(const char *title,int width,int height); //window constructor
			~Window();
			
			bool closed() const;
			void clear() const;
			void update() const;

			int getWidth() const;
			int getHeight() const;
		};

	}
}