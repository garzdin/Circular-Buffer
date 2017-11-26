# Circular-Buffer
A circular buffer implemented in C

# API

## Structures
```c
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
 ```

## Functions
```c
  buffer_t buffer_init(int size);
  buffer_state_t buffer_state(buffer_t *buffer);
  buffer_return_t buffer_push(buffer_t *buffer, buffer_el_t data);
  buffer_result_t buffer_pop(buffer_t *buffer);
  buffer_return_t buffer_free(buffer_t *buffer);
```

## Example
```c
  buffer_t buffer = buffer_init(8);
  
  buffer_return_t el_1_p = buffer_push(&buffer, 'A');
  assert(el_1_p == BUFFER_SUCCESS);
  
  buffer_result_t el_1 = buffer_pop(&buffer);
  assert((&el_1)->ret == BUFFER_SUCCESS);
  assert((&el_1)->data == (buffer_el_t) 'A');
```
