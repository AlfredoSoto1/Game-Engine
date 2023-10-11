
import "Application.h";

using namespace Uranium::Core;

extern Application* createApplication();

/*
* Entry point definition
*/
auto main(int argc, char* argv[]) -> int {

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

	return 0;
}