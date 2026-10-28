//8. write the argument 2 to the file
//9. Save and close the file
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char* argv[]){

    int app_return = -1;

    openlog("writer", LOG_PERROR, LOG_USER);
    syslog(LOG_INFO, "Application started successfully");

    if (argc < 3){
        syslog(LOG_WARNING, "Arguments not sufficent");
        app_return = -1;
    }

    else { 
        char* filepath = argv[1];
        char* filecontentstring = argv[2];
    
        int fd = open(filepath, O_RDWR | O_CREAT | O_TRUNC, 0664);

        if (fd == -1){
            perror("Open failed");
            syslog(LOG_WARNING, 
                "Invalid file descriptor obtained for file");
        }

        syslog(LOG_DEBUG, "Writing %s to %s", 
            filecontentstring, filepath);

        app_return = 0;
    }     

    syslog(LOG_INFO, "Exiting");

    return app_return;

}
