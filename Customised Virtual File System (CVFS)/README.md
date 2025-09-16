🗂️ Customized Virtual File System (CVFS)
A simple in-memory virtual file system written in C that simulates basic UNIX file operations using custom data structures like inodes, superblocks, and file tables.

✅ Features
Create, read, write, open, and delete regular files
View file stats via stat and fstat
Support for file permissions (read, write, read-write)
Maintain offsets for reading/writing
File seeking (lseek)
Manual/help command descriptions
🛠️ Compilation
To compile the CVFS project:

gcc -o cvfs main.c
Replace main.c with the filename containing your code.

▶️ Running
Run the program after compiling:

./cvfs
📜 Supported Commands
Command	Usage	Description
create	create <filename> <permission>	Create a new file with permission (1=Read, 2=Write, 3=RW)
open	open <filename> <mode>	Open a file in the given mode
write	write <filename>	Write data to the file (prompted to enter text)
read	read <filename> <bytes>	Read specified number of bytes from the file
close	close <filename>	Close an open file
closeall	closeall	Close all open files
ls	ls	List all files
stat	stat <filename>	Display file statistics using file name
fstat	fstat <fd>	Display file statistics using file descriptor
truncate	truncate <filename>	Clear file contents
rm	rm <filename>	Remove/delete a file
lseek	`lseek <START	CURRENT
man	man <command>	Show manual for a command
help	help	Display command help
clear	clear	Clear the console
exit	exit	Terminate the file system
📁 Example
CVFS : > create demo.txt 3
File is successfully created with file descriptor : 0

CVFS : > open demo.txt 3
File is successfully opened with file descriptor : 1

CVFS : > write demo.txt
Enter the data :
Hello Virtual File System!

CVFS : > read demo.txt 24
Hello Virtual File System!
⚠️ Limitations
Maximum 50 files (MAXINODE)
File size limited to 2048 bytes
In-memory only, no persistent storage
📌 Future Enhancements
Persistent file storage on disk
Directory support
User authentication
File timestamp tracking
note this file generated with help of ChatGPT

VirtualFileSystem/README.md at main · SagarRathode/VirtualFileSystem
