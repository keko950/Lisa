workspace "Lisa"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Lisa/vendor/GLFW/include"

include "Lisa/vendor/GLFW"

project "Lisa"
	location "Lisa"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lspch.h"
	pchsource "Lisa/src/lspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LS_PLATFORM_WINDOWS",
			"LS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LS_DEBUG"
		symbols "On"
		buildoptions "MDd"

	filter "configurations:Release"
		defines "LS_RELEASE"
		symbols "On"
		buildoptions "MD"

	filter "configurations:Dist"
		defines "LS_DIST"
		symbols "On"
		buildoptions "MD"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Lisa/src",
		"Lisa/vendor/spdlog/include"
	}

	links
	{
		"Lisa"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LS_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "LS_DEBUG"
		symbols "On"
		buildoptions "MDd"

	filter "configurations:Release"
		defines "LS_RELEASE"
		symbols "On"
		buildoptions "MD"

	filter "configurations:Dist"
		defines "LS_DIST"
		symbols "On"
		buildoptions "MD"