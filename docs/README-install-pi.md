# README-install-pi.md

Steps:
1) Install base system (Raspbian OS 64 Bit)
2) Change user pi to named user 
3) Install Node.js via nvm
4) Install additional software
    ```sh
    root@rpi:~ # apt update
    root@rpi:~ # apt install screen git picocom avrdude gcc-avr avr-libc
    ```
5) Make sure that user can access Fischl USB-Blaster  
   See [Device Permissions for USB-Blaster](#device-permissions-for-usb-blaster)

5) Clone project:    
    ```sh
    user@rpi:~ $ git clone https://git.htl-mechatronik.at/sx/electro-vehicle-wallbox-station.git
    ```

5) Build/start software

------------------------------------------------

## Details

### Build and Start µC Software

Connect USB-Programmer with Programming connector and power on the board.

```sh
user@rpi:~ $ cd ~/electro-vehicle-wallbox-station
user@rpi: $ cd evws1/software/atmega324p_u1
user@rpi: $ make u1
```

### Device Permissions for USB-Blaster

See: [https://andreasrohner.at/posts/Electronics/How-to-fix-device-permissions-for-the-USBasp-programmer/](https://andreasrohner.at/posts/Electronics/How-to-fix-device-permissions-for-the-USBasp-programmer/)

Create as user root the file `/etc/udev/rules.d/99-usbasp.rules`:
```
SUBSYSTEM=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05dc", GROUP="dialout"
```

Restart udev:
```sh
root@rpi:~ # udevadm control --reload-rules
# udevadm trigger
```

Check file permissions:
```sh
root@rpi:~ # lsusb
...
Bus 001 Device 003: ID 16c0:05dc Van Ooijen Technische Informatica shared ID for use with libusb
...

root@rpi:~ # ls -l /dev/bus/usb/001/003
crw-rw-r-- 1 root dialout 189, 2 Apr  8 20:16 /dev/bus/usb/001/003
```

Ensure that user is member of group `dialout`



