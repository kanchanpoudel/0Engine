#pragma once

#ifdef S00NYA_DLL_EXPORT
#define S00NYA_API __declspec(dllexport)
#elif S00NYA_DLL
#define S00NYA_API __declspec(dllimport)
#else
#define S00NYA_API
#endif

#define SetBIT(n, p) n | (0x001 << p)
#define GetBIT(n, p) n & (0x001 << p)

#define null 0

namespace s00nya
{
	typedef int					Integer;
	typedef signed char			Integer8;
	typedef short				Integer16;
	typedef int					Integer32;
	typedef long long			Integer64;

	typedef unsigned int		UInteger;
	typedef unsigned char		UInteger8;
	typedef unsigned short		UInteger16;
	typedef unsigned int		UInteger32;
	typedef unsigned long long	UInteger64;

	typedef signed char       	FInteger8;
	typedef int               	FInteger16;
	typedef int               	FInteger32;
	typedef long long         	FINteger64;
	typedef unsigned char     	FUInteger8;
	typedef unsigned int      	FUInteger16;
	typedef unsigned int      	FUInteger32;
	typedef unsigned long long	FUInteger64;

	typedef float				Float;
	typedef double				Double;
	typedef long double			LDouble;

	typedef char				Character;
	typedef wchar_t				WCharacter;
	typedef Character			Byte;
	typedef unsigned char		UCharacter;

	typedef bool				Boolean;
}