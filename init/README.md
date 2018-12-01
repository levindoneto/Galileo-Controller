### GPIO Setup
#### On the host
```
$ scp init/config root@<IP_GALILEO>:
```
#### On the Galileo Gen2 ($root)
```
$ groupadd -r examgroup
$ groupmems -g examgroup -a <USERNAME>
$ cp ~/<NEEDED_INIT_BASH> /etc/init.d
$ chmod +x /etc/init.d/<NEEDED_INIT_BASH>
$ update-rc.d <NEEDED_INIT_BASH> defaults
$ reboot
```
