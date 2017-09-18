#include <iostream>
#include <thread>

enum {
	NUM_WORKERS = 5,
};

void worker_main(int workerNumber)
{
	std::cout << "I'm worker " << workerNumber << std::endl;
}

int main(int argc, char* argv[])
{
	std::thread threads[NUM_WORKERS];

	for (int i = 0; i < NUM_WORKERS; i++)
	{
		threads[i] = std::thread(worker_main, i);
	}

	// wait till all worker threads complete
	for (int i = 0; i < NUM_WORKERS; i++)
	{
		threads[i].join();
	}

	return 0;
}
