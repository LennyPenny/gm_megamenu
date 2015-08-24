solution "gmsv_megamenu"
	language		"C++"
	location		"project"
	targetdir		"bin"

	--
	-- Statically link the C-Runtime to reduce dependencies needed to run our module
	--
	flags "StaticRuntime"

	architecture "x86"

	configurations { "Release" }

	configuration "Release"
		flags		"symbols"	-- Generate debugging information
		optimize	"On"		-- Optimize the build output for size and speed

	project "gmsv_megamenu"
		kind	"SharedLib"
		include	"LuaInterface"

		files { "src/**.cpp", "src/**.h" }
