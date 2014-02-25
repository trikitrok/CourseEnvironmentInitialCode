#include "Course.h"

#include "Environment.h"

using namespace boost::posix_time;

Course::Course(const std::string & name)
: name(name) {
  Environment environment;
  this->college = environment.getVariable("ENV_COLLEGE");
}

Course::~Course() {}

void Course::start() {
  this->startTime = microsec_clock::local_time();
}

void Course::end() {
  ptime endTime = microsec_clock::local_time();
  time_duration elapsed = endTime - startTime;
  duration = static_cast<int>(elapsed.total_microseconds() / 1000000.0);
}

std::string Course::getName() const {
  return this->name;
}

std::string Course::getCollege() const {
  return this->college;
}

int Course::getDurationInSeconds() const {
  return this->duration;
}

bool Course::isShort() const {
  return this->duration < 2 * SecondsPerMinute;
}

bool Course::isLong() const {
  return !isShort();
}