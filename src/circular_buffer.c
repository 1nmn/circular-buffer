#include <stdlib.h>
#include "circular_buffer.h"

circular_buffer *cb_init(size_t capacity)
{
    circular_buffer *cb = malloc(sizeof(circular_buffer));
    if (!cb)
        return NULL;

    cb->buffer = malloc(capacity * sizeof(int));
    if (!cb->buffer)
    {
        free(cb);
        return NULL;
    }

    cb->capacity = capacity;
    cb->head = 0;
    cb->tail = 0;
    cb->full = false;

    return cb;
}

void cb_free(circular_buffer *cb)
{
    if (cb)
    {
        free(cb->buffer);
        free(cb);
    }
}

int cb_push(circular_buffer *cb, int val)
{
    if (!cb)
        return -1;

    cb->buffer[cb->head] = val;

    if (cb->full)
        cb->tail = (cb->tail + 1) % cb->capacity;

    cb->head = (cb->head + 1) % cb->capacity;
    cb->full = (cb->head == cb->tail);

    return 0;
}

int cb_pop(circular_buffer *cb, int *out)
{
    if (!cb || !out || cb_is_empty(cb))
        return -1;

    *out = cb->buffer[cb->tail];
    cb->full = false;
    cb->tail = (cb->tail + 1) % cb->capacity;

    return 0;
}

int cb_peek(circular_buffer *cb, int *out)
{
    if (!cb || !out || cb_is_empty(cb))
        return -1;

    *out = cb->buffer[cb->tail];

    return 0;
}

bool cb_is_empty(circular_buffer *cb)
{
    return (!cb->full && (cb->head == cb->tail));
}

bool cb_is_full(circular_buffer *cb)
{
    return cb->full;
}