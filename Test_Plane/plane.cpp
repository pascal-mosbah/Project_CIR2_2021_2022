#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

class Plane;

void update_plane(Plane &plane, bool &stop_thread);

class Plane
{
    std::thread t;
    int x = 0;
    bool stop_thread = false;

public:
    Plane()
    {
        t = std::thread(update_plane, std::ref(*this), std::ref(stop_thread));
    }
    void update()
    {
        std::cout << x++ << std::endl;
    }

    ~Plane()
    {
        stop_thread = true;
        t.join();
        std::cout << "Thread was stopped" << std::endl;
    }
};

void update_plane(Plane &plane, bool &stop_thread)
{
    while (!stop_thread)
    {
        std::this_thread::sleep_for(3s);
        plane.update();
    }
}

int main()
{
    Plane plane;
    int a;
    std::cin >> a;
    return EXIT_SUCCESS;
}