// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: Gabriel Marcano, 2023

#ifndef SYSCALLS_INTERNAL_H_
#define SYSCALLS_INTERNAL_H_

#include <uart.h>
#include <am1815.h>
#include <asimple_littlefs.h>

/** Base polymorphic class for syscall implementations.
 *
 * This holds onto function pointers for the various system calls devices can
 * implement. Any unimplemented ones should be left as NULL.
 */
struct syscalls_base
{
	int (*open)(void *context, const char *name, int flags, int mode);
	int (*close)(void *context, int file);
	int (*read)(void *context, int file, char *ptr, int len);
	int (*write)(void *context, int file, char *ptr, int len);
	int (*lseek)(void *context, int file, int ptr, int dir);
	int (*gettimeofday)(void *context, struct timeval *ptimeval, void *ptimezone);
};

///{
/** The following functions are used to register devices with specific
 * syscalls. These are called internally by asimple.
 */
void syscalls_register_rtc(void *device);
void syscalls_register_stdin(void *device);
void syscalls_register_stdout(void *device);
void syscalls_register_stderr(void *device);
void syscalls_register_fs(void *device);

///}

#endif//SYSCALLS__INTERNAL_H_