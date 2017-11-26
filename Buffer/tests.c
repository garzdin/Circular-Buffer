//
//  tests.c
//  Buffer
//
//  Created by Teodor Garzdin on 26.11.17.
//  Copyright © 2017 Teodor Garzdin. All rights reserved.
//

#include <assert.h>
#include "buffer.h"

buffer_t buffer;

void setup() {
    buffer = buffer_init(2);
}

void run() {
    assert((&buffer)->head == 0);
    assert((&buffer)->tail == 0);
    assert((&buffer)->size == 2);
    
    buffer_push(&buffer, 'A');
    buffer_push(&buffer, 'T');
    buffer_push(&buffer, '+');
    
    buffer_result_t el_1 = buffer_pop(&buffer);
    buffer_result_t el_2 = buffer_pop(&buffer);
    buffer_result_t el_3 = buffer_pop(&buffer);
    
    assert((&el_1)->ret == BUFFER_SUCCESS);
    assert((&el_1)->data == (buffer_el_t) 'A');
    
    assert((&el_2)->ret == BUFFER_SUCCESS);
    assert((&el_2)->data == (buffer_el_t) 'T');
    
    assert((&el_3)->ret == BUFFER_SUCCESS);
    assert((&el_3)->data == (buffer_el_t) '+');
    
    buffer_push(&buffer, '\r');
    
    buffer_result_t el_4 = buffer_pop(&buffer);

    assert((&el_4)->ret == BUFFER_SUCCESS);
    assert((&el_4)->data == (buffer_el_t) '\r');
}

void test() {
    setup();
    run();
}
