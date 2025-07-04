workspace "UnderDogEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to the root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "UnderDog/vendor/GLFW/include"

include "UnderDog/vendor/GLFW"

project "UnderDog"
	location "UnderDog"
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir ("bin" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int" .. outputdir .. "/%{prj.name}")

	pchheader "udpch.h"
	pchsource "UnderDog/src/udpch.cpp"

	files
	{
		"UnderDog/src/**.h",
		"UnderDog/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"

		cppdialect "C++20"
		staticruntime "On"

		systemversion "latest"

		defines
		{
			"UD_PLATFORM_WINDOWS",
			"UD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin" .. outputdir .. "/Sandbox")
		}




	filter "configurations:Debug"
		buildoptions
		{
			"/MDd",
			"/utf-8"
		}
		defines "UD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		buildoptions
		{
			"/MD",
			"/utf-8"
		}
		defines "UD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		buildoptions 
		{
			"/MD",
			"/utf-8"
		}
		defines "UD_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int" .. outputdir .. "/%{prj.name}")
	files
	{
		"Sandbox/src/**.h",
		"Sandbox/src/**.cpp"
	}

	includedirs
	{
		"UnderDog/vendor/spdlog/include",
		"UnderDog/src"
	}

	links
	{
		"UnderDog"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"



		defines
		{
			"UD_PLATFORM_WINDOWS"
		}

		
	filter "configurations:Debug"
		buildoptions
		{
			"/MDd",
			"/utf-8"
		}
		defines "UD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		buildoptions
		{
			"/MD",
			"/utf-8"
		}
		defines "UD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		buildoptions
		{
			"/MD",
			"/utf-8"
		}
		defines "UD_DIST"
		optimize "On"
