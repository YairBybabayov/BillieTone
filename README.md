
# Billie Jean Bassline Beep Driver

## Overview

This project demonstrates how to recreate the iconic bassline from **"Billie Jean"** by Michael Jackson using the `Beep` device driver in Windows. The program interacts with the Windows NT kernel through the `DeviceIoControl` function, setting frequencies and durations that correspond to the notes of the bassline.

The driver uses specific frequencies and durations to replicate the notes and rhythm of the bassline, based on common bass guitar tuning (EADG).

## Prerequisites

- Windows OS
- A C compiler (like `cl.exe` or `gcc` for Windows)
- Basic knowledge of Windows kernel programming

## Notes Frequencies

Here are the corresponding notes and their frequencies used in the song's bassline:

- **F# (D string, 4th fret)**: 185 Hz
- **C# (A string, 4th fret)**: 138 Hz
- **E (D string, 2nd fret)**: 165 Hz
- **B (A string, 2nd fret)**: 123 Hz

## How It Works

- The program opens a handle to the `Beep` device using the `NtOpenFile` function.
- It then uses `DeviceIoControl` to send the **frequency** and **duration** parameters to the beep device.
- These parameters are controlled by the `BEEP_SET_PARAMETERS` structure, which holds the `Frequency` (in Hz) and `Duration` (in milliseconds).
- The code follows the sequence of the Billie Jean bassline.

## Code Breakdown

The program plays the following sequence of notes:

1. **F# (D string, 4th fret)** – 185 Hz, 400 ms
2. **C# (A string, 4th fret)** – 138 Hz, 400 ms
3. **E (D string, 2nd fret)** – 165 Hz, 400 ms
4. **F# (D string, 4th fret)** – 185 Hz, 400 ms
5. **E (D string, 2nd fret)** – 165 Hz, 400 ms
6. **C# (A string, 4th fret)** – 138 Hz, 400 ms
7. **B (A string, 2nd fret)** – 123 Hz, 400 ms
8. **C# (A string, 4th fret)** – 138 Hz, 400 ms

## How to Compile

To compile the code, you can use any C compiler available on your system. For example, using `cl.exe` (from Visual Studio):

```bash
cl.exe billie_tone.c
```

Or using `gcc` on a Windows environment:

```bash
gcc billie_tone.c -o billie_tone.exe
```

## How to Run

Once compiled, you can run the executable on a Windows machine:

```bash
./billie_tone.exe
```

The program will play the bassline using the system’s speaker through the Beep device.

## Troubleshooting

- Ensure that you have the proper permissions to access kernel-level device drivers.
- The program may require Administrator privileges on some systems to access the Beep device.
- Verify that the `ntdll` library is correctly linked during compilation.

## License

This project is open-source and can be modified as per your needs.
