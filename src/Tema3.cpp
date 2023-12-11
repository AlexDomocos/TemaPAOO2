#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>


std::mutex consoleMutex;

class ParkingLot {
public:
    ParkingLot(int numSpaces) : spacesAvailable(numSpaces) {}

    void park(int carId) {
        std::unique_lock<std::mutex> lock(spaceMutex);
        cv.wait(lock, [this](){ return spacesAvailable > 0; });

        --spacesAvailable;
        
        {
            std::lock_guard<std::mutex> consoleLock(consoleMutex);
            std::cout << "Car " << carId << " has parked. Spaces left: " << spacesAvailable << std::endl;
        }        

        lock.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        lock.lock(); 
        ++spacesAvailable;
        cv.notify_one();

        {
            std::lock_guard<std::mutex> consoleLock(consoleMutex);
            std::cout << "Car " << carId << " is leaving. Spaces available: " << spacesAvailable << std::endl;
        }
    }

private:
    std::mutex spaceMutex;
    std::condition_variable cv;
    int spacesAvailable;
};

void carTask(int carId, ParkingLot& lot) {
    lot.park(carId);
}

int main() {
    const int numParkingSpaces = 3;
    ParkingLot parkingLot(numParkingSpaces);

    const int numCars = 5;
    std::vector<std::thread> cars;

    for (int i = 0; i < numCars; ++i) {
        cars.emplace_back(carTask, i, std::ref(parkingLot));
    }

    for (auto& car : cars) {
        car.join();
    }

    return 0;
}