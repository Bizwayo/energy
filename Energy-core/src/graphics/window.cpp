#include "window.h"

namespace energy {
	namespace graphics {

		void windowResize(GLFWwindow* window, int width, int height);

		Window::Window(const char* title, int width, int height) {
			my_Title = title;
			my_Width = width;
			my_Height = height;

			if (!init()) {
				glfwTerminate();
			}
		}

		Window::~Window() {
			glfwTerminate();
		}

		int Window::getWidth() const { return my_Width; }
		int Window::getHeight() const { return my_Height; }


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
			glfwSetWindowSizeCallback(my_Window, windowResize);

			if (glewInit() != GLEW_OK) {
				std::cout << "GLEW NOT INITIALIZED" << std::endl;
				return false;
			}
			return true;
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(my_Window);
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Window::update() const {
			glfwSwapBuffers(my_Window);
			//glfwGetFramebufferSize(my_Window, &my_Width, my_Height);
			glfwPollEvents();
		}

		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

	}
}