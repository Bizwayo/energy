#pragma once

#include <GL/glew.h>
#include <glfw3.h>
#include <iostream>

namespace energy {
	namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class Window
		{
		private:
			const char* my_Title;	//window title
			int my_Width, my_Height;	//width and height of our window 
			bool my_Closed;				//checks to see if window has been closed
			GLFWwindow* my_Window;		//The window

			bool my_Keys[MAX_KEYS];
			bool my_MouseButtons[MAX_BUTTONS];
			double mx, my;


			bool init();
			
		public:

			Window(const char *title,int width,int height); //window constructor
			~Window();
			
			bool closed() const;
			void clear() const;
			void update() const;

			int getWidth() const;
			int getHeight() const;
			bool* getMyKeys();
			bool* getMyMouseButtons();
			double getMx();
			double getMy();

			void setMx(double x);
			void setMy(double y);


			bool isKeyPressed(unsigned int keycode);
			bool isMouseButtonPressed(unsigned int button);
			void getMousePosition(double& x,double& y);

			//friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			//friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			//friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		};

	}
}