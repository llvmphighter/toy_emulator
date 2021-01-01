file(GLOB EMULATOR_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../emulator/src/*.cpp)

add_executable(verifier verifier.cpp ${EMULATOR_SRC_FILES})

target_include_directories(verifier
   PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../emulator/include
           ${TOY_EMULATOR_DIR}/third-party/spdlog/include
           ${TOY_EMULATOR_DIR}/third-party/abseil-cpp
           ${TOY_EMULATOR_DIR}/third-party/googletest/googletest/include
)
target_link_libraries(verifier
   PRIVATE pthread
           absl::status
           gtest_main
)
