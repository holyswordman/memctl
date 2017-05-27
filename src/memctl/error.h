#ifndef MEMCTL_CLI__ERROR_H_
#define MEMCTL_CLI__ERROR_H_

#include "memctl/memctl_error.h"

/*
 * Description:
 * 	Error codes for the memctl tool.
 */
enum {
	message_error   = 128,
	usage_error     = 129,
	execve_error    = 130,
};

/*
 * error_message
 */
void error_message(const char *format, ...);

/*
 * usage_error
 */
struct usage_error {
	const char *command;
	const char *option;
	const char *message;
};

void error_usage(const char *command, const char *option, const char *format, ...);

/*
 * execve_error
 */
struct execve_error {
	const char *path;
	const char *reason;
};

void error_execve(const char *path, const char *error);

/*
 * print_errors
 *
 * Description:
 * 	Print out any error messages in the error stack and then clear the stack.
 */
void print_errors(void);

#endif