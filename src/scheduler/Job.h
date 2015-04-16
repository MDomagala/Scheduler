/*
 * Job.h
 *
 *  Created on: Apr 9, 2015
 *      Author: Marcin Domagała
 */

#ifndef JOB_H_
#define JOB_H_

#include <boost/asio.hpp>
#include <boost/asio/system_timer.hpp>
#include <chrono>
#include <boost/function.hpp>

using namespace boost;


namespace scheduler {

class Job {
public:
	static Job* ORDER(Job* j1, Job* j2);
	Job(const std::chrono::system_clock::time_point& tp, function<void (void)> f);
	const std::chrono::system_clock::time_point& getTimePoint() const {return timePoint;};
	void callback();
	virtual ~Job();
private:
	boost::function<void (void)> functor;
	std::chrono::system_clock::time_point timePoint;
};

} /* namespace scheduler */

#endif /* JOB_H_ */
