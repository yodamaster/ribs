/*
    This file is part of RIBS (Robust Infrastructure for Backend Systems).
    RIBS is an infrastructure for building great SaaS applications (but not
    limited to).

    Copyright (C) 2011 Adap.tv, Inc.

    RIBS is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, version 2.1 of the License.

    RIBS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with RIBS.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _ACCEPTOR__H_
#define _ACCEPTOR__H_

#include "basic_epoll_event.h"
#include "epoll_event_array.h"
#include "epoll.h"
#include "class_factory.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "vmpool.h"

struct acceptor : basic_epoll_event
{
    int init(int fd, int port, int listen_backlog, struct epoll_server_event_array *events);
           
    struct basic_epoll_event *on_accept();
    
    //void init_per_thread(vmpool_op<struct server_epoll_event> p);
    void init_per_thread();
    void noop() { }
    basic_epoll_event *callback_error() { abort(); return NULL; }
    
    struct basic_epoll_event_method_0args callback;
    struct basic_epoll_event_void_method_0args accept_callback;

    struct epoll_server_event_array *events;
    static __thread struct vmpool_op<struct server_epoll_event> pool;
};

#endif // _ACCEPTOR__H_
