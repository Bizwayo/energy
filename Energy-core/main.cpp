#include <glfw3.h>
#include <iostream>

int main() {
	if (!glfwInit())
		std::cout << "ERROR" << std::endl;
	else
		std::cout << "SUCCESS" << std::endl;
	return 0;
}

