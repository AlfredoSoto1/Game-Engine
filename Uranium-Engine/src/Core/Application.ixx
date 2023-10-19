
export module Uranium.Core.Application;

import <string>;
import <vector>; 
import <memory>; 

namespace Uranium::Core {

	extern class Context;

	class Application {
	public:
		/*
		* 
		*/
		static Application* instance();

	private:
		/*
		* Application singleton reference
		*/
		static Application* appSingleton;

		/*
		* Default method that logs any GL errors
		*/
		static void diagnosticErrors(int error, const char* description);

		/*
		* This gets called externally where the entry point is defined
		*/
		friend void buildApplication(int argc, char* argv[]);
		
	public:
		/*
		* Application main constructor.
		* This must not throw an exception since this
		* is all what it must start from the application.
		*/
		explicit Application() noexcept;

		virtual ~Application();
		
		/*
		* Delete all the moving/copying constructors
		* since we dont want the client to create a copy
		* of the Application itself.
		*/
		Application(Application&) = delete;
		Application(Application&&) = delete;
		Application(const Application&) = delete;
		Application(const Application&&) = delete;

	public:
		/*
		* Public modifiers
		*/
		void exit();

	private:
		/*
		* Friend with classes
		*/
		friend class EntryPoint;

	private:
		/*
		* Private modifiers
		*/
		void run();

		void addArgument(const std::string& arg);

	private:
		/*
		* Private members
		*/
		volatile bool exitRequested;
		volatile unsigned int activeContexts;

		std::vector<std::string> arguments;
		std::vector<std::unique_ptr<Context>> contexts;
	};
	
	extern void buildApplication(int argc, char* argv[]);
}
