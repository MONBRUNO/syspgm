# 유닉스 유틸리티

## 1. 명령어 스케줄링

### cron (주기적 실행)
- `crontab` 파일 구성: `분 시 일 월 요일 [사용자] 명령`
- 주요 명령:
  - `crontab -l`: 등록된 작업 목록
  - `crontab -e`: 수정/생성
  - `crontab -r`: 삭제

### at (한 번 실행)
- `at [시간]`: 지정 시간에 명령 실행
- `atq`: 등록된 at 작업 조회
- `at -r [작업번호]`: 작업 삭제

---

## 2. 디스크 및 아카이브

### 디스크 사용량 확인
- `df`: 파일 시스템별 사용량
- `du`: 디렉토리/파일별 사용량 (`-s`: 요약)

### tar 아카이브
- `tar -cvf 파일.tar 파일들`: 묶기
- `tar -xvf 파일.tar`: 풀기
- `tar -tvf 파일.tar`: 내용 보기

---

## 3. 파일 압축

### gzip
- `gzip 파일`: 압축 → `.gz` 생성
- `gzip -d 파일.gz` or `gunzip 파일.gz`: 압축 해제

### compress
- `compress 파일` → `.Z` 생성
- `uncompress 파일.Z`: 압축 해제

### 압축 예
```bash
tar -cvf src.tar *
gzip src.tar
gzip -d src.tar.gz
tar -xvf src.tar
```

---

## 4. AWK 기본

### 개요
- 필드 기반 텍스트 처리 스크립트 언어
- 기본 구조: `[조건] {액션}`

### 사용 예
- `$ awk '{ print $1, $NF }' 파일`
- `$ awk '/pattern/ { print $0 }' 파일`
- `$ awk 'END { print NR }' 파일`

### 조건
- `BEGIN`, `END`, `/패턴/`, `NR`, `NF` 등

### 액션 및 제어문
- `if`, `for`, `while`, `print`, `printf`, `next`, `exit` 등 사용 가능

---

## 5. AWK 프로그램 예

### 간단한 예
```awk
BEGIN { print "파일 시작" }
{ print $1, $NF }
END { print "파일 끝" }
```

### 줄 수, 단어 수 계산
```awk
BEGIN { word = 0 }
{ word += NF }
END { print "단어 수:", word }
```

### 단어 빈도수 분석
```awk
BEGIN { FS="[^a-zA-Z]+" }
{ for(i=1;i<=NF;i++) words[tolower($i)]++ }
END { for(i in words) print i, words[i] }
```

---

## 핵심 요약

- `cron`, `at`: 명령 스케줄링
- `tar`, `gzip`, `compress`: 파일 묶기 및 압축
- `awk`: 텍스트 기반 필드 처리 및 스크립팅 도구


