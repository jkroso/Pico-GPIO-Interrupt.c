#ifndef PICO_GPIO_INTERRUPT_H
#define PICO_GPIO_INTERRUPT_H

typedef void (*handler)(void *argument);

typedef struct {
  void * argument;
  handler fn;
} closure_t;

void handle_interupt(uint gpio, uint32_t events);
void listen(uint pin, int condition, handler fn, void *arg);

#endif
