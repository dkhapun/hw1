/*
 * mtmtest.h
 *
 *      Author: Strulovich
 *
 * This is a (very) basic testing framework for C++. This is similar to what
 * you've seen for C, but there are some differences. The main one is that a
 * test fails by throwing an AssertionError exception. This should be clear
 * once exceptions were taught.
 * Due to this, tests should now be functions with a void return type.
 * In addition, some extra macros were added or updated to work better with C++
 * features.
 */

#ifndef MTMTEST_H_
#define MTMTEST_H_

#include <iostream>
#include <sstream>
#include <string>

/**
 * Special exception class used for signaling a test failure.
 * This class does not extend any standard exception class in order to make
 * sure user code does not catch such an exception by mistake
 */
class AssertionError {
  int line;
  std::string file;
  std::string message;

public:
  /**
   * Initialize a new AssertionError with a line number, a file name
   * and a specialized message.
   */
  AssertionError(int line, std::string file, std::string message) : 
    line(line), 
    file(file), 
    message(message) {

  }

  /** Prints an assertion error's information about the test failure */
  friend std::ostream& operator<<(std::ostream& os,
      const AssertionError& error) {
    return os << error.file << ":" << error.line << " " << error.message;
  }
};

/** Testing macro for signaling a failure in the test */
#define FAIL(message) throw AssertionError(__LINE__, __FILE__, message);

/** Testing macro for defining specialized assertions */
#define ASSERT_WITH_MESSAGE(condition,message) do { \
    if (!(condition)) { \
      FAIL(message); \
    } \
  } while(0)

/** Assert that a boolean condition is true */
#define ASSERT_TRUE(condition) \
  ASSERT_WITH_MESSAGE(condition, "Condition is false: "#condition)

/** Assert that a boolean condition is false */
#define ASSERT_FALSE(condition) \
  ASSERT_WITH_MESSAGE(!(condition), "Condition is true: "#condition)

/**
 * Assert that that two values are equal. Values are compared with a call
 * to their == operator.
 */
#define ASSERT_EQUALS(expected,actual) \
  ASSERT_WITH_MESSAGE((expected) == (actual), "Values not equal")

/**
 * Assert that that two values are different. Values are compared with a call
 * to their == operator.
 */
#define ASSERT_NOT_EQUAL(expected,actual) \
  ASSERT_WITH_MESSAGE((expected) != (actual), "Values equal")

/**
 * Converts 'object' to string using operator<< and asserts that this string
 * is equal to the expected string
 */
#define ASSERT_PRINT(expected,object) do { \
  std::ostringstream os; \
  os << (object); \
  ASSERT_EQUALS(expected, os.str()); \
} while(0)

/** Asserts the distance between two floating values is smaller than epsilon */
#define ASSERT_DOUBLE_EQUALS(expected,actual,epsilon) \
  ASSERT_WITH_MESSAGE(((expected) + epsilon >= actual) && \
      ((expected) - epsilon <= actual ), "Values not equal")

/** Asserts that running the target command does not throw any exceptions */
#define ASSERT_NO_THROW(command) do {\
  try { \
    (command); \
  } catch (AssertionError&) { \
    throw; \
  } catch (std::exception& e) { \
    FAIL(std::string("Expected no exceptions, but caught") + e.what()); \
  } catch (...) { \
    FAIL(std::string("Expected no exceptions, but caught an unknown object"));\
  } \
} while (0)

/**
 * Asserts that running the target command throws an exception of type
 * 'exception_type'.
 */
#define ASSERT_THROWS(exception_type,command) do {\
  try { \
    (command); \
    FAIL(std::string("Expected exception of type ") + #exception_type); \
  } catch (AssertionError&) { \
    throw; \
  } catch (exception_type&) { \
    \
  } catch (std::exception& e) { \
    FAIL(std::string("Expected exception of type ") + #exception_type + \
        ", but caught" + e.what()); \
  } catch (...) { \
    FAIL(std::string("Expected exception of type ") + #exception_type + \
        ", but caught an unknown object"); \
  } \
} while (0)

/**
 * Runs a target test.
 * This macro receives the test function's name. The test function should take
 * no arguments and have a return value of type void.
 */
#define RUN_TEST(b) do {\
  try { \
    std::cerr <<  "Running " << #b << "... "; \
    b(); \
    std::cerr << "[OK]" << std::endl; \
  } catch (AssertionError& error) { \
    std::cerr << "Failed (" << error << ")" << std::endl; \
  } catch (std::exception& e) { \
    std::cerr << "Failed (Unexpected exception: " << e.what() << ")" \
      << std::endl; \
  } catch (...) { \
    std::cerr << "Failed (Unknown unexpected exception)" << std::endl; \
  } \
} while (0)

#endif /* MTMTEST_H_ */
