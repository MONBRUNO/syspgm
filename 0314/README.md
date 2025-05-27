# 리눅스 시스템 명령어 정리

## 1. 주요 시스템 디렉토리

| 디렉토리 | 설명 |
|----------|------|
| `/`      | 루트 디렉토리 |
| `/home`  | 사용자 홈 디렉토리 |
| `/bin`   | 기본 명령어 실행파일 |
| `/usr`   | 소프트웨어 설치용 디렉토리 |
| `/dev`   | 장치 파일 위치 |
| `/etc`   | 설정 파일 위치 |
| `/tmp`   | 임시 파일 디렉토리 |
| `/var`   | 로그, 메일 등 변화하는 파일 저장 |
| `/proc`  | 시스템 정보 제공 (가상 디렉토리) |

## 2. 파일/디렉토리 관리 명령어

- `ls`, `cd`, `pwd`, `mkdir`, `rmdir`, `cp`, `mv`, `rm`, `touch`, `cat`, `more`, `less`
- `find` : 파일 검색
- `chmod`, `chown`, `chgrp` : 권한 및 소유자 설정

## 3. 시스템 명령어

- `shutdown`, `reboot`, `top`, `ps`, `kill`, `cron`
- `df`, `du`, `mount`, `umount`, `free`, `uptime`
- `grep`, `egrep` : 문자열 검색
- `alias`, `history` : 명령어 설정 및 기록 확인

## 4. 사용자 및 그룹 관리

- 사용자 추가: `adduser`, `useradd`, `passwd`
- 사용자 삭제: `userdel -r`
- 수정: `usermod`, `groupadd`, `groupdel`
- 쉘 설정: `.bash_profile`, `.bashrc`

## 5. 파일 압축/해제

- `tar`, `gzip`, `gunzip`, `bzip2`, `bunzip2`
```bash
tar cvfz archive.tar.gz dir/
tar xvfz archive.tar.gz
```

## 6. 텍스트 편집기 `vi`

- `i`, `a`, `x`, `dd`, `yy`, `p`, `:wq`, `:q!`
- 검색: `/`, `?`
- 문자열 치환: `:%s/old/new/g`

## 7. 네트워크 명령어

- `ifconfig`, `ping`, `traceroute`, `route`
- 네트워크 설정: `/etc/sysconfig/network`, `/etc/sysconfig/network-scripts/`

## 8. 패키지 관리 (RPM 기반)

- 설치: `rpm -ivh package.rpm`
- 제거: `rpm -e package`
- 정보 확인: `rpm -qi`, `-ql`, `-qf`

## 9. 로그 관리

- 주요 로그 파일: `/var/log/messages`, `/var/log/secure`, `/var/log/cron`
- 데몬: `syslogd`, `klogd`
- 설정 파일: `/etc/syslog.conf`, `/etc/logrotate.conf`

## 10. Quota 설정

- `/etc/fstab`에 `usrquota` 추가
- `quotacheck`, `quotaon`, `repquota`, `edquota`

## 참고

- 리눅스에서 모든 것은 파일로 취급됨 (장치, 네트워크 포함)
- 환경 변수: `PATH`, `HOME`, `SHELL`
- 권한 숫자 표기법: `r=4`, `w=2`, `x=1` (예: `chmod 755`)

