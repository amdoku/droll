# Generic test that uses conan libs
add_executable(droll main.cpp)
target_link_libraries(
  droll
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)
