#include<stdio.h>

char bits;

void p(int n) {
	char pilani;
	printf("In pilani, address = %u\n", &pilani);
	if( n >= 0 ) {
		printf("In pilani, address of n = %u\n", &n);
		p(n+1);
	}
	return;
}

void g() {
	char goa;
	printf("In goa, address = %u\n", &goa);
	return;
}

void h() {
	char hyderabad;
	printf("In hyderabad, address = %u\n", &hyderabad);
	return;
}

void d() {
	char dubai;
	printf("In dubai, address = %u\n", &dubai);
	return;
}

int main() {
	char c;
	int flag = 0;
	printf("Enter a character 'p', 'g', 'h' or 'd': ");
	scanf("%c", &c);
	while( flag == 0) {	
		switch(c) {
			case 'p':
				p(0);
				break;
			case 'g':
				g();
				break;
			case 'h':
				h();
				break;
			case 'd':
				d();
				break;
			default:
				flag = 1;
				break;
		}
		if( flag==1)
			break;
		printf("Enter a character 'p', 'g', 'h' or 'd': ");
		scanf("\n%c", &c);
	}
	// Each local variable is stored in a stack. They are deallocated on return
	// So each memory location outputs the same location.
	
	return 0;
}


