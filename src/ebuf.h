#ifndef __EBUF_H_
#define __EBUF_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/* Memory buffer descriptor */
struct ebuf {
	char *buf;   /* Buffer pointer */
	size_t len;  /* Data length. Data is located between offset 0 and len. */
	size_t size; /* Buffer size allocated by realloc(1). Must be >= len */
};

/*
 * Initialises an ebuf.
 * `initial_size` specifies the initial capacity of the ebuf.
 */
void ebuf_init(struct ebuf *ebuf, size_t initial_size);

/* Frees the space allocated for the ebuffer and resets the ebuf structure. */
void ebuf_free(struct ebuf *ebuf);

/*
 * Resizes an ebuf.
 *
 * If `new_size` is smaller than buffer's `len`, the
 * resize is not performed.
 */
void ebuf_resize(struct ebuf *ebuf, size_t new_size);

#endif
