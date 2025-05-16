# 📂 Chapter 5: 파일 입출력 (File I/O)

유닉스 시스템에서 파일 입출력의 기본 개념과 주요 시스템 호출, 임의 접근 파일 처리 방법을 다룹니다.

---

## ⚙️ 시스템 호출 (System Calls)

- 커널에 서비스를 요청하는 프로그래밍 인터페이스
- 주요 시스템 호출 예:
  - 파일: `open()`, `close()`, `read()`, `write()`, `dup()`, `lseek()`
  - 프로세스: `fork()`, `exec()`, `exit()`, `wait()`
  - 메모리: `malloc()`, `calloc()`, `free()`
  - 통신: `pipe()`, `socket()`

---

## 📄 파일 열기와 닫기

- `open(path, oflag, mode)` : 파일을 열거나 생성하며, 성공 시 파일 디스크립터(fd) 반환
- `oflag` 옵션:
  - `O_RDONLY`, `O_WRONLY`, `O_RDWR`: 읽기, 쓰기, 읽기/쓰기 모드
  - `O_CREAT`: 파일 없으면 생성
  - `O_TRUNC`: 파일 내용 초기화
  - `O_APPEND`: 파일 끝에 추가 쓰기
- `close(fd)`: 파일 닫기

---

## 📚 데이터 읽기와 쓰기

- `read(fd, buf, nbytes)` : fd 파일에서 nbytes만큼 읽어 buf에 저장
- `write(fd, buf, nbytes)`: buf에 있는 데이터를 fd 파일에 씀
- 반환값은 실제 읽거나 쓴 바이트 수, 실패 시 -1

---

## 🔄 파일 디스크립터 복제

- `dup(oldfd)`, `dup2(oldfd, newfd)`: 기존 fd 복제, 같은 파일 공유
- 여러 fd가 같은 열린 파일에 접근 가능

---

## 🔀 임의 접근 파일 (Random Access File)

- 파일 내 원하는 위치로 이동하여 읽기/쓰기 가능
- `lseek(fd, offset, whence)`로 파일 위치 포인터 조절
  - `SEEK_SET`: 파일 시작 기준
  - `SEEK_CUR`: 현재 위치 기준
  - `SEEK_END`: 파일 끝 기준

---

## 🎓 학생 레코드 임의 접근 예제

- 학번 기준으로 학생 레코드를 파일 내 특정 위치에 저장
- `dbcreate.c`: 학생 정보 파일에 저장
- `dbquery.c`: 학번으로 학생 정보 조회
- `dbupdate.c`: 학번으로 학생 점수 수정

파일 위치는 `(학번 - START_ID) * sizeof(record)`로 계산

---

## 📌 핵심 요약

- 시스템 호출은 응용 프로그램과 커널 사이의 인터페이스
- `open()`으로 파일을 열고, `read()`/`write()`로 데이터 입출력
- 파일 디스크립터는 열린 파일을 가리키는 정수
- `lseek()`로 파일 내 임의 위치로 접근 가능
- 임의 접근을 통해 데이터베이스 형식의 파일 입출력 구현 가능

---


