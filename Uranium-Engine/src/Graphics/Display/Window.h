#pragma once

extern struct GLFWwindow;

namespace Uranium::Graphics::Display {
	
	extern class WindowModes;
	extern class WindowProps;

	class Window {
	public:
		/*
		* Window constructor
		*/
		explicit Window() noexcept;
		
		~Window();

	public:
		/*
		* Public Getters & Setters
		*/
		operator GLFWwindow* () const;

		inline bool shouldClose() const;

		auto getModes() -> const WindowModes& const;
		auto getProps() -> const WindowProps& const;

	public:
		/*
		* Public modifiers
		*/

	private:
		/*
		* Private modifiers
		*/

	};
}