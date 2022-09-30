.PHONY: all
all: ut

ut: setup
	cmake --build build --target ut_all
	cp ./build/ut_all .

setup:
	cmake -B build

.PHONY: clean
clean:
	rm -f HelloWorld
	rm -f ut_all
