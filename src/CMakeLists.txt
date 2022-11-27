add_executable(
    CppTemplate 
    main.cpp
)

target_link_libraries(
    CppTemplate
    ${CONAN_LIBS}
)
