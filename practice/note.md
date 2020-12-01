#### 预定义的宏查看
C++版本 ”__cplusplus“、 源文件信息的“FILE”“ LINE”“ DATE”，以及一些语言特性测试宏，比如“__cpp_decltype” “__cpp_decltype_auto” “__cpp_lib_make_unique”等。不过，与优化更密切相关的底层系统信息在 C++ 语言标准里没有定义，但编译器通常都会提供，预定义的宏，可以用 GCC 可以使用一条简单的命令查看：

`g++ -E -dM - < /dev/null`