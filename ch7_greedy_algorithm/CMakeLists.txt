

# コインの最小枚数
add_executable(GAMinCoins
    main_ga_min_coins.cpp
)
target_compile_features(GAMinCoins PRIVATE cxx_std_17)


# 区間スケジューリング
add_executable(GAIntervalSchedule
    main_ga_interval_schedule.cpp
)
target_compile_features(GAIntervalSchedule PRIVATE cxx_std_17)

# マルチ配列
add_executable(GAMultiArray
    main_ga_multi_array.cpp
)
target_compile_features(GAMultiArray PRIVATE cxx_std_17)

