#include "src/graphics/window.h"

int main() {
	using namespace energy;
	using namespace graphics;

	int w = 500, h = 500;

	Window window("ENERGY",w,h);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed()) {
		window.clear();
#if 1
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5,-0.5);
		glVertex2f(0.0, 0.5);
		glVertex2f(0.5, -0.5);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER,0,1);
#endif
		window.update();
	}
	return 0;
}

