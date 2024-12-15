cmake_minimum_required(VERSION 3.30)
project(cpp_test_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        cpp_test_project unordered_map.cpp
        binary_tree_search/binary_tree_ex.cpp
        binary_tree_search/test_test.cpp bts.cpp
        overloading_operators.cpp
        namespace_example.cpp
        virtual_casting_typeid.cpp
        custom_smart_pointer.cpp
        for_each_ex.cpp
        smart_pointer_ex.cpp
        multithreads_and_atomic_ex.cpp
        vtable_ex.cpp
        test_dir/myheaderfile.h
        test_dir/myheaderfile.cpp
        main_for_compiler.cpp
        rules_of_5_ex.cpp
        multiple_inherits_ex.cpp
        exception_ex.cpp
        rhombus_inheritance_ex.cpp
        access_violation_ex.cpp
        cast_ex.cpp
        undefined_behavior.cpp
        iostream/fstream_ex.cpp
        binary_fstream.cpp
        iostream/write_read_object_to_file.cpp
        iostream/write_read_file-ex.cpp
        iostream/fstream_ex.cpp
        test_fstream.cpp
        enum_ex.cpp
        class_template.cpp
        forward_list_ex.cpp
        forward_list_test_ex.cpp
        forward_list_test_ex2.cpp
        macros_ex.cpp
        my_class.cpp
        sorting_ex.cpp
        std_algorithm_ex.cpp
        std_function.cpp
        System.cpp
        lock_guard_mtx_ex.cpp
        functor_ex.cpp
        main.cpp
        mutex_ex.cpp
        time_execute_function.cpp
        dead_lock_ex.cpp
        binary_tree_and_list_ex_2.cpp
        binary_tree_and_list_ex.cpp
)
