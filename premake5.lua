-- require("netbeans")
-- require("cmake")
-- require("raw")

workspace("FuerzasElectricas")
    configurations({"Debug","Release"})
    platforms({"Windows","Linux"})
    location("build/%{_ACTION}")

    project("FuerzasElectricas")
        kind("ConsoleApp")
        language("C++")
        targetdir("bin/%{cfg.buildcfg}")
		objdir("obj")

        files({"include/**.h","src/**.cpp","src/**.c","**.lua"})

        includedirs ({
		    "include"
		})

        filter("configurations:Debug")
            defines({"DEBUG"})
            symbols("On")

        filter("configurations:Release")
            defines({"NDEBUG"})
            optimize("On")

        filter("platforms:Windows")
            defines({"WINDOWS"})
            system("windows")

        filter("platforms:Linux")
            system("linux")
            defines({"LINUX"})