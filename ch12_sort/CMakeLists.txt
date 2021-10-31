

# 挿入ソート
add_executable(InsertionSort
    main_insertion_sort.cpp
)
target_compile_features(InsertionSort PRIVATE cxx_std_17)


# マージソート
add_executable(MergeSort
    main_merge_sort.cpp
)
target_compile_features(MergeSort PRIVATE cxx_std_17)


# クイックソート
add_executable(QuickSort
    main_quick_sort.cpp
)
target_compile_features(QuickSort PRIVATE cxx_std_17)


# ヒープソート
add_executable(HeapSort
    main_heap_sort.cpp
)
target_compile_features(HeapSort PRIVATE cxx_std_17)