cc_library(
	name = "greet_lib",
	srcs = ["greet.cpp"],
	hdrs = ["greet.h"],
)

cc_binary(
	name = "helloworld",
	srcs = ["HelloWorld.cpp"],
	deps = [":greet_lib",
			"//lib:weather_lib"],
)