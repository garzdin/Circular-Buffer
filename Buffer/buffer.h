//
//  buffer.h
//  Buffer
//
//  Created by Teodor Garzdin on 26.11.17.
//  Copyright © 2017 Teodor Garzdin. All rights reserved.
//

#ifndef buffer_h
#define buffer_h

#include <stdlib.h>
#include <stdio.h>

#define BUFFER_DEFAULT_SIZE 8

typedef uint8_t buffer_el_t;

typedef enum {
    UNKNOWN,
    BUFFER_EMPTY,
    BUFFER_FULL,
    BUFFER_READ,
} buffer_state_t;

typedef enum {
    BUFFER_ERROR,
    BUFFER_SUCCESS
} buffer_return_t;

typedef struct {
    int head;
    int tail;
    uint8_t *data;
    int size;
} buffer_t;

typedef struct {
    buffer_el_t data;
    buffer_return_t ret;
} buffer_result_t;

buffer_t buffer_init(int size);
buffer_state_t buffer_state(buffer_t *buffer);
buffer_return_t buffer_push(buffer_t *buffer, buffer_el_t data);
buffer_result_t buffer_pop(buffer_t *buffer);
buffer_return_t buffer_free(buffer_t *buffer);

#endif /* buffer_h */
