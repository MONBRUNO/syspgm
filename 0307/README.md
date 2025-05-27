# Windows에서 WSL2를 활용한 Linux 사용 가이드

## 개요

이 문서는 Windows 환경에서 WSL2(Windows Subsystem for Linux 2)를 활용하여 Linux 환경을 구축하고 사용하는 방법을 안내합니다. WSL2를 사용하면 가상 머신이나 이중 부팅 없이도 Windows에서 직접 Linux를 실행할 수 있습니다.

## WSL2란?

WSL2는 Windows에서 Linux 커널을 직접 실행할 수 있도록 지원하는 기능입니다. WSL1과 비교하여 다음과 같은 장점이 있습니다:

- **실제 Linux 커널**을 사용하여 시스템 호출 호환성이 향상됨
- **파일 시스템 성능**이 개선되어 빠른 속도를 제공
- **Docker 및 CUDA**와 같은 도구 지원이 가능

## 설치 전 준비 사항

- **Windows 버전 확인**: WSL2는 Windows 10 버전 2004 이상에서 지원됩니다. `winver` 명령어를 통해 Windows 버전을 확인하세요.
- **가상화 기능 활성화**: BIOS에서 가상화(Virtualization) 기능이 활성화되어 있어야 합니다.
- **Windows 기능 활성화**:
  - 'Linux용 Windows 하위 시스템'
  - '가상 머신 플랫폼'

## WSL2 설치 및 설정

1. **PowerShell을 관리자 권한으로 실행**하고 다음 명령어를 입력하여 WSL을 설치합니다:
   ```powershell
   wsl --install
   ```

2. **Linux 커널 업데이트**: 최신 Linux 커널을 설치하여 WSL2를 지원합니다. [Microsoft 공식 문서](https://learn.microsoft.com/ko-kr/windows/wsl/install-manual#step-4---download-the-linux-kernel-update-package)를 참고하여 업데이트하세요.

3. **WSL2를 기본 버전으로 설정**:
   ```powershell
   wsl --set-default-version 2
   ```

4. **Windows Terminal 설치**: [Microsoft Store](https://apps.microsoft.com/detail/windows-terminal/9N0DX20HK701?hl=ko-kr&gl=KR)에서 설치합니다.

5. **Linux 배포판 설치**: 예: [Ubuntu 22.04 LTS](https://apps.microsoft.com/detail/ubuntu-2204-lts/9PN20MSR04DW?hl=ko-kr&gl=KR)

6. **사용자 계정 설정**: 초기 실행 시 사용자 이름과 비밀번호를 설정합니다.

## 문제 해결

- **Ubuntu 실행 시 에러 발생**: 'Linux용 Windows 하위 시스템' 기능이 활성화되어 있는지 확인하고 재부팅하세요.

## 참고 자료

- [WSL 공식 문서](https://learn.microsoft.com/ko-kr/windows/wsl/)
- [블로그 원문](https://rimiyeyo.tistory.com/entry/WSL2%EA%B0%9C%EB%85%90%EA%B3%BC-Windows%EC%97%90%EC%84%9C-WSL2%EB%A5%BC-%ED%99%9C%EC%9A%A9%ED%95%B4%EC%84%9C-Linux%EC%82%AC%EC%9A%A9%ED%95%B4%EB%B3%B4%EA%B8%B0)

