#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//#define INSERT_OP 10이렇게 정의하면 안되나? 왜 16진수로 정의?
#define INSERT_OP      0x01//0001(2) == 1(10)
#define DELETE_OP      0x02//0010(2) == 2(10)
#define SUBSTITUTE_OP  0x04//0100(2) == 4(10)
#define MATCH_OP       0x08//1000(2) == 8(10)
#define TRANSPOSE_OP   0x10//10000(2) == 16(10)

#define INSERT_COST	1
#define DELETE_COST	1
#define SUBSTITUTE_COST	1
#define TRANSPOSE_COST	1

static int __GetMin3( int a, int b, int c);
static int __GetMin4( int a, int b, int c, int d);

// 재귀적으로 연산자 행렬을 순회하며, 두 문자열이 최소편집거리를 갖는 모든 가능한 정렬(alignment) 결과를 출력한다.
// op_matrix : 이전 상태의 연산자 정보가 저장된 행렬 (1차원 배열임에 주의!)
// col_size : op_matrix의 열의 크기
// str1 : 문자열 1
// str2 : 문자열 2
// n : 문자열 1의 길이
// m : 문자열 2의 길이
// level : 재귀호출의 레벨 (0, 1, 2, ...)
// align_str : 정렬된 문자쌍들의 정보가 저장된 문자열 배열 예) "a - a", "a - b", "* - b", "ab - ba"

// 문자열의 길이가 최대 8 ex) ab - be\0 8자리가 필요
// op[i][j] => op_matrix[i * col_size + j]
static void backtrace_main( int *op_matrix, int col_size, char *str1, char *str2, int n, int m, int level, char align_str[][8]){

	//base case


	backtrace_main();

	printf("\n[%d] ==============================\n", );
	print_alignment(align_str, level);
}

// 강의 자료의 형식대로 op_matrix를 출력 (좌하단(1,1) -> 우상단(n, m))
// 각 연산자를 다음과 같은 기호로 표시한다. 삽입:I, 삭제:D, 교체:S, 일치:M, 전위:T
void print_matrix( int *op_matrix, int col_size, char *str1, char *str2, int n, int m){
	for(int i = n-1; i >= 0 ; i--){
		printf("%c\t", str1[i]);

		for(int j = 1; j < m + 1; j++){
			int tmp = op_matrix[i * col_size + j];
			// if(tmp == 1) printf("I\t");
			// else if(tmp == 2) printf("D\t");
			// else if(tmp == 3) printf("ID\t");
			// else if(tmp == 4) printf("S\t");
			// else if(tmp == 5) printf("\t");
			// else if(tmp == 6) printf("\t");
			// else if(tmp == 7) printf("\t");
 			// else if(tmp == 8) printf("M\t");
			// else if(tmp == 9) printf("\t");
			// else if(tmp == 10) printf("\t");
			// else if(tmp == 11) printf("\t");
			// else if(tmp == 12) printf("\t");
			// else if(tmp == 13) printf("\t");
			// else if(tmp == 14) printf("\t");
			// else if(tmp == 15) printf("\t");
			// else if(tmp == 16) printf("T\t");

			if (op_matrix[i * col_size + j] & 4) fprintf(stdout, "S");
			if (op_matrix[i * col_size + j] & 8) fprintf(stdout, "M");
			if (op_matrix[i * col_size + j] & 1) fprintf(stdout, "I");
			if (op_matrix[i * col_size + j] & 2) fprintf(stdout, "D");
			if (op_matrix[i * col_size + j] & 16) fprintf(stdout, "T");
			printf("\t");
		}
		printf("\n");
	}
	printf(" \t");
	for(int j = 0; j < m; j++){
		printf("%c\t", str2[j]);
	}
	printf("\n");
}

