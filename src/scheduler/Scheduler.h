/*
 * Scheduler.h
 *
 *  Created on: Apr 9, 2015
 *      Author: Marcin Domagała
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Job.h"
#include "Jobs.h"
#include "Timer.h"

namespace scheduler {

class Scheduler {
public:
	Scheduler(boost::asio::io_service& service);
	virtual ~Scheduler();
	void schedule(Job* job);
	void schedule(const asio::system_timer::time_point& tp, function<void (void)> f);
private:
	void insert(Job* job);
	void loop(const boost::system::error_code& ec);
	void start();

	Job* actualJob;
	Jobs jobs;
	Timer* timer;
};

} /* namespace scheduler */

#endif /* SCHEDULER_H_ */
