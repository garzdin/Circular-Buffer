//
//  main.c
//  Buffer
//
//  Created by Teodor Garzdin on 26.11.17.
//  Copyright © 2017 Teodor Garzdin. All rights reserved.
//

#include <stdio.h>
#include "buffer.h"

int main(int argc, const char * argv[]) {
    buffer_t buffer = buffer_init(4);
    buffer_push(&buffer, 'A');
    buffer_push(&buffer, 'T');
    buffer_push(&buffer, '+');
    buffer_result_t result1 = buffer_pop(&buffer);
    buffer_result_t result2 = buffer_pop(&buffer);
    buffer_result_t result3 = buffer_pop(&buffer);
    buffer_push(&buffer, '\r');
    buffer_push(&buffer, '\n');
    buffer_result_t result4 = buffer_pop(&buffer);
    buffer_result_t result5 = buffer_pop(&buffer);
    buffer_free(&buffer);
    printf("Hello, World!\n");
    return 0;
}
