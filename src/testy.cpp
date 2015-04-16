//============================================================================
// Name        : testy.cpp
// Author      : mmmm
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <functional>
#include <boost/asio.hpp>

#include <chrono>
#include <boost/chrono.hpp>
#include <boost/asio/system_timer.hpp>
#include <boost/bind.hpp>

#include "scheduler/Scheduler.h"
#include "scheduler/Timer.h"

using namespace boost::chrono;


void prnt() {
	std::cout << "Done" << std::endl;
	std::cout << "C" << time_point_cast<seconds, steady_clock, nanoseconds>(steady_clock::now()) <<  '\n';
}

int main() {

	boost::asio::io_service s;
	scheduler::Scheduler sch(s);

	std::cout << "A " << time_point_cast<seconds, steady_clock, nanoseconds>(steady_clock::now()) <<  '\n';

	sch.schedule(std::chrono::system_clock::now() + std::chrono::seconds(5), boost::bind(prnt));
	sch.schedule(std::chrono::system_clock::now() + std::chrono::seconds(9), boost::bind(prnt));
	sch.schedule(std::chrono::system_clock::now() + std::chrono::seconds(3), boost::bind(prnt));
	sch.schedule(std::chrono::system_clock::now() + std::chrono::seconds(2), boost::bind(prnt));
	sch.schedule(std::chrono::system_clock::now() + std::chrono::seconds(5), boost::bind(prnt));
//	timer.expires_from_now(std::chrono::seconds(5));
//	timer.expires_at(std::chrono::system_clock::now() + std::chrono::seconds(5));
//	timer.wait();
	s.run();
//	mtd();

}

