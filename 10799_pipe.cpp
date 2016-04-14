#include<iostream>
#include<stack>

using namespace std;

//using stack

char p[100002];
int cnt = 0;
int c = 0; //현재 겹쳐진 파이프 수
stack<int> s;

int main(void){
	char nextp = NULL;
	scanf("%s", p);

	s.push(p[0]);
	c = 1;

	for(int i = 1; p[i] != '\0' ; i++){
		nextp = p[i];
		if(nextp == '('){
			c++;
			s.push(nextp);
		}else if((s.top() == '(') && (nextp == ')')){
			c--;
			cnt += c;
			s.push(nextp);
		}else if(( s.top() == ')') && (nextp == ')')){
			cnt++;
			c--;
			s.push(nextp);
		}
	}

	printf("%d\n", cnt);

	return 0;
}
