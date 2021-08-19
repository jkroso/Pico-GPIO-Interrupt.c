# pico-gpio-interrupt.c

## Installation

Install with [clib(1)](https://github.com/clibs/clib):

```sh
$ clib install jkroso/pico-gpio-interrupt.c
```

## Api

The API consists of one function: `listen(pin, condition, fn, argument)` and its very similar to `gpio_set_irq_enabled_with_callback` except it removes the `enabled` argument and adds `argument` which is a pointer that will be passed to your `fn` every time an interrupt event occurs.

## Example

```c
#include "./deps/pico-gpio-interrupt/gpio-interrupt.c"

void example(void * p) {
  printf("interrupt called with %i\n", (int *)p);
}

int main() {
  stdio_init_all();
  puts("Start");
  listen(21, GPIO_IRQ_EDGE_RISE, example, NULL);
  while (true) tight_loop_contents();
  return 0;
}
```
