workspace "Lisa"
	architecture "x64"
	startproject "Sandbox"
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
IncludeDir["GLM"] = "Lisa/vendor/glm"

group "Dependencies"
include "Lisa/vendor/GLFW"
include "Lisa/vendor/glad"
include "Lisa/vendor/imgui"

group ""

project "Lisa"
	location "Lisa"
	kind "StaticLib"
	language "C++"
	staticruntime "On"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lspch.h"
	pchsource "Lisa/src/lspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.IMGUI}",
		"%{IncludeDir.GLM}"
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
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "LS_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "LS_DIST"
		runtime "Release"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Lisa/vendor/spdlog/include",
		"%{IncludeDir.glm}",
		"Lisa/vendor"
	}

	links
	{
		"Lisa"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"LS_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "LS_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines "LS_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "LS_DIST"
		runtime "Release"
		symbols "On"