add_executable(emulator
  Main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Emulator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/RegisterFile.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Memory.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Instruction.cpp
)

target_include_directories(emulator
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(emulator
  PRIVATE elf
)
