#include "GarrysMod/Lua/Interface.h"

#include "glua/luaInterface.h"
#include "glua/shared.h"

#include "conv.h"

#include "interface.h"
#include "vtable.h"

#define CREATELUAINTERFACE_INDEX	(5)
#define CLOSELUAINTERFACE_INFEX		(6)
#define LUA_SETTABLE_INDEX			(8)

using namespace GarrysMod;

Lua::Shared *luaShared = 0;
Lua::ILuaBase*  Menu = 0;

VTable *sharedHooker = 0;
VTable *interfaceHooker = 0;

void llprint(const char *toPrint) {
	Menu->PushSpecial(Lua::SPECIAL_GLOB);
		Menu->GetField(-1, "print");
		Menu->PushString(toPrint);
		Menu->Call(1, 0);
	Menu->Pop();
}

void __hook hlua_settable(Lua::Interface *_this, void*, int i) {
	llprint("hi");

	typedef void *(__thiscall *hlua_settableFn)(Lua::Interface *_this, int i);
	hlua_settableFn(interfaceHooker->getold(LUA_SETTABLE_INDEX))(_this, i);
}

Lua::Interface * __hook hCreateLuaInterface(Lua::Interface *_this, void *, unsigned char state, bool renew)
{
	typedef Lua::Interface *(__thiscall *hCreateLuaInterfaceFn)(Lua::Interface *_this, unsigned char state, bool renew);
	if (state != Lua::Interface::CLIENT)
		return hCreateLuaInterfaceFn(sharedHooker->getold(CREATELUAINTERFACE_INDEX))(_this, state, renew);

	interfaceHooker = new VTable(_this);
	interfaceHooker->hook(LUA_SETTABLE_INDEX, (void *)&hlua_settable);

	Lua::Interface *ret = hCreateLuaInterfaceFn(sharedHooker->getold(CREATELUAINTERFACE_INDEX))(_this, state, renew);

	return ret;
}



GMOD_MODULE_OPEN() {
	Menu = LUA;
	llprint("megamenu loaded");
	libsym_return code;
	luaShared = GetInterface<Lua::Shared *>("lua_shared", "LUASHARED003", &code);

	sharedHooker = new VTable(luaShared);

	sharedHooker->hook(CREATELUAINTERFACE_INDEX, (void *)&hCreateLuaInterface);

	return 0;
}
