//
//  main.c
//  IOKitTest1
//
//  Created by Tim Shull on 2/20/17.
//  Copyright © 2017 Tim Shull. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <IOKit/IOTypes.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/IOBSD.h>
#include <sys/param.h>
#include <paths.h>

int main(int argc, const char*argv[])
{
    io_object_t device; //This is the object IOIteratorNext returns
    char deviceFilePath[MAXPATHLEN]; //MAXPATHLEN is defined in sys/param.h
    size_t devPathLength;
    CFTypeRef deviceNameAsCFString;
    Boolean gotString = false;
    deviceNameAsCFString = IORegistryEntryCreateCFProperty(device, CFSTR(kIOBSDNameKey), kCFAllocatorDefault, 0);

    if (deviceNameAsCFString) {
        strcpy(deviceFilePath, '\0');
        devPathLength = strlen(_PATH_DEV); //_PATH_DEV is defined in paths.h
        strcpy(deviceFilePath, _PATH_DEV);

        //Add "r" before the BSD node name from the I/O Registry
        //to specify the raw disk node. The raw disk node receives
        //I/O requests directly and does not go through the
        //buffer cache.
        strcat(deviceFilePath, "r");
        gotString = CFStringGetCString(deviceNameAsCFString, deviceFilePath + strlen(deviceFilePath), MAXPATHLEN - strlen(deviceFilePath), kCFStringEncodingASCII);

        if (gotString) { printf("Device file path: %s\n", deviceFilePath); }
        //deviceFilePath will look something like /dev/rdisk1
    }
    return 0;
}
