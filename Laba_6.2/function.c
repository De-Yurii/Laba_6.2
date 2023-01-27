#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
#include <stdio.h>
#include <stdarg.h>

int find_most_frequenc(char element, ...) {
	va_list p;
	char letters[26], letter;
	int frequence[26] = { 0 };
	for (int i = 0; i < 26; i++) {
		letters[i] = i + 65;
	}
	va_start(p, element);
	letter = toupper(element);
	for (int j = 0; j < 26; j++) {
		if (letter == letters[j]) {
			frequence[j]++;
			break;
		}
	}

	for (int i = 1; *p != '\0'; i++) {
		char letter = toupper(*p);
		for (int j = 0; j < 26; j++) {
			if (letter == letters[j]) {
				frequence[j]++;
				break;
			}
		}
		va_arg(p, char);
	}
	int max = 0, max_index;
	for (int i = 0; i < 26; i++) {
		if (frequence[i] > max) {
			max = frequence[i];
			max_index = i;
		}
	}
	printf("%c", letters[max_index]);
	return 0;
}