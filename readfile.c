#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        char error_message[] = "no filepath given\n";
        perror(error_message);
        return -1;
    }
    int file = open(argv[1], O_RDONLY);
    char file_contents[2048];
    int bytes_read = read(file, file_contents, 2048);

    write(1, file_contents, bytes_read);

    close(file);
}
