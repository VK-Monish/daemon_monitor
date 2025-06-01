# daemon_monitor

# 🧿 Daemon Process Monitor

A lightweight C-based Linux daemon that runs in the background, logs its process ID every 2 seconds, and clears the log every 60 seconds (30 cycles). It's a foundational template for building real system daemons.

---

## 📌 Real-World Application

This daemon acts as a **process logger**, useful in scenarios like:

- **Embedded Linux systems** where you need low-level process monitoring.
- **IoT devices** that require simple health tracking of software modules.
- **Security**: Use this base to monitor processes or detect unexpected changes.
- **Custom daemons**: Extend this to log system metrics (CPU, RAM, etc.) or integrate with syslog.

---

## ⚙️ Features

- Logs `PID` every 2 seconds to a file.
- Auto-clears log every 30 writes (~60 seconds).
- Parent exits; child runs in background (true daemon).
- Uses Linux system calls: `fork()`, `open()`, `write()`, `sleep()`.
- Designed for expansion into full-featured system services.

---

## 🗂️ Project Structure

Daemon_monitor/
├── main.c # Daemon setup and process detachment
├── sl_daemon.c # Logging logic
├── sl_daemon.h # Header for daemon function
├── Makefile # Build system
└── README.md # Documentation (this file)


---

## 🧪 How It Works

1. Forks the process: parent exits, child continues.
2. Child closes all file descriptors and becomes a background process.
3. Every 2 seconds, logs the current PID to `/home/moni/love.c`.
4. After 30 logs, the file is truncated (cleared), and the cycle restarts.

---

## 🛠️ Build Instructions

### Prerequisites
- GCC
- Linux OS (Ubuntu/Debian/CentOS/Yocto-compatible)
- Basic command-line experience

### Build
```bash
make
./daemon_monitor
cat /home/moni/love.c
Hello...I am Monish and my roll number is: 12345
Hello...I am Monish and my roll number is: 12345
...
