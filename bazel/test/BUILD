cc_test(
    name = "hello_test",
    srcs = ["hello_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = ["//lib:weather_lib",
            "@gtest//:main"
    ],
)