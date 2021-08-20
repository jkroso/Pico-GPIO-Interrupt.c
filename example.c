#include "gpio-interrupt.c"
#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>

uint8_t ANYEDGE = GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL;

void example(void * p) {
  printf("interrupt called with %i\n", (int *)p);
}

int main() {
  stdio_init_all();
  puts("Start");
  listen(21, ANYEDGE, example, NULL);
  while (true) tight_loop_contents();
  return 0;
}
