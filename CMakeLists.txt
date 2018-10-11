# Minimum cmake version
cmake_minimum_required(VERSION 3.8)

# Project name
project(Sarvihh)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Load SFML libraries
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS graphics audio REQUIRED)

# Include all header files from the tree structure
include_directories(
	source/game 
	source/map 
	source/scenes
)

# Load map source files
set(MAP_SOURCES 
	source/map/Map.cpp 
	source/map/Map_Layer.cpp 
	source/map/Tile.cpp
)

# Load game source files
set(GAME_SOURCES 
	source/game/Game.cpp 
	source/game/Running_Game.cpp
	source/game/Scene.cpp
	source/game/Entity.cpp
)

# Load scenes
set(SCENE_SOURCES 
	source/scenes/Scene_Map.cpp 
	source/scenes/Scene_Menu.cpp 
)

# Load source files
set(SOURCES 
	Sarvihh.cpp 
	${MAP_SOURCES} 
	${SCENE_SOURCES} 
	${GAME_SOURCES}
)

# Create executable and link libraries
add_executable(Sarvihh ${SOURCES})
target_link_libraries(Sarvihh sfml-graphics sfml-audio sfml-system sfml-window)

# Copy resources
configure_file(
	media/graphics/Tileset.png
	media/graphics/Tileset.png
COPYONLY)

configure_file(
	media/graphics/Sarvihh.png
	media/graphics/Sarvihh.png
COPYONLY)