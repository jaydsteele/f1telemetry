cc_library(
    name = "capture_telemetry",
    srcs = ["capture_telemetry.cc"],
    hdrs = ["capture_telemetry.h"],
)

cc_binary(
    name = "f1capture",
    srcs = ["main.cc"],
    deps = [
        ":capture_telemetry",
        "//include:all",
    ],
)
