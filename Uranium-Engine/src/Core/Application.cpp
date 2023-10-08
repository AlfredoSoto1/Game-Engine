#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Context.h"
#include "Application.h"

namespace Uranium::Core {
	Application* Application::appSingleton = nullptr;

	Application* Application::instance() {
		return appSingleton;
	}

	Application::Application() noexcept :
		exitRequested(false),
		activeContexts(0),
		arguments(),
		contexts()
	{
		if (appSingleton != nullptr)
			throw std::runtime_error("Instance of application already exist!");

		appSingleton = this;
	}

	Application::~Application() {
		contexts.clear();
		arguments.clear();
	}

	void Application::exit() {
		exitRequested = true;
	}

	void Application::addArgument(const std::string& arg) {
		// Add new arguments from terminal if any
		arguments.push_back(arg);
	}

	void Application::diagnosticErrors(int error, const char* description) {
		fprintf(stderr, "Error [%i]: %s\n", error, description);
	}

	void Application::run() {

		// For testing purposes, create a context and
		// increase the context count
		contexts.push_back(std::make_unique<Context>());
		activeContexts++;
		
		// Initialize GLFW
		if (glfwInit() == GLFW_FALSE)
			throw std::exception("GLFW could not initialize correctly.");

		// Set the custom error callback
		// to diagnostic any possible error in 
		// the lifetime of the glfw application
		glfwSetErrorCallback(&Application::diagnosticErrors);

		// Update the application in the main thread
		while (activeContexts != 0 && !exitRequested) {
			// Update glfw callbacks
			glfwPollEvents();
		}

		// Join all the contexts to end application
		for(const auto& context : contexts)
			context->endContext();

		// Terminate the GLFW application
		// after all contexts are ended correctly
		glfwTerminate();
	}
}