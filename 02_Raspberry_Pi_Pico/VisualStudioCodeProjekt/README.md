# Build on Consol
    $ mkdir build
    $ cd build
    $ export PICO_SDK_PATH=../../pico-sdk
    $ cmake ..
    $ make
    
# Mount the mass storage device manually
    $ dmesg | tail
        [ 371.973555] sd 0:0:0:0: [sda] Attached SCSI removable disk
    $ sudo mkdir -p /mnt/pico
    $ sudo mount /dev/sda1 /mnt/pico
## Check
    $ ls /mnt/pico/
        INDEX.HTM INFO_UF2.TXT
## Copy
    $ sudo cp PROJECTNAME.uf2 /mnt/pico
    $ sudo sync
## Dismount
    $ sudo umount /mnt/pico