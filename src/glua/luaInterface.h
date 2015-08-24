#include "GarrysMod/Lua/Interface.h"
#include <cstddef>

typedef unsigned int uint;

struct ILuaCallback;
struct ILuaObject;
struct IThreadedCall;

struct string;

struct buff;


namespace GarrysMod {
	namespace Lua {

		class Interface {
		public:

			typedef std::ptrdiff_t Integer;
			typedef double Number;
			typedef int(*Function)(lua_State *L);
			typedef int Reference;

			lua_State *state;

			enum {
				CLIENT,
				SERVER,
				MENU,
				SETTABLE = 6,
				RUNSTRINGEX = 106//offset
			};

			static const char* Names[];

			static const char *GetName(int state_id) {
				return Names[state_id];
			}

			virtual int			Top(void) = 0;
			virtual void		Push(int iStackPos) = 0;
			virtual void		Pop(int iAmt = 1) = 0;
			virtual void		GetTable(int iStackPos) = 0;
			virtual void		GetField(int iStackPos, const char* strName) = 0;
			virtual void		SetField(int iStackPos, const char* strName) = 0;
			virtual void		CreateTable() = 0;
			virtual void		SetTable(int i) = 0;
			virtual void		SetMetaTable(int i) = 0;
			virtual bool		GetMetaTable(int i) = 0;
			virtual void		Call(int iArgs, int iResults) = 0;
			virtual int			PCall(int iArgs, int iResults, int iErrorFunc) = 0;
			virtual int			Equal(int iA, int iB) = 0;
			virtual int			RawEqual(int iA, int iB) = 0;
			virtual void		Insert(int iStackPos) = 0;
			virtual void		Remove(int iStackPos) = 0;
			virtual int			Next(int iStackPos) = 0;
			virtual void*		NewUserdata(unsigned int iSize) = 0;
			virtual void		ThrowError(const char* strError) = 0;
			virtual void		CheckType(int iStackPos, int iType) = 0;
			virtual void		ArgError(int iArgNum, const char* strMessage) = 0;
			virtual void		RawGet(int iStackPos) = 0;
			virtual void		RawSet(int iStackPos) = 0;
			virtual const char*	GetString(int iStackPos = -1, unsigned int* iOutLen = 0) = 0;
			virtual double		GetNumber(int iStackPos = -1) = 0;
			virtual bool		GetBool(int iStackPos = -1) = 0;
			virtual Function	GetCFunction(int iStackPos = -1) = 0;
			virtual void*		GetUserdata(int iStackPos = -1) = 0;
			virtual void		PushNil() = 0;
			virtual void		PushString(const char* val, unsigned int iLen = 0) = 0;
			virtual void		PushNumber(double val) = 0;
			virtual void		PushBool(bool val) = 0;
			virtual void		PushCFunction(Function val) = 0;
			virtual void		PushCClosure(Function val, int iVars) = 0;
			virtual void		PushUserdata(void*) = 0;
			virtual int			ReferenceCreate() = 0;
			virtual void		ReferenceFree(int i) = 0;
			virtual void		ReferencePush(int i) = 0;
			virtual void		PushSpecial(int iType) = 0;
			virtual bool		IsType(int iStackPos, int iType) = 0;
			virtual int			GetType(int iStackPos) = 0;
			virtual const char*	GetTypeName(int iType) = 0;
			virtual void		CreateMetaTableType(const char* strName, int iType) = 0;
			virtual const char*	CheckString(int iStackPos = -1) = 0;
			virtual double		CheckNumber(int iStackPos = -1) = 0;
			virtual double		ObjLen(int iStackPos = -1) = 0;
			virtual void* AddThreadedCall(IThreadedCall *) = 0;
			virtual void* Init(ILuaCallback *, bool) = 0;
			virtual void* Shutdown(void) = 0;
			virtual void* Cycle(void) = 0;
			virtual void* GetLuaState(void) = 0;
			virtual void* Global(void) = 0;
			virtual void* GetObject(int) = 0;
			virtual void* DELETE_ME_5437(int) = 0;
			virtual void* _DELETE_ME2466(int) = 0;
			virtual void* PushLuaObject(ILuaObject *) = 0;
			virtual void* PushLuaFunction(int(*)(lua_State *)) = 0;
			virtual void* LuaError(char  const*, int) = 0;
			virtual void* TypeError(char  const*, int) = 0;
			virtual void* CallInternal(int, int) = 0;
			virtual void* CallInternalNoReturns(int) = 0;
			virtual void* CallInternalGetBool(int) = 0;
			virtual void* CallInternalGetString(int) = 0;
			virtual void* CallInternalGet(int, ILuaObject *) = 0;
			virtual void* _DELETE_ME(ILuaObject *, void *) = 0;
			virtual void* NewGlobalTable(char  const*) = 0;
			virtual void* NewTemporaryObject(void) = 0;
			virtual void* isUserData(int) = 0;
			virtual void* GetMetaTableObject(char  const*, int) = 0;
			virtual void* GetMetaTableObject(int) = 0;
			virtual void* GetReturn(int) = 0;
			virtual void* IsServer(void) = 0;
			virtual void* IsClient(void) = 0;
			virtual void* IsDedicatedServer(void) = 0;
			virtual void* DestroyObject(ILuaObject *) = 0;
			virtual void* CreateObject(void) = 0;
			virtual void* SetMember(ILuaObject *, ILuaObject *, ILuaObject *) = 0;
			virtual void* GetNewTable(void) = 0;
			virtual void* SetMember(ILuaObject *, float) = 0;
			virtual void* SetMember(ILuaObject *, float, ILuaObject *) = 0;
			virtual void* SetMember(ILuaObject *, char  const*) = 0;
			virtual void* SetMember(ILuaObject *, char  const*, ILuaObject *) = 0;
			virtual void* SetIsServer(bool) = 0;
			virtual void* PushLong(long) = 0;
			virtual void* GetFlags(int) = 0;
			virtual void* FindOnObjectsMetaTable(int, int) = 0;
			virtual void* FindObjectOnTable(int, int) = 0;
			virtual void* SetMemberFast(ILuaObject *, int, int) = 0;
			virtual bool RunString(char  const* szFileName, char  const* szFolderName, char  const* szStringToRun, bool bRun, bool bShowErrors) = 0;
			virtual void* IsEqual(ILuaObject *, ILuaObject *) = 0;
			virtual void* Error(char const*) = 0;
			virtual void* GetStringOrError(int) = 0;
			virtual void* RunLuaModule(char const*) = 0;
			virtual void* FindAndRunScript(char const*, bool, bool, char  const*) = 0;
			virtual void* SetPathID(char const*) = 0;
			virtual void* GetPathID(void) = 0;
			virtual void* ErrorNoHalt(char  const*, ...) = 0;
			virtual void* Msg(char  const*, ...) = 0;
			virtual void* PushPath(char  const*) = 0;
			virtual void* PopPath(void) = 0;
			virtual void* GetPath(void) = 0;
			virtual void* GetColor(int) = 0;
			virtual void* PushColor(int, int, int, int) = 0;
			virtual void* GetStack(int, void *) = 0;
			virtual void* GetInfo(char  const*, void *) = 0;
			virtual void* GetLocal(void *, int) = 0;
			virtual void* GetUpvalue(int, int) = 0;
			virtual void* RunStringEx(char  const*, char  const*, char  const*, bool, bool, bool) = 0;
			virtual void* DELETE_ME1(char  const*, int) = 0;
			virtual void* GetDataString(int, void **) = 0;
			virtual void* ErrorFromLua(char  const*, ...) = 0;
			virtual void* GetCurrentLocation(void) = 0;
			virtual void* MsgColour(void*  const&, char  const*, ...) = 0;
			virtual void* SetState(lua_State *) = 0;
			virtual void* DELETE_ME2(void) = 0;
			virtual void* GetCurrentFile(string &) = 0;
			virtual void* CompileString(buff &, string const&) = 0;
			virtual void* ThreadLock(void) = 0;
			virtual void* ThreadUnlock(void) = 0;
			virtual void* CallFunctionProtected(int, int, bool) = 0;
			virtual void* Require(char  const*) = 0;
			virtual void* GetActualTypeName(int) = 0;
			virtual void* SetupInfiniteLoopProtection(void) = 0;
		};

	}
}
