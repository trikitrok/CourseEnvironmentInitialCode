#include "Course.h"

#include <Windows.h>

Course::Course(const std::string & name)
: name(name) {

  // Setting college property
  const DWORD buffSize = 65535;
  static char buffer[buffSize];
  if (GetEnvironmentVariableA("ENV_COLLEGE", buffer, buffSize)) {
    this->college = std::string(buffer);
  } else {
    this->college = "";
  }
}

Course::~Course() {}

void Course::start() {
  this->startTime = clock();
}

void Course::end() {
  clock_t endTime = clock();
  this->duration = static_cast<int>((endTime - this->startTime) / CLOCKS_PER_SEC);
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
  const int twoMinutes = 2 * 60;
  return this->duration < twoMinutes;
}

bool Course::isLong() const {
  return !isShort();
}