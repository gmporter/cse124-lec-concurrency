#include <iostream>
#include <thread>
#include <mutex>

enum {
	NUM_WORKERS = 5,
};

std::mutex worker_mutex;

void worker_main(int workerNumber)
{
	std::lock_guard<std::mutex> guard(worker_mutex);
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
