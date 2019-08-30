project "GLAD"
	kind "StaticLib"
	language "C"
	staticruntime "on"
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/*.c",
		"src/*.h",
		"include/glad/glad.h",
		"include/KHR/khrplatform.h"
	}

	includedirs
	{
		"include"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"
