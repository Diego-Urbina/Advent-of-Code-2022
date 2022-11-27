add_executable(
    CppTemplateTest
    main_test.cpp
)

target_link_libraries(
    CppTemplateTest
    ${CONAN_LIBS}
)

include(GoogleTest)
gtest_discover_tests(CppTemplateTest)
