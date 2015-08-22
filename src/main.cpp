#include "GarrysMod/Lua/Interface.h"

#include "glua/luaInterface.h"
#include "glua/shared.h"

#include "interface.h"
#include "vtable.h"

#define CREATELUAINTERFACE_INDEX	(4)
#define CLOSELUAINTERFACE_INFEX		(5)

using namespace GarrysMod;

Lua::Shared *luaShared = 0;
VTable *sharedHooker = 0;

Lua::Interface * __hook hCreateLuaInterface(Lua::Interface *_this, void *, char state, bool renew)
{
	typedef Lua::Interface *(__thiscall *hCreateLuaInterface)(Lua::Interface *_this, char state, bool renew);
	Lua::Interface *ret = hCreateLuaInterfaceFn(sharedHooker->getold(CREATELUAINTERFACE_INDEX))(_this, state, renew);

	return ret;
}

GMOD_MODULE_OPEN() {
	libsym_return code;
	luaShared = GetInterface<Lua::Shared *>("lua_shared", "LUASHARED003", &code);

	sharedHooker = new VTable(luaShared);

	sharedHooker->hook(CREATELUAINTERFACE_INDEX, (void *)&hCreateLuaInterface);

	return 0;
}
