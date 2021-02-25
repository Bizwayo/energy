#include "src/graphics/window.h"

int main() {
	using namespace energy;
	using namespace graphics;

	int w = 500, h = 500;

	Window window("ENERGY",w,h);

	while (!window.closed()) {
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5,-0.5);
		glVertex2f(0.0, 0.5);
		glVertex2f(0.5, -0.5);
		glEnd();
		window.update();
	}
	return 0;
}

