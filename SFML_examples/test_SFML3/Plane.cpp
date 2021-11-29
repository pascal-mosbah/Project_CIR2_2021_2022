#include "Plane.hpp"


Plane::Plane(const float &radius, const float &init_angle, const float &altitude, const float &speed) : angle_(init_angle * M_PI / 180),
                                                                                                        radius_(radius),
                                                                                                        x_(radius * cos(init_angle) + x_center),
                                                                                                        y_(radius * sin(init_angle) + y_center),
                                                                                                        omega_(speed / radius),
                                                                                                        altitude_(altitude),
                                                                                                        initial_clock_(high_resolution_clock::now())
{
    //    std::cout << "Thread creation" << std::endl;
    initial_clock_ = high_resolution_clock::now();
    update();
    t_ = std::thread(update_plane, std::ref(*this), std::ref(stop_thread_));
}

void Plane::update()
{
    auto current_clock = high_resolution_clock::now();
    auto dt = (current_clock - initial_clock_).count() / 1e9;
    initial_clock_ = current_clock;
    angle_ -= omega_ * dt;
    x_ = (radius_ * cos(angle_)) + x_center;
    y_ = (radius_ * sin(angle_)) + y_center;
}

float Plane::get_x()
{
    return x_;
}

float Plane::get_y()
{
    return y_;
}

float Plane::get_angle()
{
    return angle_ * 180. / M_PI + initial_rotation;
}
Plane::~Plane()
{
    stop_thread_ = true;
    t_.join();
//    std::cout << "Thread was stopped" << std::endl;
}
;

void update_plane(Plane &plane, bool &stop_thread)
{
    while (!stop_thread)
    {
        std::this_thread::sleep_for(1s);
        plane.update();
    }
}
