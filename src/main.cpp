#include "GarrysMod/Lua/Interface.h"

#include "interface.h"
#include "vtable.h"

using namespace GarrysMod;

int Example(lua_State *state) {
	LUA->PushString("Hello from Example()!");

	return 1;
}

void *luaShared = 0;

GMOD_MODULE_OPEN() {
	libsym_return code;
	luaShared = GetInterface<void *>("lua_shared", "LUASHARED003", &code);


	return 0;
}
