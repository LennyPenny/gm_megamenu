#ifndef CONVENTIONS_H
#define CONVENTIONS_H

#ifndef _WIN32

#define __naked __attribute__ ((naked))

#ifndef __cdecl
#define __cdecl __attribute__((cdecl))
#endif //__cdecl

#ifndef __stdcall
#define __stdcall __attribute__((stdcall))
#endif //__stdcall

#ifndef __fastcall
#define __fastcall __attribute__((fastcall))
#endif //__fastcall

#ifndef __thiscall
#define __thiscall __attribute__((cdecl))
#endif //__thiscall


#ifndef _cdecl

#define _cdecl __attribute__((cdecl))
#define _stdcall __attribute__((stdcall))
#define _fastcall __attribute__((fastcall))
#define _thiscall __attribute__((cdecl))

#endif //_cdecl

#define __hook __cdecl
#define _hook __cdecl
#define HOOK_EDX(arg)

#else

#define __hook __fastcall

#define HOOK_EDX(arg) arg,

#define __naked __declspec(naked)

#endif


#endif // CONVENTIONS_H
