#pragma once

#include <string>

extern struct GLFWwindow;

namespace Uranium::Graphics::Display {

	class WindowProps {
	public:
		/*
		* Minimun and maximum default dimensions
		* for a window when resizing and creation in pixels
		*/
		static constexpr unsigned int MIN_WIDTH = 320;
		static constexpr unsigned int MIN_HEIGHT = 180;

	public:
		/*
		* public methods
		*/
		void setGLVersion(unsigned int mayor, unsigned int minor);

		void setTitle(const std::string& title);

		void setOpacity(unsigned int opacity);
		void setPosition(int xPosition, int yPosition);
		void setDimension(unsigned int width, unsigned int height);
		void setResolution(unsigned int widthResolution, unsigned int heightResolution);

	public:
		/*
		* Public getters
		*/
		inline std::string getTitle() const;

		inline unsigned int getMayorGLVersion() const;
		inline unsigned int getMinorGLVersion() const;

		inline unsigned int getOpacity() const;

		void getPosition(int* xPosition, int* yPosition);
		void getDimension(unsigned int* width, unsigned int* height);
		void getResolution(unsigned int* widthResolution, unsigned int* heightResolution);

	private:
		/*
		* This constructor is set as
		* private because we dont want instances
		* of this class to be created outside the window object definition
		*/
		WindowProps() noexcept;

	private:
		/*
		* Private members
		*/
		unsigned int mayorGLVersion;
		unsigned int minorGLVersion;

		GLFWwindow* glWindow;

		std::string title;

		unsigned int opacity;

		int xPosition;
		int yPosition;

		unsigned int width;
		unsigned int height;
		
		unsigned int widthResolution;
		unsigned int heightResolution;
	};
}