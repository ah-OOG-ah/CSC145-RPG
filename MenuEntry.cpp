#include "MenuEntry.h"
#include <functional>

MenuEntry::MenuEntry(std::string name, std::function<bool(void)> action) : name(name), action(action) { }
