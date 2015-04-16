/*
 * Jobs.h
 *
 *  Created on: Apr 9, 2015
 *      Author: Marcin Domagała
 */

#ifndef JOBS_H_
#define JOBS_H_

#include "Job.h"
#include <boost/thread/mutex.hpp>


namespace scheduler {

class Jobs {
	typedef typename std::vector<Job*>::iterator iterator;
public:
	Jobs();
	virtual ~Jobs();
	void add(Job* job);
	Job* popFirst();
	int getSize();
private:
	std::vector<Job*> jobs;
	boost::mutex guard;
};

} /* namespace scheduler */

#endif /* JOBS_H_ */
