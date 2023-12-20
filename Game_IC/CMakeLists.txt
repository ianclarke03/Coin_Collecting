set(HEADER_FILES
	MyGame.h
)

set(SOURCE_FILES
	main.cpp
	MyGame.cpp
)

add_executable(Game_IC ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_IC Egg)

include_directories(../Egg/include)