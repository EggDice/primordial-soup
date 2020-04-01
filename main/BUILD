cc_binary(
    name = "soup",
    srcs = ["main.cpp"],
    linkopts = ["-lglut -lGL -lGLU"],
    deps = [
        "//render-system:render_system",
    ],
)

cc_test(
    name = "test",
    srcs = ["test-main.cpp"],
    linkopts = ["-lgtest -lpthread"],
    deps = [
        "//render-system:render_system",
        "//render-system:render_system_test",
    ],
)
