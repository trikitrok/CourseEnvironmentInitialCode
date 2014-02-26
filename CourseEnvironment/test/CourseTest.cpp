#include <gmock/gmock.h>
#include "../src/Course.h"
#include <Windows.h>

using namespace ::testing;

// Helpers declarations
void sleepMinutes(int minutes);
void sleepSeconds(int seconds);

// Fixture
class ACourse : public Test {
protected:
  Course * course;

  virtual void SetUp() {
    course = new Course("math");
  }

  virtual void TearDown() {
    delete course;
  }
};

TEST_F(ACourse, IsCreated) {
  ASSERT_THAT(course->getName(), Eq("math"));
}

// Needs environment variable ENV_COLLEGE with value Standford
TEST_F(ACourse, WhenCreatedInitializesCollegeProperty) {
  ASSERT_THAT(course->getCollege(), Eq("Stanford"));
}

TEST_F(ACourse, CanTellWhenItIsShort) {
  course->start();
  sleepSeconds(2);
  course->end();

  ASSERT_THAT(course->getDurationInSeconds(), Eq(2));
  ASSERT_TRUE(course->isShort());
}

TEST_F(ACourse, CanTellItIsLong) {
  course->start();
  sleepMinutes(3);
  course->end();

  ASSERT_TRUE(course->isLong());
}

// Helpers
void sleepMinutes(int minutes) {
  sleepSeconds(minutes * 60);
}

void sleepSeconds(int seconds) {
  Sleep(seconds * 1000);
}