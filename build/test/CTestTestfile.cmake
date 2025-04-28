# CMake generated Testfile for 
# Source directory: /home/fdachs/Coding/wfrp_sim/test
# Build directory: /home/fdachs/Coding/wfrp_sim/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/home/fdachs/Coding/wfrp_sim/build/test/die_tests[1]_include.cmake")
add_test([=[die_tests]=] "/home/fdachs/Coding/wfrp_sim/build/test/die_tests")
set_tests_properties([=[die_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/fdachs/Coding/wfrp_sim/test/CMakeLists.txt;39;add_test;/home/fdachs/Coding/wfrp_sim/test/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
