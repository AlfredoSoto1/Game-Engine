#pragma once

#ifdef UR_PLATFORM_WINDOWS

// Declare the entry point for the application
namespace Uranium::Core {
	Core::Application* createApplication();
}

// This tells the compiler that there is an implementation of
// the "createApplication()" method somewhere in the client side
// of the application.
extern Uranium::Core::Application* Uranium::Core::createApplication();

namespace Uranium::Core {

	class Application;

	class EntryPoint {
	public:
		explicit EntryPoint(int argc, char* argv[]) {
			// Call the defined in client entry point
			// to launch the application
			application = createApplication();

			// Pass all the arguments from the terminal
			// to the application
			for (int i = 0; i < argc; i++)
				application->addArgument(argv[i]);

			// Run application
			//application->run();
		}

		~EntryPoint() {
			// Free all resources allocated by the application
			delete application;
		}

	private:
		Application* application;
	};
}

/*
* Entry point definition
*/
auto main(int argc, char* argv[]) -> int {

	using namespace Uranium::Core;

	// Create a new entrypoint
	EntryPoint entryPoint = EntryPoint(argc, argv);

	return 0; // Success
}

#endif // UR_PLATFORM_WINDOWS
