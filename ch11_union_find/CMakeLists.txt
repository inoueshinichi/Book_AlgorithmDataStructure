

# Union Find
add_executable(UnionFind1
    main_uf_1.cpp
)
target_compile_features(UnionFind1 PRIVATE cxx_std_17)

# Union Find for グラフの連結成分数
add_executable(UnionFind_GetGroupOfGraph
    main_uf_get_group_of_graph.cpp
)
target_compile_features(UnionFind_GetGroupOfGraph PRIVATE cxx_std_17)