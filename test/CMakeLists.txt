find_package(GTest REQUIRED)

file(GLOB EMULATOR_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../emulator/src/*.cpp)

add_executable(verifier verifier.cpp ${EMULATOR_SRC_FILES})

target_include_directories(verifier
  PRIVATE ${GTEST_INCLUDE_DIRS} 
          ${CMAKE_CURRENT_SOURCE_DIR}/../emulator/include/
)
target_link_libraries(verifier
  PRIVATE ${GTEST_LIBRARIES}
          pthread
)
