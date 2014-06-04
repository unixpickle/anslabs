FLAGS=-Wno-c++11-extensions

all: build/test_raw build/test_cap build/test_structor

build/test_raw: build
	g++ $(FLAGS) -I ../include test_raw.cpp -o build/test_raw

build/test_cap: build
	g++ $(FLAGS) -I ../include test_cap.cpp -o build/test_cap

build/test_structor: build
	g++ $(FLAGS) -I ../include test_structor.cpp -o build/test_structor

build:
	mkdir build

clean:
	rm -rf build
