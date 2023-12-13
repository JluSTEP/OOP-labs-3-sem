#define _CRTDBG_MAP_ALLOC
#include <iostream>

using namespace std;

class MemoryLeakDetectorInitializer;

class MemoryLeakDetector {
public:
	friend MemoryLeakDetectorInitializer;
	static MemoryLeakDetector* getInstance() {
		if (instance == nullptr) {
			instance = new MemoryLeakDetector();
		}
		return instance;
	}
	void dumpMemoryLeaks() {
		_CrtDumpMemoryLeaks();
	}

private:
	static MemoryLeakDetector* instance;

	MemoryLeakDetector() {};
	~MemoryLeakDetector() {};

};

MemoryLeakDetector* MemoryLeakDetector::instance = nullptr;
MemoryLeakDetector* leakDetector = nullptr;

class MemoryLeakDetectorInitializer {
public:
	MemoryLeakDetectorInitializer() {
		leakDetector = MemoryLeakDetector::getInstance();
	}
	~MemoryLeakDetectorInitializer() {
		delete leakDetector;
	}
};

MemoryLeakDetectorInitializer leakDetectorInitializer;

int main() {
	std::cout << "Hello World!\n";

	int* utechka = new int[999999999];
	//утечка памяти

	leakDetector->dumpMemoryLeaks(); 

	return 0;
}
