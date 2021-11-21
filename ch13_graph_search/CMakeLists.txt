

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


# 深さ優先探索-2
add_executable(GS_DFS_2
    main_gs_dfs_2.cpp
)
target_compile_features(GS_DFS_2 PRIVATE cxx_std_17)


# 幅優先探索-2
add_executable(GS_BFS_2
    main_gs_bfs_2.cpp
)
target_compile_features(GS_BFS_2 PRIVATE cxx_std_17)


# 深さ優先探索によるs-tパスの存在チェック
add_executable(GS_DFS_S-T_PATH
    main_gs_dfs_s-t_path.cpp
)
target_compile_features(GS_DFS_S-T_PATH PRIVATE cxx_std_17)


# 深さ優先探索による二部グラフの判定
add_executable(GS_DFS_BIPARTITE
    main_gs_bipartite_graph.cpp
)
target_compile_features(GS_DFS_BIPARTITE PRIVATE cxx_std_17)


# 深さ優先探索によるトポロジカルソート
add_executable(GS_DFS_TOPOLOGICAL_SORT
    main_gs_topological_sort.cpp
)
target_compile_features(GS_DFS_TOPOLOGICAL_SORT PRIVATE cxx_std_17)


# 根なし木を根付き木とみなしたときの、深さや部分木のサイズを計算する
add_executable(GS_BFS_SEARCH_NO_ROOT_TREE
    main_search_no_root_tree.cpp
)
target_compile_features(GS_BFS_SEARCH_NO_ROOT_TREE PRIVATE cxx_std_17)

