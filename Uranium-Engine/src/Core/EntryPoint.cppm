
import Uranium.Core.Application;

using namespace Uranium::Core;

// Custom entry point defined outside of main Engine
extern Application* createApplication();

void Uranium::Core::buildApplication(int argc, char* argv[]) {
	
	// Call the defined in client entry point
	// to launch the application
	Application* application = createApplication();

	// Pass all the arguments from the terminal
	// to the application
	for (int i = 0; i < argc; i++)
		application->addArgument(argv[i]);

	// Run application
	//application->run();

	// Free all resources allocated by the application
	delete application;
}

/*
* Entry point definition
*/
auto main(int argc, char* argv[]) -> int {

	// Build the application
	Uranium::Core::buildApplication(argc, argv);

	// Exit success
	return 0;
}