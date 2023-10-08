
#define UR_PLATFORM_WINDOWS

#include <iostream>
#include <Uranium.h>

class GameStarter : public Uranium::Core::Application {
public:
	explicit GameStarter() noexcept :
		Application()
	{
		
		// Create window and register it to the application

	}
	
	~GameStarter() {
		
	}

private:

};

Uranium::Core::Application* Uranium::Core::createApplication() {
	return new GameStarter();
}