#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "WindowModes.h"
#include "Input/Components/Monitor.h"

namespace Uranium::Graphics::Display {

	WindowModes::WindowModes() noexcept :
		glWindow(nullptr),

		visible(true),
		resizable(true),
		decorated(true),
		fullscreen(false),
		alwaysOnTop(false),

		maximized(false),
		minimized(false)
	{

	}

	void WindowModes::setVisible(bool visible) {
		this->visible = visible;
		if (not glWindow) return;

		if (visible)
			glfwShowWindow(glWindow);
		else
			glfwHideWindow(glWindow);
	}

	void WindowModes::setResizable(bool resizable) {
		this->resizable = resizable;
		if (glWindow) glfwSetWindowAttrib(glWindow, GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);
	}

	void WindowModes::setDecorated(bool decorated) {
		this->decorated = decorated;
		if (glWindow) glfwSetWindowAttrib(glWindow, GLFW_DECORATED, decorated ? GLFW_TRUE : GLFW_FALSE);
	}
	void WindowModes::setAlwaysOnTop(bool alwaysOnTop) {
		this->alwaysOnTop = alwaysOnTop;
		if (glWindow) glfwSetWindowAttrib(glWindow, GLFW_FLOATING, alwaysOnTop ? GLFW_TRUE : GLFW_FALSE);
	}

	void WindowModes:: restore() {
		maximized = false;
		minimized = false;
		if (glWindow == nullptr)
			return;

		Window& window = *static_cast<Window*>(glfwGetWindowUserPointer(glWindow));
		window.getCallback().setHasResized(true);

		if (not fullscreen) {
			glfwRestoreWindow(glWindow);
			return;
		}

		fullscreen = false;

		// Get the current position of the window
		// and keep track of the corresponding values
		int xpos;
		int ypos;
		glfwGetWindowPos(glWindow, &xpos, &ypos);

		// Update position without setting a new
		// position with glfw internally
		window.getProps().getPosition().x = xpos;
		window.getProps().getPosition().y = ypos;

		// return window to its default dimensions:
		glfwSetWindowMonitor(
			glWindow,
			nullptr,                                 // current active monitor
			xpos, ypos,                              // position of the extended window
			window.getProps().getDimension().width,  // width of the window
			window.getProps().getDimension().height, // height of the window
			GLFW_DONT_CARE                           // refreshrate in Hz
		);
	}

	void WindowModes:: maximize() {
		if (fullscreen)
			return;

		maximized = false;
		minimized = true;
		if (glWindow == nullptr)
			return;
		glfwIconifyWindow(glWindow);

		Window& window = *static_cast<Window*>(glfwGetWindowUserPointer(glWindow));
		window.getCallback().setHasResized(true);
	}

	void WindowModes:: minimize() {
		if (fullscreen)
			return;

		maximized = false;
		minimized = true;
		if (glWindow == nullptr)
			return;
		glfwIconifyWindow(glWindow);

		Window& window = *static_cast<Window*>(glfwGetWindowUserPointer(glWindow));
		window.getCallback().setHasResized(true);
	}
}