#include <gmock/gmock.h>
#include "../src/Course.h"
#include <chrono>
#include <thread>

using namespace ::testing;

class ACourse : public Test {
protected:
  const std::string CourseName{"math"};
  Course * course;

  virtual void SetUp() {
    course = new Course(CourseName);
  }

  virtual void TearDown() {
    delete course;
  }
};

TEST_F(ACourse, IsCreated) {
  ASSERT_THAT(course->getName(), Eq(CourseName));
}

// Needs file src\data\environment.txt to contain a key ENV_COLLEGE environment 
// with value equal to the college, i.e. ENV_COLLEGE:Standford
TEST_F(ACourse, WhenCreatedInitializesCollegeProperty) {
  ASSERT_THAT(course->getCollege(), Eq("Stanford"));
}

TEST_F(ACourse, CanTellWhenItIsShort) {
  course->start();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  course->end();

  ASSERT_THAT(course->getDurationInSeconds(), Eq(2));
  ASSERT_TRUE(course->isShort());
}

TEST_F(ACourse, CanTellItIsLong) {
  course->start();
  std::this_thread::sleep_for(std::chrono::minutes(3));
  course->end();

  ASSERT_TRUE(course->isLong());
}
