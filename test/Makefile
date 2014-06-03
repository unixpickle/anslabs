all: build/test_raw build/test_cap

build/test_raw: build
	g++ -I ../include test_raw.cpp -o build/test_raw

build/test_cap: build
	g++ -I ../include test_cap.cpp -o build/test_cap

build:
	mkdir build

clean:
	rm -rf build
