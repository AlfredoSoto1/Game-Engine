#include "Window.h"

namespace Uranium::Graphics::Display {

	Window::Window() noexcept {

	}

	Window::~Window() {

	}

	Window::operator GLFWwindow* () const {
		return nullptr;
	}

	inline bool Window::shouldClose() const {
		return false;
	}

	//auto Window::getModes() -> const WindowModes& const {
	//}

	//auto Window::getProps() -> const WindowProps& const {
	//}
}