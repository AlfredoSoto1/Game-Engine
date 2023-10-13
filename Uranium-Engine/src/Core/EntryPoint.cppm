
import "Application.h";

using namespace Uranium::Core;

extern Application* createApplication();

void buildApplication(const Application& application, int argc, char* argv[]) {
	// Pass all the arguments from the terminal
	// to the application
	for (int i = 0; i < argc; i++)
		application.addArgument(argv[i]);

	// Run application
	//application->run();
}

/*
* Entry point definition
*/
auto main(int argc, char* argv[]) -> int {

	// Call the defined in client entry point
	// to launch the application
	Application* application = createApplication();

	buildApplication(*application, argc, argv);

	// Free all resources allocated by the application
	delete application;

	return 0;
}