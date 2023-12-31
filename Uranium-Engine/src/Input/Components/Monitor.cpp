#include <GLFW/glfw3.h>

#include "Monitor.h"

namespace Uranium::Input::Components {

	Monitor Monitor::getPrimary() {
		// Returns a new Monitor object containing
		// all data from the primary monitor
		return Monitor(glfwGetPrimaryMonitor());
	}

	std::vector<Monitor> Monitor::allConnected() {
		// Obtain the monitor count that GLFW provides
		int monitorCount;
		// Retrieve a C array from GLFW 
		// with the returned monitor count
		GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);

		// Store the monitors obtained by GLFW
		// into an std::vector
		std::vector<Monitor> connectedMonitors;
		for (int i = 0; i < monitorCount; i++)
			connectedMonitors.push_back(Monitor(monitors[i]));
		return connectedMonitors;
	}

	Monitor::Monitor(GLFWmonitor* monitor) :
		monitor(monitor),
		vidmode(nullptr)
	{
		if (monitor != nullptr)
			vidmode = glfwGetVideoMode(monitor);
	}

	Monitor::operator GLFWmonitor* () const {
		return monitor;
	}

	bool Monitor::isConnected() const {
		return monitor != nullptr;
	}

	void Monitor::getResolution(unsigned int* width, unsigned int* height) const {
		if (vidmode == nullptr) {
			*width = GLFW_DONT_CARE;
			*height = GLFW_DONT_CARE;
			return;
		}
		*width = vidmode->width;
		*height = vidmode->height;
	}

	int Monitor::getRefreshRate() const {
		if (vidmode == nullptr)
			return GLFW_DONT_CARE;
		return vidmode->refreshRate;
	}
}