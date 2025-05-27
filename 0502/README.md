# 파일과 시스템 호출 요약

## 1. 유닉스 커널과 시스템 호출
- **커널의 역할**: 파일, 프로세스, 메모리, 통신, 디바이스 관리
- **시스템 호출**: 응용 프로그램이 커널 서비스 요청하는 인터페이스

### 주요 시스템 호출
- 파일: `open()`, `close()`, `read()`, `write()`, `dup()`, `lseek()`
- 프로세스: `fork()`, `exec()`, `wait()`, `exit()`
- 기타: `signal()`, `pipe()`, `socket()` 등

---

## 2. 파일 조작

### open()
- 파일 열기, 반환값은 **파일 디스크립터(fd)**
- 옵션: `O_RDONLY`, `O_WRONLY`, `O_RDWR`, `O_CREAT`, `O_TRUNC`, `O_APPEND` 등

### creat()
- `open(path, O_WRONLY|O_CREAT|O_TRUNC, mode)`와 동일
- 새 파일을 생성하고 쓰기 전용으로 연다

### close()
- 열린 파일 닫기

---

## 3. 파일 읽기/쓰기

### read()
- `read(fd, buf, size)`  
- 파일로부터 데이터를 읽어 버퍼에 저장, 읽은 바이트 수 반환

### write()
- `write(fd, buf, size)`  
- 버퍼 내용을 파일에 씀

---

## 4. 파일 복사/크기 계산 예제
- `fsize.c`: 파일 크기 계산
- `copy.c`: 파일 복사 구현

---

## 5. 파일 디스크립터 복제

### dup(), dup2()
- 기존 fd를 복제
- `dup(fd1) → fd2` 동일 파일 공유
- `dup2(fd1, fd2)`: fd2에 fd1 복사

---

## 6. 파일 위치 이동

### lseek()
- 파일 포인터 이동
- `SEEK_SET`, `SEEK_CUR`, `SEEK_END` 기준 위치

---

## 7. 레코드 기반 저장/조회/수정 예제
- `dbcreate.c`: 학생 정보 입력하여 저장
- `dbquery.c`: 학번 기반 조회
- `dbupdate.c`: 학번 기반 점수 수정
- 구조체: `struct student { name, id, score }`

---

## 핵심 요약
- 시스템 호출은 커널 서비스를 요청하는 프로그래밍 방법
- `open`으로 파일 열고, `read/write`로 데이터 조작, `close`로 닫음
- `lseek`으로 원하는 위치 지정 가능
- 파일 디스크립터와 파일 위치 포인터는 파일 입출력의 핵심 개념


