#pragma once
#include "window/window.h"
#include <memory>
class App{
public:
	void run();
private:
    std::unique_ptr<Window> main_window = std::make_unique<Window>();
};