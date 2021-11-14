

# 深さ優先探索-1
add_executable(GS_DFS_1
    main_gs_dfs_1.cpp
)
target_compile_features(GS_DFS_1 PRIVATE cxx_std_17)


# 幅優先探索-1
add_executable(GS_BFS_1
    main_gs_bfs_1.cpp
)
target_compile_features(GS_BFS_1 PRIVATE cxx_std_17)