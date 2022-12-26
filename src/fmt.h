#ifndef FMT_H
#define FMT_H

#include <string>
#include <memory>

template <typename... Args>
std::string fmt(const std::string &format, Args... args) {
    std::size_t size = std::snprintf(nullptr, 0, format.c_str(), args...) + 1;

    std::unique_ptr<char[]> buf(new char[size]);

    std::snprintf(buf.get(), size, format.c_str(), args...);

    return std::string(buf.get(), buf.get() + size - 1);
}

#endif
