#include <stdio.h>
#include <stdint.h>

uint32_t counter() {
	static uint32_t i = 0;
	i++;
	return i;
}

int main()
{
	uint32_t current;
	while (1) {
		current = counter();
		if (current == 100) {
			printf("Count is %d\n", current);
			return 0;
		} else {
			continue;
		}
	};
}

