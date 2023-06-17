#ifndef _THREADS_LIST_H
#define _THREADS_LIST_H
#include "matrix_thread.h"
#include "../src/CSAL_SHARED/event_management.hpp"

#define INIT_THREAD_LIST                                                                                                \
    (task_init_descriptor_t[]){                                                                                         \
        {event_management_thread, event_management_init, "Event Management Thread", 2048, NULL, 0, NULL},               \
        {matrix_thread, matrix_thread_init, "IPC Publish thread", 8192, NULL, 0, NULL},                              \
    }                                                                                                                   \

extern int NUM_THREADS;
#endif