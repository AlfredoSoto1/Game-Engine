#pragma once

#include <thread>

namespace Uranium::Core {
	class Context {
	public:
		/*
		* Context constructor
		*/
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
	};
}