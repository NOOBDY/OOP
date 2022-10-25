FROM --platform=linux/amd64 ubuntu:latest
RUN apt update && apt install -y git build-essential cmake ninja-build valgrind
WORKDIR /opt/app/
CMD cmake -B $PWD/build -G Ninja -DCMAKE_BUILD_TYPE=Debug; \
    cmake --build $PWD/build; \
    valgrind --leak-check=yes --track-origins=yes -s $PWD/build/ut_all --gtest_color=yes