/*
 * Copyright (c) 2017 Cyril Hrubis <chrubis@suse.cz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <sys/utsname.h>
#include "test.h"
#include "tst_kernel.h"

int tst_kernel_bits(void)
{
	struct utsname buf;
	int kernel_bits;

	if (uname(&buf))
		tst_brkm(TBROK | TERRNO, NULL, "uname()");

	kernel_bits = strstr(buf.machine, "64") ? 64 : 32;

	tst_resm(TINFO, "uname.machine=%s kernel is %ibit",
	         buf.machine, kernel_bits);

	return kernel_bits;
}
