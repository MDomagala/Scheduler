/*
 * Jobs.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Marcin Domagała
 */

#include "Jobs.h"

namespace scheduler {

Jobs::Jobs() : jobs(0) {}

Jobs::~Jobs() {
	for(iterator it = jobs.begin(); it != jobs.end() ; ++it) {
		delete (*it);
	}
	jobs.clear();
}

void Jobs::add(Job* job) {
	boost::mutex::scoped_lock lock(guard);
	if(jobs.empty()) {
		jobs.push_back(job);
	} else {
		for(iterator it = jobs.begin(); it != jobs.end() ; ++it) {
			if(Job::ORDER(job, (*it)) == (*it)) {
				jobs.insert(it, job);
				return;
			}
		}
		jobs.push_back(job);
	}
}

Job* Jobs::popFirst() {
	boost::mutex::scoped_lock lock;
	Job* job = *(jobs.begin());
	jobs.erase(jobs.begin());
	return job;
}

int Jobs::getSize(){
	return jobs.size();
}

} /* namespace scheduler */
