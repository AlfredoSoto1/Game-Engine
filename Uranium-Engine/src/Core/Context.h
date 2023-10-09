#pragma once

#include <memory>
#include <thread>

namespace Uranium::Graphics::Display {
	extern class Window;
}

namespace Uranium::Core {

	class Context {
	public:
		/*
		* Custom alias
		*/
		using Window = Uranium::Graphics::Display::Window;

	public:
		explicit Context() noexcept;
		
		virtual ~Context();
		
		/*
		* Delete the move and copy constructor,
		* because we dont want more instances of
		* a context that must be unique.
		*/
		Context(Context&) = delete;
		Context(Context&&) = delete;
		Context(const Context&) = delete;
		Context(const Context&&) = delete;

	public:
		/*
		* Getters and Setters
		*/
		bool isActive();
		bool isExitRequested();

	public:
		/*
		* Public modifiers
		*/
		void exit();

		void endContext();

	private:
		/*
		* Private modifiers
		*/
		void startContext();

	private:
		/*
		* Private members
		*/
		bool contextActive;
		bool exitRequested;

		std::thread contextThread;

		std::unique_ptr<Window> window;
	};
}