/*
 * Timer.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Marcin Domagała
 */

#include "Timer.h"

namespace scheduler {

Timer::Timer(boost::asio::io_service& service) : boost::asio::system_timer(service) {}

Timer::~Timer() {}

} /* namespace scheduler */
