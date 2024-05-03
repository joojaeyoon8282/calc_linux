#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

int getch(){
	int c;
	struct termios oldattr, newattr;

	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);
	newattr.c_cc[VMIN] = 1;
	newattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	c = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
	return c;
}

void clear(void){
	while(getchar() != '\n');
}

void main(){
	float a,b,c;
	char ch;
	system("clear");
	printf("첫번째 숫자를 입력해주세요:");
	scanf("%f",&a);
	clear();
	printf("부호를 입력해주세요:");
	scanf("%c",&ch);
	printf("두번째 숫자를 입력해주세요:");
	scanf("%f",&b);
	switch(ch)
	{
		case'+':c=a+b;
				printf("출력=%f\n",c);
				break;
		case'-':c=a-b;
				printf("출력=%f\n",c);
				break;
		case'*':c=a*b;
				printf("출력=%f\n",c);
				break;
		case'/':c=a/b;
				printf("출력=%f\n",c);
				break;
		default:printf("유효하지 않은 값");
	}
	getch();
}
