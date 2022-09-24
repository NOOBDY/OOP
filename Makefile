.PHONY: all
all: hello ut

hello: setup
	cmake --build build --target HelloWorld
	cp ./build/HelloWorld .

ut: setup
	cmake --build build --target ut_all
	cp ./build/ut_all .

setup:
	cmake -B build

.PHONY: clean
clean:
	rm -f HelloWorld
	rm -f ut_all
