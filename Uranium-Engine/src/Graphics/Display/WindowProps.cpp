#include <GLFW/glfw3.h>

#include "WindowProps.h"

namespace Uranium::Graphics::Display {

	WindowProps::WindowProps() noexcept :
		mayorGLVersion(3),
		minorGLVersion(3),

		glWindow(nullptr),

		title("Uranium-Engine"),

		opacity(100),
		xPosition(0),
		yPosition(0),
		width(MIN_WIDTH),
		height(MIN_HEIGHT),
		widthResolution(MIN_WIDTH),
		heightResolution(MIN_HEIGHT)
	{

	}

	void WindowProps::setGLVersion(unsigned int mayor, unsigned int minor) {
		this->mayorGLVersion = mayor;
		this->minorGLVersion = minor;
	}

	void WindowProps::setTitle(const std::string& title) {
		this->title = title;

		if (glWindow) glfwSetWindowTitle(glWindow, title.c_str());
	}

	void WindowProps::setOpacity(unsigned int opacity) {
		this->opacity = opacity;

		if (!glWindow || opacity == 100) return;

		glfwSetWindowAttrib(
			// Establish window attribute to be -> frame buffer
			glWindow, GLFW_TRANSPARENT_FRAMEBUFFER,
			// Tell the frame buffer to become transparent
			// if and only if the opacity is lower than 100%
			opacity < 100 ? GLFW_TRUE : GLFW_FALSE
		);

		// Set the opacity of the window to be in a scale of [0, 100]
		glfwSetWindowOpacity(glWindow, opacity / 100.0f);
	}

	void WindowProps::setPosition(int xPosition, int yPosition) {
		this->xPosition = xPosition;
		this->yPosition = yPosition;

		if (glWindow) glfwSetWindowPos(glWindow, xPosition, yPosition);
	}

	void WindowProps::setDimension(unsigned int width, unsigned int height) {
		this->width = width;
		this->height = height;

		if (!glWindow) glfwSetWindowSize(glWindow, width, height);
	}

	void WindowProps::setResolution(unsigned int widthResolution, unsigned int heightResolution) {
		this->widthResolution = widthResolution;
		this->heightResolution = heightResolution;
	}

	inline std::string WindowProps::getTitle() const {
		return title;
	}

	inline unsigned int WindowProps::getMayorGLVersion() const {
		return mayorGLVersion;
	}

	inline unsigned int WindowProps::getMinorGLVersion() const {
		return minorGLVersion;
	}

	inline unsigned int WindowProps::getOpacity() const {
		return opacity;
	}

	void WindowProps::getPosition(int* xPosition, int* yPosition) {
		*xPosition = this->xPosition;
		*yPosition = this->yPosition;
	}

	void WindowProps::getDimension(unsigned int* width, unsigned int* height) {
		*width = this->width;
		*height = this->height;
	}

	void WindowProps::getResolution(unsigned int* widthResolution, unsigned int* heightResolution) {
		*widthResolution = this->widthResolution;
		*heightResolution = this->heightResolution;
	}
}