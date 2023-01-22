#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int print_file(int fd) {
    char file_contents[2048];
    int bytes_read = read(fd, file_contents, 2048);

    for (int i = 0; i < bytes_read; i++)
    {
        file_contents[i] = toupper(file_contents[i]);
    }
    

    write(1, file_contents, bytes_read);
    return bytes_read;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        int bytes_read;
        do
        {
            bytes_read = print_file(0);
        } while (bytes_read != 0);
    }
    else {
        for (int i = 1; i < argc; i++)
        {
            int file = open(argv[i], O_RDONLY);

            int bytes_read = print_file(file);

            while (bytes_read > 0)
            {
                bytes_read = print_file(file);
            }
            
            close(file);
        }
    }
}
