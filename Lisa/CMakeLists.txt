file(GLOB LISA_SOURCES 
    "src/**/*.h"
    "src/**/*.cpp"
)

add_library(Lisa "${LISA_SOURCES}")
target_precompile_headers(Lisa PUBLIC src/lspch.h src/lspch.cpp)



target_include_directories(Lisa PUBLIC
                           "src"
                           )

add_subdirectory(vendor)

target_link_libraries(Lisa PUBLIC
                           glad 
                           glfw
                           glm
                           imgui
                           spdlog
                           )