# - Declare the build of the statics MPAGSCipher library
add_library(MPAGSCipher STATIC
  CipherMode.hpp
  CaesarCipher.cpp
  CaesarCipher.hpp
  ProcessCommandLine.cpp
  ProcessCommandLine.hpp
  TransformChar.cpp
  TransformChar.hpp
  )
  
target_include_directories(MPAGSCipher
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}
  )

target_compile_features(MPAGSCipher
  PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization
  )