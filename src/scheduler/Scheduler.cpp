/*
 * Scheduler.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Marcin Domagała
 */

#include "Scheduler.h"
#include <boost/bind.hpp>
#include <boost/chrono.hpp>
//#include <boost/asio.hpp>
#include <chrono>

using namespace boost::chrono;

namespace scheduler {

Scheduler::Scheduler(boost::asio::io_service& service) : actualJob(nullptr), jobs() {
	timer = new Timer(service);
}

Scheduler::~Scheduler() {}

void Scheduler::schedule(Job* job) {
	insert(job);
}

void Scheduler::schedule(const std::chrono::system_clock::time_point& tp, function<void (void)> f) {
	Job* tmp = new Job(tp, f);
	insert(tmp);
}

void Scheduler::start() {
	if(actualJob) {
		timer->expires_at(actualJob->getTimePoint());
		timer->async_wait(boost::bind(&Scheduler::loop, this, _1));
	}
}

void Scheduler::insert(Job* job) {
	if(!actualJob) {
		actualJob = job;
		start();
	} else {
		if(Job::ORDER(actualJob, job) == actualJob) {
			jobs.add(actualJob);
			actualJob = job;
			timer->cancel();
		} else {
			jobs.add(job);
		}
	}
}

void Scheduler::loop(const boost::system::error_code& ec) {
	if (ec == boost::asio::error::operation_aborted) {
	    start();
	    return;
	}
	if (ec == boost::asio::error::interrupted) {
		std::cout << "run | WARNING: timer interrupted: " << ec << ", " << ec.message() << std::endl;
	    return;
	}
	if (ec) {
		std::cout << "run | ERROR: " << ec << ", " << ec.message() << std::endl;
		return;
	}
	if (actualJob) {
		actualJob->callback();
		delete actualJob;
	}
	if(jobs.getSize()) {
		actualJob = jobs.popFirst();
		start();
	}
}

} /* namespace scheduler */
