
#define UR_PLATFORM_WINDOWS

#include <Uranium.h>;

using namespace Uranium;

class GameStarter : public Core::Application {
public:
	explicit GameStarter() noexcept :
		Application()
	{

		// Create window and register it to the application

		Graphics::Display::Window window;


	}

	~GameStarter() {

	}

private:

};

Core::Application* Core::createApplication() {
	return new GameStarter();
}
