#pragma once

// Pre-Compiled headers
#include <iostream>

// Debug headers
#ifdef _DEBUG
#define UR_print(x) std::cout << x << std::endl
#endif // _DEBUG

// Uranium-Engine headers

#include "Graphics/Display/Window.h"
#include "Graphics/Display/WindowModes.h"
#include "Graphics/Display/WindowProps.h"

#include "Core/Application.h"
#include "Core/EntryPoint.h"