#include "Context.h"

#include <iostream>

namespace Uranium::Core {

	Context::Context() noexcept :
		exitRequested(false),
		contextActive(false),
		contextThread(&Context::startContext, this)
	{
		std::cout << "Context Created" << std::endl;
	}

	Context::~Context() {
		std::cout << "Context Destroyed" << std::endl;
	}

	bool Context::isActive() {
		return contextActive;
	}

	bool Context::isExitRequested() {
		return exitRequested;
	}

	void Context::exit() {
		exitRequested = true;
	}

	void Context::endContext() {
		// Join the thread and update
		// contextActive flag to false to tell
		// the client that the context has ended
		contextThread.join();
		contextActive = false;
	}

	void Context::startContext() {
		// Context thread starts to be active
		// when the thread starts running
		contextActive = true;

		// Run context here

		for (int i = 0; i < 100000; i++) {
			std::cout << "Context running" << std::endl;
		}
	}
}