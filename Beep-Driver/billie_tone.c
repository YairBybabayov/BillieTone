/* billie_tone.c */
#include<Windows.h>
#include<ntddbeep.h>
#include<stdio.h>
#include<winternl.h>

#pragma comment(lib, "ntdll")

int main() {
	HANDLE hDevice;
	UNICODE_STRING devName;
	RtlInitUnicodeString(&devName, DD_BEEP_DEVICE_NAME_U);
	OBJECT_ATTRIBUTES devAttr;
	InitializeObjectAttributes(&devAttr, &devName, 0, NULL, NULL);
	IO_STATUS_BLOCK ioStatus;
	NTSTATUS status = NtOpenFile(&hDevice, GENERIC_WRITE, &devAttr, &ioStatus, 0, 0);
	if (status == 0) {
		
		//printf("Handle: 0x%p\n", hDevice);
		
		BEEP_SET_PARAMETERS note;
		DWORD ret;

		//F# (D string, 4th fret)
		note.Frequency = 185;
		note.Duration = 400;
		DeviceIoControl(hDevice, IOCTL_BEEP_SET, &note, sizeof(note), NULL, 0, &ret, NULL);

		//C# (A string, 4th fret)
		note.Frequency = 138;
		note.Duration = 400;
		DeviceIoControl(hDevice, IOCTL_BEEP_SET, &note, sizeof(note), NULL, 0, &ret, NULL);

		// E note - quarter note (D string, 2nd fret)
		note.Frequency = 165;
		note.Duration = 400;
		DeviceIoControl(hDevice, IOCTL_BEEP_SET, &note, sizeof(note), NULL, 0, &ret, NULL);

		//F# (D string, 4th fret)
		note.Frequency = 185;
		note.Duration = 400;
		DeviceIoControl(hDevice, IOCTL_BEEP_SET, &note, sizeof(note), NULL, 0, &ret, NULL);

		// E note - quarter note (D string, 2nd fret)
		note.Frequency = 165;
		note.Duration = 400;
		DeviceIoControl(hDevice, IOCTL_BEEP_SET, &note, sizeof(note), NULL, 0, &ret, NULL);

		//C# (A string, 4th fret)
		note.Frequency = 138;
		note.Duration = 400;
		DeviceIoControl(hDevice, IOCTL_BEEP_SET, &note, sizeof(note), NULL, 0, &ret, NULL);

		//B(A string, 2nd fret)
		note.Frequency = 123;
		note.Duration = 400;
		DeviceIoControl(hDevice, IOCTL_BEEP_SET, &note, sizeof(note), NULL, 0, &ret, NULL);
		
		//C# (A string, 4th fret)
		note.Frequency = 138;
		note.Duration = 400;
		DeviceIoControl(hDevice, IOCTL_BEEP_SET, &note, sizeof(note), NULL, 0, &ret, NULL);


		CloseHandle(hDevice);
	}
	return 0;
}


