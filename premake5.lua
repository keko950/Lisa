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
IncludeDir["GLAD"] = "Lisa/vendor/glad/include"
IncludeDir["IMGUI"] = "Lisa/vendor/imgui"

group "Dependencies"
include "Lisa/vendor/GLFW"
include "Lisa/vendor/glad"
include "Lisa/vendor/imgui"

group ""

startproject "Sandbox"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.IMGUI}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"GLAD",
		"IMGUI"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LS_PLATFORM_WINDOWS",
			"LS_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"IMGUI_IMPL_OPENGL_LOADER_GLAD"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LS_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LS_DIST"
		symbols "On"


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

	filter "configurations:Release"
		defines "LS_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LS_DIST"
		symbols "On"