// 두 문자열 str1과 str2의 최소편집거리를 계산한다.
// return value : 최소편집거리
// 이 함수 내부에서 print_matrix 함수와 backtrace 함수를 호출함
int min_editdistance( char *str1, char *str2){
	int n = strlen(str1);
	int m = strlen(str2);
	int col_size = n + 1;

	int i, j;
	int d[n+1][m+1];
	int op_matrix[(n+1)*(m+1)];
	//d는 각 셀에 저장된 값이 최소편집거리(정수)이고,
	//op_matrix는 이전 셀에서 자기 셀로 전이할 때 사용된 연산자(들)을 정수로 표현한 값이 저장

	//d[][] 왼쪽, 아래 값 초기화
	d[0][0] = 0;
	for(i = 1; i < n + 1; i++) d[i][0] = d[i-1][0] + INSERT_COST;
	for(j = 1; j < m + 1; j++) d[0][j] = d[0][j-1] + DELETE_COST;

	//d[][] 완성
	for(i = 1; i < n + 1; i++){
		for(j = 1; j < m + 1; j++){
			int i;
			if(str1[i] == str2[j])
				d[i][j] = __GetMin3(d[i][j-1] + INSERT_COST, d[i-1][j] + DELETE_COST, d[i-1][j-1]);
				t = d[i][j];
				if(t == d[i][j - 1] + INSERT_COST) op_matrix[i * col_size + j] |= INSERT_OP;
				if(t == d[i-1][j] + DELETE_COST) op_matrix[i * col_size + j] |= DELETE_OP;
				if(t == d[i-1][j-1]) op_matrix[i * col_size + j] |= MATCH_OP;

			else if(str1[i] == str2[j-1] && str1[i-1] == str2[j])
				d[i][j] = __GetMin4(d[i][j-1] + INSERT_COST, d[i-1][j] + DELETE_COST, d[i-1][j-1] + SUBSTITUTE_COST, d[i-2][j-2] + TRANSPOSE_COST);
				t = d[i][j];
				if(t == d[i][j - 1] + INSERT_COST) op_matrix[i * col_size + j] |= INSERT_OP;
				if(t == d[i-1][j] + DELETE_COST) op_matrix[i * col_size + j] |= DELETE_OP;
				if(t == d[i-1][j-1] + TRANSPOSE_COST) op_matrix[i * col_size + j] |= TRANSPOSE_OP;
			
			else
				d[i][j] = __GetMin3(d[i][j-1] + INSERT_COST, d[i-1][j] + DELETE_COST, d[i-1][j-1] + SUBSTITUTE_COST);
				t = d[i][j];
				if(t == d[i][j - 1] + INSERT_COST) op_matrix[i * col_size + j] |= INSERT_OP;
				if(t == d[i-1][j] + DELETE_COST) op_matrix[i * col_size + j] |= DELETE_OP;
				if(t == d[i-1][j-1] + TRANSPOSE_COST) op_matrix[i * col_size + j] |= SUBSTITUTE_OP;				
		}
	}

	print_matrix(op_matrix, col_size, str1, str2, n, m);


	backtrace(op_matrix, col_size, str1, str2, n, m);


}

////////////////////////////////////////////////////////////////////////////////
// 세 정수 중에서 가장 작은 값을 리턴한다.
static int __GetMin3( int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if(c < min)
		min = c;
	return min;
}

////////////////////////////////////////////////////////////////////////////////
// 네 정수 중에서 가장 작은 값을 리턴한다.
static int __GetMin4( int a, int b, int c, int d)
{
	int min = __GetMin3( a, b, c);
	return (min > d) ? d : min;
}

////////////////////////////////////////////////////////////////////////////////
// 정렬된 문자쌍들을 출력
void print_alignment( char align_str[][8], int level)
{
	int i;
	
	for (i = level; i >= 0; i--)
	{
		printf( "%s\n", align_str[i]);
	}
}

////////////////////////////////////////////////////////////////////////////////
// backtrace_main을 호출하는 wrapper 함수
// str1 : 문자열 1
// str2 : 문자열 2
// n : 문자열 1의 길이
// m : 문자열 2의 길이
void backtrace( int *op_matrix, int col_size, char *str1, char *str2, int n, int m)
{
	char align_str[n+m][8]; // n+m strings
	
	backtrace_main( op_matrix, col_size, str1, str2, n, m, 0, align_str);
	
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char str1[30];
	char str2[30];
	
	int distance;
	
	fprintf( stderr, "INSERT_COST = %d\n", INSERT_COST);
	fprintf( stderr, "DELETE_COST = %d\n", DELETE_COST);
	fprintf( stderr, "SUBSTITUTE_COST = %d\n", SUBSTITUTE_COST);
	fprintf( stderr, "TRANSPOSE_COST = %d\n", TRANSPOSE_COST);
	
	while( fscanf( stdin, "%s\t%s", str1, str2) != EOF)
	{
		printf( "\n==============================\n");
		printf( "%s vs. %s\n", str1, str2);
		printf( "==============================\n");
		
		distance = min_editdistance( str1, str2);
		
		printf( "\nMinEdit(%s, %s) = %d\n", str1, str2, distance);
	}
	return 0;
}

