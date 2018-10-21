#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <QTypeInfo>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define min_s(a, b) (((a) < (b)) ? (a) : (b))

class  ringbuffer
{

public:

    ringbuffer(uint32_t capacity);
    uint32_t pop(void* buffer, uint32_t size);
    uint32_t push(void* buffer, uint32_t size);
    bool isEmpty();
    uint32_t getCapicity();
    void resize();
    uint32_t get_length();
    bool isFull();
    uint8_t pop();
    uint8_t get(uint32_t index);

private:

    void ring_init(uint32_t capacity);

    void*		 room;
    uint32_t     size;
    uint32_t	 max_size;
    uint32_t     in;
    uint32_t     out;
};

#endif // RINGBUFFER_H
