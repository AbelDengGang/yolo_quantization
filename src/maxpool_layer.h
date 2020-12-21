#ifndef MAXPOOL_LAYER_H
#define MAXPOOL_LAYER_H

#include "image.h"
#include "cuda.h"
#include "layer.h"
#include "network.h"
#include "blas.h"
#include "assert.h"

typedef layer maxpool_layer;

image get_maxpool_image(maxpool_layer l);
maxpool_layer make_maxpool_layer(int batch, int h, int w, int c, int size, int stride, int padding, int layer_quant_flag, int quant_stop_flag, int close_quantization, int quant);
void resize_maxpool_layer(maxpool_layer *l, int w, int h);
void forward_maxpool_layer(const maxpool_layer l, network net);
void forward_maxpool_layer_quant(const maxpool_layer l, network net);
void backward_maxpool_layer(const maxpool_layer l, network net);

#ifdef GPU
void forward_maxpool_layer_gpu(maxpool_layer l, network net);
void backward_maxpool_layer_gpu(maxpool_layer l, network net);
#endif

#endif

