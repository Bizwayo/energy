#include "window.h"


namespace energy {
	namespace graphics {

		void windowResize(GLFWwindow* window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);


		Window::Window(const char* title, int width, int height) {
			my_Title = title;
			my_Width = width;
			my_Height = height;

			if (!init()) {
				glfwTerminate();

				for (int i = 0; i < MAX_KEYS;i++) {
					my_Keys[i] = false;
				}
				for (int i = 0; i < MAX_BUTTONS; i++) {
					my_MouseButtons[i] = false;
				}
			}
		}

		Window::~Window() {
			glfwTerminate();
		}

		int Window::getWidth() const { return my_Width; }
		int Window::getHeight() const { return my_Height; }
		bool* Window::getMyKeys(){ return my_Keys; }
		bool* Window::getMyMouseButtons(){ return my_MouseButtons; }
		double Window::getMx(){ return mx; }
		double Window::getMy(){ return my; }

		void Window::setMx(double x)  { mx = x; }
		void Window::setMy(double y)  { my = y; }

		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Init FAILED" << std::endl;
				return false;
			}
			my_Window = glfwCreateWindow(my_Width,my_Height,my_Title,NULL,NULL);
			if (!my_Window) {
				glfwTerminate();
				std::cout << "WINDOW FAILED" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(my_Window);
			glfwSetWindowUserPointer(my_Window,this);

			glfwSetWindowSizeCallback(my_Window, windowResize);

			glfwSetKeyCallback(my_Window, key_callback);
			glfwSetMouseButtonCallback(my_Window,mouse_button_callback);
			glfwSetCursorPosCallback(my_Window,cursor_position_callback);

			if (glewInit() != GLEW_OK) {
				std::cout << "GLEW NOT INITIALIZED" << std::endl;
				return false;
			}
			return true;
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(my_Window);
		}


		//CALLBACKS
		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			(*win).getMyKeys()[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			(*win).getMyMouseButtons()[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			(*win).setMx(xpos);
			(*win).setMy(ypos);
		}


		bool Window::isKeyPressed(unsigned int keycode) {
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return my_Keys[keycode];
		}


		bool Window::isMouseButtonPressed(unsigned int button) {
			if (button >= MAX_BUTTONS) {
				return false;
			}
			return my_MouseButtons[button];
		}

		void Window::getMousePosition(double& x, double& y) {
			x = mx;
			y = my;
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Window::update() const {
			glfwSwapBuffers(my_Window);
			//glfwGetFramebufferSize(my_Window, &my_Width, my_Height);
			glfwPollEvents();
		}


		


		



	}
}