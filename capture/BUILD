cc_library(
    name = "udp_server",
    srcs = ["udp_server.cc"],
    hdrs = ["udp_server.h"],
)

cc_binary(
    name = "capture",
    srcs = ["main.cc"],
    deps = [
        ":udp_server",
        "//include:all",
    ],
)
