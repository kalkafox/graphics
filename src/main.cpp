#include <memory>
#include "app.h"

int main(){
	std::unique_ptr<App> a = std::make_unique<App>();
	a->run();
}
