set(HEADER_FILES

)

set(SOURCE_FILES
	main.cpp
)

add_executable(Game_IC ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_IC Egg)

include_directories(../Egg/include)