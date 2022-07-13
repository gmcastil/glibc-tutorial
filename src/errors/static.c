#include <stdio.h>
#include <stdint.h>

uint32_t counter(uint32_t);

uint32_t counter(uint32_t start) {

	static uint32_t call_count = 0;
	static uint32_t i;

	if ( call_count == 0 ) {
		i = start;
	} else {
		i++;
	}

	call_count++;
	return i;
}

int main()
{
	uint32_t current;
	while (1) {
		current = counter(3);
		printf("Count is %d\n", current);
		if ( current == 10 ) {
			return 0;
		} else {
			continue;
		}
	};
}
