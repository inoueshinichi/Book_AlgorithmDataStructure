

# ジャンプカエル問題
add_executable(DPFrogJump
    main_dp_frog_jump.cpp
)
target_compile_features(DPFrogJump PRIVATE cxx_std_17)


# ナップサック問題
add_executable(DPNapsack
    main_dp_napsack.cpp
)
target_compile_features(DPNapsack PRIVATE cxx_std_17)


# 編集距離問題
add_executable(DPEditDistance
    main_dp_edit_distance.cpp
)
target_compile_features(DPEditDistance PRIVATE cxx_std_17)
