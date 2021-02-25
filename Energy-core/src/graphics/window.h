#pragma once

namespace energy {
	namespace graphics {

		class Window
		{
		private:
			const char* my_Title;
			int my_Width, my_Height;
		public:
			Window(const char *title,int width,int height); //window constructor
			~Window();
			void update() const;
		};

	}
}