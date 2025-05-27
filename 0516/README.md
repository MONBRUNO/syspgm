# 네트워크, 서버, 파일 유틸리티

## 1. 네트워크 및 서버

### 네트워크 개요
- **LAN**: 근거리 통신망, 이더넷 기반
- **라우터**: 네트워크 간 데이터 전달 장치
- **게이트웨이**: LAN과 인터넷 연결 장치
- **WAP**: 무선 장치와 유선 네트워크 연결

### 인터넷 구성 요소
- **IP 주소**: 장치 식별 주소 (예: 203.252.201.11)
- **TCP/IP**: 신뢰성 있는 데이터 전송 보장
- **DNS**: 도메인 → IP 변환 (예: `nslookup` 명령 사용)

### 호스트 정보 확인
- `hostname`: 시스템 이름
- `ip addr`: IP 주소 확인
- `finger`: 사용자 정보 확인

---

## 2. 서버 구축

### 아파치 웹 서버
- 설치: `apt install apache2`
- 시작/활성화: `systemctl start|enable apache2`
- 테스트 경로: `/var/www/html/index.html`, `phpinfo.php`

### FTP 서버
- 설치: `apt install vsftpd`
- 서비스: `systemctl start vsftpd`
- 방화벽 등록: `firewall-cmd --add-service=ftp`

### SSH (원격 접속)
- 설치: `apt install ssh`
- 접속: `ssh 사용자@호스트`, `ssh 호스트 명령`

---

## 3. 파일 전송 및 원격 데스크톱

### 파일 전송
- `ftp`, `sftp` 명령어로 서버에 접속하여 `get`, `put` 가능
- 명령 예시:
  - `ftp> mget *.txt`, `sftp> put test.txt`

### 원격 데스크톱
- 설치: `apt install xrdp`
- 포트 등록: `ufw allow from any to any port 3389`

---

## 4. 웹 서비스

- **WWW**: HTML 기반 정보 공간
- **HTTP**: 클라이언트-서버 통신 프로토콜
- **브라우저**: Chrome, Firefox, Safari 등

---

## 5. 파일 유틸리티 명령어

### find
- 속성 기반 파일 검색: 이름(-name), 사용자(-user), 크기(-size), 권한(-perm)
- 예: `find . -name "*.c" -exec ls -l {} \;`

### grep
- 문자열 필터링: `grep [옵션] 패턴 파일`
- 주요 옵션:
  - `-i`: 대소문자 무시, `-n`: 줄번호, `-v`: 부정, `-w`: 단어단위

### 정렬: sort
- 사용법: `sort [-옵션] 파일`
- 옵션: `-r`(역순), `-n`(숫자), `-k`(필드), `-t`(구분자)

### 비교: cmp, diff
- `cmp`: 바이트 단위 비교
- `diff`: 줄 단위 비교, `a`, `d`, `c` 편집 명령어 형식 출력

### 파일 분할/합병
- 분할: `split -l 10 파일`
- 합병: `cat`, `paste -s 파일들`

---

이 문서는 유닉스 시스템에서의 네트워크 설정 및 서버 구축, 그리고 파일 탐색, 정렬, 비교, 전송 등의 유틸리티 명령어 사용법을 요약한 것입니다.
