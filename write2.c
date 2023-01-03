#include <unistd.h>

ssize_t write(int fd, void *buffer, size_t count); 

ssize_t ret;

/*Ghi một nội dung độ dài len có địa chỉ bắt đầu từ vùng nhớ buf vào file fd*/

while (len != 0 && (ret = write (fd, buf, len)) != 0)
{
   if (ret == −1)
   {
       if (errno == EINTR)
           continue;

       perror ("write" );
       break;
   }
   len -= ret;
   buf += ret;
}
