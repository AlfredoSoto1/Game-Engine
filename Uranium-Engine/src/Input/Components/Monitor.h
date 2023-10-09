#pragma once

#include <vector>

extern struct GLFWmonitor;
extern struct GLFWvidmode;

namespace Uranium::Input::Components {

	class Monitor {
	public:
		/*
		* 
		*/
		static Monitor getPrimary();

		static std::vector<Monitor> allConnected();

	public:
		// Delete the Monitor() constructor
		// since we dont want the client to
		// be creating hollow monitor objects
		Monitor() = delete;

		// Convert an instance to a
		// GLFWmonitor pointer
		operator GLFWmonitor* () const;

		// Returns true if the current
		// instance is connected.
		bool isConnected() const;

		// Returns the monitor refreshrate in hz
		int getRefreshRate() const;

		// Returns the resolution of
		// the connected monitor
		void getResolution(unsigned int* width, unsigned int* height) const;

	private:
		/*
		* private methods
		*/
		Monitor(GLFWmonitor* monitor);

	private:
		/*
		* private members
		*/
		GLFWmonitor* monitor;
		const GLFWvidmode* vidmode;
	};
}