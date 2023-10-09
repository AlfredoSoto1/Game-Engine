#pragma once

extern struct GLFWwindow;

namespace Uranium::Input::Components {
	extern class Monitor;
}

namespace Uranium::Graphics::Display {

	enum class WinMode {
		MAXIMIZED,
		MINIMIZED,

		VISIBLE,
		RESIZABLE,
		DECORATED,
		FULLSCREEN,
		ALLWAYS_ON_TOP
	};

	class WindowModes {
	public:
		/*
		* Custom alias
		*/
		using Monitor = Input::Components::Monitor;

	public:
		/*
		* Public setters
		*/
		void setVisible(bool visible);
		void setResizable(bool resizable);
		void setDecorated(bool decorated);
		void setAlwaysOnTop(bool alwaysOnTop);

		void setFullscreen(const Monitor& monitor);

	public:
		/*
		* Public modifiers
		*/
		void restore();
		void maximize();
		void minimize();

	private:
		/*
		* This constructor is set as
		* private because we dont want instances
		* of this class to be created outside the window object definition
		*/
		WindowModes() noexcept;

	private:
		/*
		* Private members
		*/
		GLFWwindow* glWindow;

		bool visible;
		bool resizable;
		bool decorated;
		bool fullscreen;
		bool alwaysOnTop;

		bool maximized;
		bool minimized;
	};
}