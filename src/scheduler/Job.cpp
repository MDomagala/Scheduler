/*
 * Job.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Marcin Domagała
 */

#include "Job.h"
#include <iostream>

namespace scheduler {

Job::Job(const asio::system_timer::time_point& tp, function<void (void)> f) : functor(f), timePoint(tp) {}

Job::~Job() {}

Job* Job::ORDER(Job* j1, Job* j2) {
	return j1->getTimePoint() >= j2->getTimePoint() ? j2 : j1;
}

void Job::callback() {
	try {
		functor();
	} catch (std::string& er){
		std::cout << er << std::endl;
	}
};

} /* namespace scheduler */
