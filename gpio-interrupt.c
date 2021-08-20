#ifndef PICO_GPIO_INTERRUPT_H
#define PICO_GPIO_INTERRUPT_H
#include "pico/stdlib.h"
#include <stdlib.h>

typedef void (*handler)(void *argument);

typedef struct {
  void * argument;
  handler fn;
} closure_t;

closure_t handlers[28] = {NULL};

void handle_interupt(uint gpio, uint32_t events) {
  closure_t handler = handlers[gpio];
  handler.fn(handler.argument);
}

void listen(uint pin, int condition, handler fn, void *arg) {
  gpio_init(pin);
  gpio_pull_up(pin);
  gpio_set_irq_enabled_with_callback(pin, condition, true, handle_interupt);
  handlers[pin] = (closure_t){ arg, fn };
}

#endif
