#include "unity.h"
#include "get_next_line.h"
#include <fcntl.h>

void	test_threelines_should_be_equal(void)
{
	int		fd = open("text/threelines", O_RDWR);
	char	*expected;
	char	*actual;

	expected = "Process 34258 launched:\n";
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = "\n";
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = "Process 34258 stopped\n";
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	close(fd);
}

void	test_41_with_nl_should_be_equal(void)
{
	int		fd = open("text/41_with_nl", O_RDWR);
	char	*expected;
	char	*actual;

	expected = "0123456789012345678901234567890123456789\n";
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = "0";
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	close(fd);
}

void	test_empty_should_be_equal(void)
{
	int		fd = open("text/empty", O_RDWR);
	char	*expected = NULL;

	char	*actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	close(fd);
}

void	test_no_newline_short_should_be_equal(void)
{
	int		fd = open("text/nonewline_short", O_RDWR);
	char	*expected = "01234567890123456789012345678901234567890";
	char	*actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	// free(actual);
	close(fd);
}

void	test_no_newline_long_should_be_equal(void)
{
	int		fd = open("text/nonewline_long", O_RDWR);
	char	*expected = "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";
	char	*actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	close(fd);
}

void	test_multiple_calls_should_be_equal(void)
{
	int		fd = open("text/41_with_nl", O_RDWR);
	char	*expected;
	char	*actual;

	expected = "0123456789012345678901234567890123456789\n";
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = "0";
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	close(fd);

	expected = NULL;
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	close(fd);

	expected = NULL;
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	close(fd);
}

void	test_multiple_calls_mixed_should_be_equal(void)
{
	int		fd = open("text/41_with_nl", O_RDWR);
	int		fd1 = open("text/41_with_nl", O_RDWR);
	int		fd2 = open("text/41_with_nl", O_RDWR);
	char	*expected;
	char	*actual;

	expected = "0123456789012345678901234567890123456789\n";
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = "0123456789012345678901234567890123456789\n";
	actual = get_next_line(fd1);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = "0";
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = "0123456789012345678901234567890123456789\n";
	actual = get_next_line(fd2);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = "0";
	actual = get_next_line(fd1);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd1);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = "0";
	actual = get_next_line(fd2);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd2);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd2);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);

	expected = NULL;
	actual = get_next_line(fd1);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);


	close(fd);
	close(fd1);
	close(fd2);
}

void	test_big_fd_should_be_equal(void)
{
	char	*expected;
	char	*actual;

	expected = NULL;
	actual = get_next_line(1050);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
}

int test_gnl(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_threelines_should_be_equal);
	RUN_TEST(test_empty_should_be_equal);
	// RUN_TEST(test_no_newline_short_should_be_equal);
	RUN_TEST(test_no_newline_long_should_be_equal);
	RUN_TEST(test_41_with_nl_should_be_equal);
	RUN_TEST(test_multiple_calls_should_be_equal);
	RUN_TEST(test_multiple_calls_mixed_should_be_equal);
	RUN_TEST(test_big_fd_should_be_equal);

	return UNITY_END();
}