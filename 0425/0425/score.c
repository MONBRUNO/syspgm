#include <stdio.h>
#include <string.h>

// 학생 정보를 저장할 구조체 정의
typedef struct {
    char name[50];    // 이름
    int korean;       // 국어 점수
    int english;      // 영어 점수
    int math;         // 수학 점수
    int total;        // 총점
    float average;    // 평균
} Student;

// 총점과 평균을 계산하는 함수
void calculateScores(Student *student) {
    student->total = student->korean + student->english + student->math;
    student->average = (float)student->total / 3.0;
}

int main() {
    Student students[5]; // 5명의 학생 정보를 저장할 배열
    int i;

    // 5명의 학생 정보 입력받기
    for (i = 0; i < 5; i++) {
        printf("%d번째 학생 정보 입력\n", i + 1);
        
        printf("이름: ");
        scanf("%s", students[i].name);
        
        printf("국어 점수: ");
        scanf("%d", &students[i].korean);
        
        printf("영어 점수: ");
        scanf("%d", &students[i].english);
        
        printf("수학 점수: ");
        scanf("%d", &students[i].math);
        
        // 총점과 평균 계산
        calculateScores(&students[i]);
        
        printf("\n");
    }
    
    // 결과 출력
    printf("\n===== 학생 성적 결과 =====\n");
    printf("이름\t총점\t평균\n");
    printf("------------------------\n");
    
    for (i = 0; i < 5; i++) {
        printf("%s\t%d\t%.2f\n", 
               students[i].name, 
               students[i].total, 
               students[i].average);
    }
    
    return 0;
}
