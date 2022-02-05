
# 最短経路探索: ベルマン・フォード法
add_executable(GSP_BELMAN_FORD
    main_gsp_belman_ford.cpp
)
target_compile_features(GSP_BELMAN_FORD PRIVATE cxx_std_17)


# 最短経路検索: ダイクストラ法 O(|V|^2)
add_executable(GSP_DIJKSTRA_1
    main_gsp_dijkstra_1.cpp
)
target_compile_features(GSP_DIJKSTRA_1 PRIVATE cxx_std_17)

# 最短経路検索: ダイクストラ法 O(|E|log|V|)
add_executable(GSP_DIJKSTRA_2
    main_gsp_dijkstra_2.cpp
)
target_compile_features(GSP_DIJKSTRA_2 PRIVATE cxx_std_17)

