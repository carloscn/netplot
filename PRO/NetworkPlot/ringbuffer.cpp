/**
 * \brief   This project about NETPLOT.
 *
 * \License  THIS FILE IS PART OF MULTIBEANS PROJECT;
 *           all of the files  - The core part of the project;
 *           THIS PROGRAM IS NOT FREE SOFTWARE, NEED MULTIBEANS ORG LIC;
 *           YOU SHOULD HAVE RECEIVED A COPY OF WTFPL LICENSE UTIL 5/1/2021
 *           OVER THE DATE, ALL FUNCTIONS WILL BE CLOSED. IF NOT, MULTIBEANS
 *           WILL TAKE APPROPRIATE MEASURES.
 *
 *                ________________     ___           _________________
 *               |    __    __    |   |   |         |______     ______|
 *               |   |  |  |  |   |   |   |                |   |
 *               |   |  |__|  |   |   |   |________        |   |
 *               |___|        |___|   |____________|       |___|
 *
 *                               MULTIBEANS ORG.
 *                     Homepage: http://www.mltbns.com/
 *
 *           * You can download the license on our Github. ->
 *           * -> https://github.com/lifimlt  <-
 *           * Copyright (c) 2018 Wei Haochen(Carlos Wei: # whc.mlt@qq.com).
 *           * Copyright (c) 2013-2018 MULTIBEANS ORG. http://www.mltbns.com/
 *
 *  \note    void.
 ****************************************************************************/
#include "ringbuffer.h"
#include "QDebug"
ringbuffer::ringbuffer(uint32_t capacity)
{
    this->ring_init(capacity);
}

void ringbuffer::ring_init(uint32_t capacity)
{
    this->room = (uint8_t*) malloc( sizeof(uint8_t) * capacity );
    this->max_size = capacity;
    this->out = 0;
    this->in = 0;
    qDebug() << this->get_length();
}

uint32_t ringbuffer::get_length()
{
    uint32_t length = 0;

    length = this->in - this->out;
    size = length;

    return size;
}

uint32_t ringbuffer::pop(void *buffer, uint32_t size)
{
    uint32_t length = 0;
    uint32_t calcu = 0;

    size = min_s(size, this->get_length());
    calcu = this->out & (this->size - 1);
    length = min_s(size, this->size - calcu);
    memcpy(buffer, this->room + calcu, length);
    memcpy(buffer, this->room, size - length);
    this->out += size;

    return size;
}

uint32_t ringbuffer::push(void *buffer, uint32_t size)
{
    uint32_t length = 0;

    size = min_s(size, this->size - this->in + this->out);
    length = min_s(size, this->size - (this->in & (this->size - 1)));
    memcpy(this->room + (this->in & (this->size - 1)), buffer, length);
    memcpy(this->room, buffer + length, size - length);
    this->in += size;

    return size;
}

bool ringbuffer::isEmpty()
{
    return (in - out) == 0;
}

bool ringbuffer::isFull()
{
    return in == (out-1);
}

uint8_t ringbuffer::pop()
{
    out += 1;
    return 0;
}

uint32_t ringbuffer::getCapicity()
{
    return max_size;
}

uint8_t ringbuffer::get(uint32_t index)
{
    return 0;
}

void ringbuffer::resize()
{

}
