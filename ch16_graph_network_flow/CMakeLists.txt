

# ネットワークフロー問題：　フォード・ファルカーソン法
add_executable(NETWORK_FLOW_FORDFULKERSON
    main_networkflow_fordfulkerson.cpp
)
target_compile_features(NETWORK_FLOW_FORDFULKERSON PRIVATE cxx_std_17)
