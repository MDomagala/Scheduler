/*
 * Timer.h
 *
 *  Created on: Apr 9, 2015
 *      Author: Marcin Domagała
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <boost/chrono.hpp>
#include <boost/asio/system_timer.hpp>

namespace scheduler {

class Timer : public boost::asio::system_timer {
public:
	Timer(boost::asio::io_service& service);
	virtual ~Timer();
};

} /* namespace scheduler */

#endif /* TIMER_H_ */
