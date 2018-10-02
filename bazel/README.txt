# tips and questions:
(1) because gtest is not build in bazel system, so create a gtest.BUILD for gtest to include it in our our project builded in bazel system;
    as a contrast, gflags is built in bazel system, so in our project no BUILD created for gflags;
(2) if external libraries are included, how to create the BUILD files (especially the relative paths)?