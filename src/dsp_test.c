/**
 * Copyright (C) 2020 Tymphany, Inc.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stdbool.h>

#include "dsp_test.h"
#include <sys/ioctl.h>

static const struct backend_ops *backend_ops;

int main(int argc, char *argv[])
{
	unsigned int len;
	unsigned int addr;
	uint8_t cnt;
	uint8_t *buf;
	size_t buf_size;
	int ret;

	buf_size = 100;
	buf = malloc(buf_size);
	if (!buf)
		goto exit;
	backend_ops = &spi_backend_ops;
	if (backend_ops->open) {
	ret = backend_ops->open(argc, argv);
	if (ret)
	{
	printf("spi open error..\n");
	//goto exit;	
	exit(1);	
	}
	}
	printf("dsp %s\n", argv[0]);
	printf("dsp %s\n", argv[1]);
	printf("argc: %d\n", argc);

	if (argc >= 4) {
		addr = strtoul(argv[2], NULL, 0);
		len = strtoul(argv[3], NULL, 0);
		if (strcmp(argv[1], "w") == 0)
		{
			printf("dsp write: %.2x %d\n",addr,len);
			for(cnt=0;cnt<len;cnt++)
			{
				buf[cnt] = strtoul(argv[cnt+4], NULL, 0);
				printf("%.2x ",buf[cnt]); 
			}
			printf("\n");
			backend_ops->write(addr, len, buf);
		}
		else if (strcmp(argv[1], "r") == 0)
		{
			printf("dsp read: %.2x %d\n",addr,len);
			buf[20] =backend_ops->read(addr, len, buf);
			for(cnt=0;cnt<len;cnt++)
			{
			   printf("%.2x ",buf[cnt]);
			}
			printf("read:%.2x ",buf[20]);
			printf("\n");
		}
		else {
			printf("command parameters is invalide..\n");
			exit(0);
		}
	}
	exit:
	free(buf);
    return 0;
}


